#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>

#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/synchronizer.h>

#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2/exceptions.h>
#include <tf2/time.h>

#include <array>
#include <chrono>
#include <cmath>
#include <limits>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using LaserScan = sensor_msgs::msg::LaserScan;

class LaserScanMergerCpp : public rclcpp::Node
{
public:
  LaserScanMergerCpp()
  : Node("laser_scan_merger_cpp")
  {
    this->declare_parameter<std::string>("topic_1", "/right_scan");
    this->declare_parameter<std::string>("topic_2", "/left_scan");
    this->declare_parameter<std::string>("merged_topic", "/merged_scan");
    this->declare_parameter<std::string>("target_frame", "base_link");

    const std::string topic_1 =
      this->get_parameter("topic_1").as_string();

    const std::string topic_2 =
      this->get_parameter("topic_2").as_string();

    const std::string merged_topic =
      this->get_parameter("merged_topic").as_string();

    target_frame_ =
      this->get_parameter("target_frame").as_string();

    // urg_node など一般的なLiDARドライバは
    // Best Effort で配信することが多いため、QoSを合わせる。
    rclcpp::QoS qos(10);
    

    sub1_.subscribe(
      this,
      topic_1,
      qos.get_rmw_qos_profile());

    sub2_.subscribe(
      this,
      topic_2,
      qos.get_rmw_qos_profile());

    // ApproximateTime Synchronizer
    sync_ = std::make_shared<Sync>(
      SyncPolicy(10),
      sub1_,
      sub2_);

    sync_->setMaxIntervalDuration(
      rclcpp::Duration::from_seconds(0.05));

    sync_->registerCallback(
      std::bind(
        &LaserScanMergerCpp::callback,
        this,
        std::placeholders::_1,
        std::placeholders::_2));

    pub_ = this->create_publisher<LaserScan>(
      merged_topic,
      qos);

    // ------------------------------------------------------------
    // right_scan の生の到着時刻を記録するためのsubscription
    // ------------------------------------------------------------
    raw_sub1_ = this->create_subscription<LaserScan>(
      topic_1,
      qos,
      std::bind(
        &LaserScanMergerCpp::rawScan1Callback,
        this,
        std::placeholders::_1));

    tf_buffer_ =
      std::make_shared<tf2_ros::Buffer>(
        this->get_clock());

    tf_listener_ =
      std::make_shared<tf2_ros::TransformListener>(
        *tf_buffer_);
  }

private:
  using SyncPolicy =
    message_filters::sync_policies::ApproximateTime<
      LaserScan,
      LaserScan>;

  using Sync =
    message_filters::Synchronizer<SyncPolicy>;

  using Mat4 =
    std::array<float, 16>;

  // ------------------------------------------------------------
  // TransformStamped -> 4x4行列
  // ------------------------------------------------------------
  Mat4 tfToMatrix(
    const geometry_msgs::msg::TransformStamped & tf)
  {
    const auto & q = tf.transform.rotation;
    const auto & t = tf.transform.translation;

    const float x = q.x;
    const float y = q.y;
    const float z = q.z;
    const float w = q.w;

    Mat4 T{};

    T[0] =
      1.0f - 2.0f * (y * y + z * z);

    T[1] =
      2.0f * (x * y - z * w);

    T[2] =
      2.0f * (x * z + y * w);

    T[3] =
      static_cast<float>(t.x);

    T[4] =
      2.0f * (x * y + z * w);

    T[5] =
      1.0f - 2.0f * (x * x + z * z);

    T[6] =
      2.0f * (y * z - x * w);

    T[7] =
      static_cast<float>(t.y);

    T[8] =
      2.0f * (x * z - y * w);

    T[9] =
      2.0f * (y * z + x * w);

    T[10] =
      1.0f - 2.0f * (x * x + y * y);

    T[11] =
      static_cast<float>(t.z);

    T[12] = 0.0f;
    T[13] = 0.0f;
    T[14] = 0.0f;
    T[15] = 1.0f;

    return T;
  }

  // ------------------------------------------------------------
  // LaserScan -> XY点群
  // ------------------------------------------------------------
  void scanToXY(
    const LaserScan & scan,
    std::vector<float> & xs,
    std::vector<float> & ys)
  {
    xs.clear();
    ys.clear();

    xs.reserve(scan.ranges.size());
    ys.reserve(scan.ranges.size());

    for (size_t i = 0; i < scan.ranges.size(); ++i)
    {
      const float r = scan.ranges[i];

      if (!std::isfinite(r))
      {
        continue;
      }

      const float angle =
        scan.angle_min +
        static_cast<float>(i) *
        scan.angle_increment;

      xs.push_back(r * std::cos(angle));
      ys.push_back(r * std::sin(angle));
    }
  }

