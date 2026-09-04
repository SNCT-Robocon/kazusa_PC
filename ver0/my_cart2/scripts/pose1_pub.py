#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose2D
from tf2_ros import Buffer, TransformListener, LookupException, ConnectivityException, ExtrapolationException, DurabilityPolicy
import math
import time
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
import subprocess
from std_msgs.msg import Bool
class TfPosePublisher(Node):
    def __init__(self):
        super().__init__('tf_pose_publisher')

        self.declare_parameter('field_color', 'none')
        
        # 値を取得して変数に格納
        self.color = self.get_parameter('field_color').get_parameter_value().string_value
        
        self.get_logger().info(f'設定されたfield: {self.color}')

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        qos_profile = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE
        )
        self.sub = self.create_subscription(Bool, '/cartrigger', self.callback, qos_profile)
       
     

        self.pose_pub = self.create_publisher(Pose2D, 'pose1', qos_profile)

        # 前回 publish したtfの timestamp を記憶
        self.last_stamp = None

        # 累積角度用
        self.prev_theta = None
        self.accum_theta = 0.0

        # 200fps (=0.005s) タイマー
        self.timer = self.create_timer(0.005, self.timer_callback)
        self.launched = False
        self.process = None
    def callback(self, msg):
            # Trueで起動
            if msg.data and not self.launched:
                self.get_logger().info('Received "True". Launching target node...')
                # self.accum_theta = 0.0  # ← この行を削除
                self.launched = True
                self.prev_theta = None    # ← これだけでOK
            # Falseで停止
            elif not msg.data and self.launched:
                self.get_logger().info('Received "False". Terminating target node...')
                self.process = None
                self.launched = False

    def unwrap_theta(self, prev, curr):
        """±πのジャンプを補正"""
        diff = curr - prev
        if diff > math.pi:
            diff -= 2 * math.pi
        elif diff < -math.pi:
            diff += 2 * math.pi
        return diff

    def timer_callback(self):
        try:
            trans = self.tf_buffer.lookup_transform('map', 'base_link', rclpy.time.Time())

            # 新しい TF かどうか確認
            stamp = trans.header.stamp
            if self.last_stamp is not None and stamp == self.last_stamp:
                return
            self.last_stamp = stamp

            pose = Pose2D()
            
            # --- XYの計算はそのまま ---
            if self.color == "red":
                pose.x = trans.transform.translation.x * 1000
                pose.y = trans.transform.translation.y * 1000
            elif self.color == "blue":
                pose.x = trans.transform.translation.x * 1000
                pose.y = trans.transform.translation.y * 1000
                
            q = trans.transform.rotation
            theta = math.atan2(
                2.0 * (q.w * q.z + q.x * q.y),
                1.0 - 2.0 * (q.y * q.y + q.z * q.z)
            )

            # --- ここから修正部分 ---
            # XY座標系の回転に合わせて、初期角度にもオフセットをかける
            # if self.color == "red":
            #     # X=Y, Y=-X は時計回りに90度回転
            #     base_theta = theta - (math.pi / 2.0)
            # elif self.color == "blue":
            #     # X=-Y, Y=X は反時計回りに90度回転
            #     base_theta = theta + (math.pi / 2.0)
            # else:
            base_theta = theta

            # 初期角度を -π 〜 π に正規化しておく
            base_theta = math.atan2(math.sin(base_theta), math.cos(base_theta))

            # 累積角度の更新
            if self.prev_theta is not None:
                # 差分は元のtheta同士で計算して足し合わせる
                diff = self.unwrap_theta(self.prev_theta, theta)
                self.accum_theta += diff
            else:
                # ★初回（prev_theta == None）のとき、初期絶対角度をセットする
                self.accum_theta = base_theta

            self.prev_theta = theta

            # 結果を代入
            pose.theta = self.accum_theta

            self.pose_pub.publish(pose)
            
        except (LookupException, ConnectivityException, ExtrapolationException):
            pass

def main(args=None):
    rclpy.init(args=args)
    node = TfPosePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