  // ------------------------------------------------------------
  // XY点群にTFを適用
  // ------------------------------------------------------------
  void transformXY(
    std::vector<float> & xs,
    std::vector<float> & ys,
    const Mat4 & T)
  {
    for (size_t i = 0; i < xs.size(); ++i)
    {
      const float x = xs[i];
      const float y = ys[i];

      xs[i] =
        T[0] * x +
        T[1] * y +
        T[3];

      ys[i] =
        T[4] * x +
        T[5] * y +
        T[7];
    }
  }

  // ------------------------------------------------------------
  // right_scanの生の到着時刻を記録
  // ------------------------------------------------------------
  void rawScan1Callback(
    const LaserScan::ConstSharedPtr & msg)
  {
    const int64_t key =
      rclcpp::Time(msg->header.stamp).nanoseconds();

    const auto now =
      std::chrono::steady_clock::now();

    recv_times_[key] = now;

    // 2秒以上前のデータを削除
    for (auto it = recv_times_.begin();
         it != recv_times_.end();)
    {
      if (
        std::chrono::duration<double>(
          now - it->second).count() > 2.0)
      {
        it = recv_times_.erase(it);
      }
      else
      {
        ++it;
      }
    }
  }

  // ------------------------------------------------------------
  // synchronized callback
  // ------------------------------------------------------------
  void callback(
    const LaserScan::ConstSharedPtr & s1,
    const LaserScan::ConstSharedPtr & s2)
  {
    const auto t_start =
      std::chrono::steady_clock::now();

    // ============================================================
    // 同期状態の測定
    // ============================================================

    const double right_stamp =
      rclcpp::Time(
        s1->header.stamp).seconds();

    const double left_stamp =
      rclcpp::Time(
        s2->header.stamp).seconds();

    // right / left のheader.stamp差
    const double stamp_diff_ms =
      std::abs(right_stamp - left_stamp) * 1000.0;

    // callbackに入った時点での各scanの経過時間
    const double right_age_ms =
      (
        this->get_clock()->now() -
        rclcpp::Time(s1->header.stamp)
      ).seconds() * 1000.0;

    const double left_age_ms =
      (
        this->get_clock()->now() -
        rclcpp::Time(s2->header.stamp)
      ).seconds() * 1000.0;

    RCLCPP_INFO_THROTTLE(
      this->get_logger(),
      *this->get_clock(),
      1000,
      "SYNC: right_age=%.2f ms, "
      "left_age=%.2f ms, "
      "stamp_diff=%.2f ms",
      right_age_ms,
      left_age_ms,
      stamp_diff_ms);

    // ============================================================
    // TF
    // ============================================================

    geometry_msgs::msg::TransformStamped tf1;
    geometry_msgs::msg::TransformStamped tf2;

    try
    {
      tf1 = tf_buffer_->lookupTransform(
        target_frame_,
        s1->header.frame_id,
        tf2_ros::fromMsg(s1->header.stamp),
        tf2::durationFromSec(0.2));

      tf2 = tf_buffer_->lookupTransform(
        target_frame_,
        s2->header.frame_id,
        tf2_ros::fromMsg(s2->header.stamp),
        tf2::durationFromSec(0.2));
    }
    catch (const tf2::TransformException & e)
    {
      RCLCPP_WARN(
        this->get_logger(),
        "tf failed: %s",
        e.what());

      return;
    }

    const auto t_tf_done =
      std::chrono::steady_clock::now();

    // ============================================================
    // TF行列
    // ============================================================

    const Mat4 T1 =
      tfToMatrix(tf1);

    const Mat4 T2 =
      tfToMatrix(tf2);

    // ============================================================
    // scan -> XY
    // ============================================================

    std::vector<float> x1;
    std::vector<float> y1;
    std::vector<float> x2;
    std::vector<float> y2;

    scanToXY(
      *s1,
      x1,
      y1);

    scanToXY(
      *s2,
      x2,
      y2);

    // ============================================================
    // TF適用
    // ============================================================

    transformXY(
      x1,
      y1,
      T1);

    transformXY(
      x2,
      y2,
      T2);

    // ============================================================
    // merge
    // ============================================================

    std::vector<float> xs;
    std::vector<float> ys;

    xs.reserve(
      x1.size() +
      x2.size());

    ys.reserve(
      y1.size() +
      y2.size());

    xs.insert(
      xs.end(),
      x1.begin(),
      x1.end());

    xs.insert(
      xs.end(),
      x2.begin(),
      x2.end());

    ys.insert(
      ys.end(),
      y1.begin(),
      y1.end());

    ys.insert(
      ys.end(),
      y2.begin(),
      y2.end());

    // ============================================================
    // 出力グリッド
    // ============================================================

    const float angle_min =
      -static_cast<float>(M_PI);

    const float angle_max =
      static_cast<float>(M_PI);

    const float angle_inc =
      std::min(
        std::fabs(s1->angle_increment),
        std::fabs(s2->angle_increment));

    const int num =
      static_cast<int>(
        std::round(
          (angle_max - angle_min) /
          angle_inc)) + 1;

    std::vector<float> merged(
      num,
      std::numeric_limits<float>::infinity());

    // ============================================================
    // 極座標へ変換してscatter-min
    // ============================================================

    for (size_t i = 0; i < xs.size(); ++i)
    {
      const float angle =
        std::atan2(
          ys[i],
          xs[i]);

      const float range =
        std::sqrt(
          xs[i] * xs[i] +
          ys[i] * ys[i]);

      const int idx =
        static_cast<int>(
          std::round(
            (angle - angle_min) /
            angle_inc));

      if (idx < 0 || idx >= num)
      {
        continue;
      }

      if (range < merged[idx])
      {
        merged[idx] = range;
      }
    }

    const auto t_process_done =
      std::chrono::steady_clock::now();

    // ============================================================
    // 出力LaserScan作成
    // ============================================================

    LaserScan msg;

    msg.header = s1->header;
    msg.header.frame_id =
      target_frame_;

    msg.angle_min =
      angle_min;

    msg.angle_max =
      angle_max;

    msg.angle_increment =
      angle_inc;

    msg.range_min =
      std::max(
        s1->range_min,
        s2->range_min);

    msg.range_max =
      std::min(
        s1->range_max,
        s2->range_max);

    msg.ranges =
      merged;

    msg.intensities.clear();

    // ============================================================
    // publish
    // ============================================================

    pub_->publish(msg);

    const auto t_end =
      std::chrono::steady_clock::now();

    // ============================================================
    // 処理時間
    // ============================================================

    const double tf_ms =
      std::chrono::duration<double, std::milli>(
        t_tf_done - t_start).count();

    const double proc_ms =
      std::chrono::duration<double, std::milli>(
        t_process_done - t_tf_done).count();

    const double publish_ms =
      std::chrono::duration<double, std::milli>(
        t_end - t_process_done).count();

    const double total_ms =
      std::chrono::duration<double, std::milli>(
        t_end - t_start).count();

    // ============================================================
    // header.stampから現在時刻まで
    // ============================================================

    const double latency_ms =
      (
        this->get_clock()->now() -
        rclcpp::Time(s1->header.stamp)
      ).seconds() * 1000.0;

    // ============================================================
    // raw right_scan受信時刻 -> merged_scan publish
    // ============================================================

    double sync_delay_ms = -1.0;

    {
      const int64_t key =
        rclcpp::Time(
          s1->header.stamp).nanoseconds();

      const auto it =
        recv_times_.find(key);

      if (it != recv_times_.end())
      {
        sync_delay_ms =
          std::chrono::duration<double, std::milli>(
            t_end - it->second).count();

        recv_times_.erase(it);
      }
    }

    // ============================================================
    // ログ
    // ============================================================

    RCLCPP_INFO_THROTTLE(
      this->get_logger(),
      *this->get_clock(),
      1000,

      "tf: %.2fms, "
      "merge: %.2fms, "
      "publish: %.2fms, "
      "callback total: %.2fms, "
      "e2e latency: %.2fms, "
      "right_scan->merged_scan: %.2fms",

      tf_ms,
      proc_ms,
      publish_ms,
      total_ms,
      latency_ms,
      sync_delay_ms);
  }

  // ==============================================================
  // Members
  // ==============================================================

  message_filters::Subscriber<LaserScan> sub1_;
  message_filters::Subscriber<LaserScan> sub2_;

  std::shared_ptr<Sync> sync_;

  rclcpp::Publisher<LaserScan>::SharedPtr pub_;

  rclcpp::Subscription<LaserScan>::SharedPtr raw_sub1_;

  std::unordered_map<
    int64_t,
    std::chrono::steady_clock::time_point>
    recv_times_;

  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;

  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

  std::string target_frame_;
};

// ================================================================
// main
// ================================================================

int main(
  int argc,
  char ** argv)
{
  rclcpp::init(argc, argv);

  auto node =
    std::make_shared<LaserScanMergerCpp>();

  rclcpp::spin(node);

  rclcpp::shutdown();

  return 0;
}