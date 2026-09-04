#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <memory>
#include <mutex>
#include <rclcpp/logging.hpp>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>
#include <vector>

#include "custom_msgs/action/follow_path.hpp"
#include "custom_msgs/msg/can_packet.hpp"
#include "geometry_msgs/msg/pose2_d.hpp"
#include "rcl_interfaces/msg/set_parameters_result.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"


#include "ament_index_cpp/get_package_share_directory.hpp"



#include "path_loader.hpp"
#include "omni.hpp"





constexpr double CONTROL_RATE_HZ = 100.0;
constexpr float PI = 3.14159265358979323846f;








struct Params{
    double kp_xy = 0.003;
    double kp_yaw = 2.0;
    double start_tolerance_xy = 500.0;
    double start_tolerance_yaw = 0.5;
    double goal_tolerance_xy = 10.0;
    double goal_tolerance_yaw = 0.03;
    double pose1_timeout = 0.2;
};


float nearest_equivalent_angle(float current_theta, float target_theta)
{
    float difference = target_theta - current_theta;
    while (difference > PI) {
        difference -= 2.0f * PI;
    }
    while (difference <= -PI) {
        difference += 2.0f * PI;
    }
    return current_theta + difference;
}



class PathFollowServer : public rclcpp::Node
{
public:

    PathFollowServer()
    : Node("path_follow_node")
    {
        declare_and_read_parameters();


        paths = path_loader::load_paths(
            ament_index_cpp::get_package_share_directory("mast") + "/path/"
        );

        for(uint32_t i = 0; i < path_loader::path_files_name.size(); i++){
            RCLCPP_INFO(
                this -> get_logger(),
                "loaded path %s with %zu poses",
                paths[i].name.c_str(),
                paths[i].poses.size()
            );
        }


        rclcpp::QoS qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        qos_profile.best_effort();
        qos_profile.durability_volatile();

        pose1_sub = create_subscription<geometry_msgs::msg::Pose2D>(
            "pose1",
            qos_profile,
            [this](const geometry_msgs::msg::Pose2D::SharedPtr message) {
                std::lock_guard<std::mutex> lock(pose_mutex);
                current_pose = *message;
                pose_received = true;
                last_pose_time = std::chrono::steady_clock::now();
            }
        );

        can_pub = create_publisher<custom_msgs::msg::CanPacket>("can_tx_line", qos_profile);

        action_server = rclcpp_action::create_server<custom_msgs::action::FollowPath>(
            this,
            "follow_path",
            std::bind(&PathFollowServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&PathFollowServer::handle_cancel, this, std::placeholders::_1),
            std::bind(&PathFollowServer::handle_accepted, this, std::placeholders::_1)
        );


        RCLCPP_INFO(this -> get_logger(), "init finished");

    }

private:
    rclcpp_action::Server<custom_msgs::action::FollowPath>::SharedPtr action_server;
    rclcpp::Subscription<geometry_msgs::msg::Pose2D>::SharedPtr pose1_sub;
    rclcpp::Publisher<custom_msgs::msg::CanPacket>::SharedPtr can_pub;

    
    std::array<path_loader::Path, path_loader::path_files_name.size()> paths;
    

    std::mutex pose_mutex;
    geometry_msgs::msg::Pose2D current_pose;
    bool pose_received = false;
    std::chrono::steady_clock::time_point last_pose_time;

    std::mutex active_goal_mutex;
    std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::FollowPath>> active_goal_handle;

    Params params;
    std::string field_color{"blue"};

    void declare_and_read_parameters()
    {
        field_color = this->declare_parameter<std::string>("field_color", field_color);
        params.kp_xy = this->declare_parameter<double>("kp_xy", params.kp_xy);
        params.kp_yaw = this->declare_parameter<double>("kp_yaw", params.kp_yaw);
        params.start_tolerance_xy = this->declare_parameter<double>("start_tolerance_xy", params.start_tolerance_xy);
        params.start_tolerance_yaw = this->declare_parameter<double>("start_tolerance_yaw", params.start_tolerance_yaw);
        params.goal_tolerance_xy = this->declare_parameter<double>("goal_tolerance_xy", params.goal_tolerance_xy);
        params.goal_tolerance_yaw = this->declare_parameter<double>("goal_tolerance_yaw", params.goal_tolerance_yaw);
        params.pose1_timeout = this->declare_parameter<double>("pose1_timeout", params.pose1_timeout);
    }


    geometry_msgs::msg::Pose2D target_pose_for_field(
        const geometry_msgs::msg::Pose2D & target_pose) const
    {
        geometry_msgs::msg::Pose2D result = target_pose;
        if(field_color == "red"){
            result.y = -result.y;
        }
        return result;
    }


    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const custom_msgs::action::FollowPath::Goal> goal
    ){

        (void)uuid;

        const uint32_t path_index_ = path_loader::find_path_index(goal -> path_name);
        if(path_index_ == path_loader::path_files_name.size()){
            RCLCPP_INFO(this -> get_logger(), "invalid goal name : %s", goal -> path_name.c_str());
            return rclcpp_action::GoalResponse::REJECT;
        }



        {
            std::lock_guard<std::mutex> lock(active_goal_mutex);
            if (active_goal_handle != nullptr && active_goal_handle -> is_active()) {
                RCLCPP_INFO(get_logger(), "goal rejected: follow path is already active");
                return rclcpp_action::GoalResponse::REJECT;
            }
        }


        {
            std::lock_guard<std::mutex> lock(pose_mutex);

            if(!pose_received) {
                RCLCPP_INFO(this -> get_logger(), "goal rejected: pose1 is not initialized");
                return rclcpp_action::GoalResponse::REJECT;
            }

            if(params.pose1_timeout < std::chrono::duration<double>(std::chrono::steady_clock::now() - last_pose_time).count()){
                RCLCPP_INFO(this -> get_logger(), "goal rejected: pose1 hz is low");
                return rclcpp_action::GoalResponse::REJECT;
            }

        }

        geometry_msgs::msg::Pose2D current_pose_copy;
        {
            std::lock_guard<std::mutex> lock(pose_mutex);
            current_pose_copy = current_pose;
        }

        const geometry_msgs::msg::Pose2D start_pose =
            target_pose_for_field(paths[path_index_].poses.front());

        const float start_distance_xy = std::hypot(
            start_pose.x - current_pose_copy.x,
            start_pose.y - current_pose_copy.y
        );

        const float start_distance_yaw = std::abs(
            nearest_equivalent_angle(
                current_pose_copy.theta, start_pose.theta
            ) - current_pose_copy.theta
        );

        if (params.start_tolerance_xy < start_distance_xy || params.start_tolerance_yaw < start_distance_yaw) {
            
            RCLCPP_INFO(
                this -> get_logger(),
                "goal rejected: xy distance %f, yaw distance %f",
                start_distance_xy,
                start_distance_yaw
            );
            return rclcpp_action::GoalResponse::REJECT;

        }

        RCLCPP_INFO(this -> get_logger(), "goal accepted: path name %s", goal -> path_name.c_str());

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::FollowPath>> goal_handle
    ){
        std::lock_guard<std::mutex> lock(active_goal_mutex);
        if (active_goal_handle == nullptr) {
            RCLCPP_WARN(get_logger(), "Cancel rejected: no active path goal");
            return rclcpp_action::CancelResponse::REJECT;
        }
        if (goal_handle != active_goal_handle) {
            RCLCPP_WARN(get_logger(), "Cancel rejected: goal handle does not match");
            return rclcpp_action::CancelResponse::REJECT;
        }

        RCLCPP_INFO(get_logger(), "Cancel accepted for active path goal");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::FollowPath>> goal_handle)
    {
        {
            std::lock_guard<std::mutex> lock(active_goal_mutex);
            active_goal_handle = goal_handle;
        }

        std::thread{
            [this, goal_handle]() {
                execute(goal_handle);
            }
        }.detach();
    }


    void execute(const std::shared_ptr<
        rclcpp_action::ServerGoalHandle<custom_msgs::action::FollowPath>
        > goal_handle
    ){
        const uint32_t path_index =
            path_loader::find_path_index(goal_handle->get_goal()->path_name);
        if (path_index == path_loader::path_files_name.size()) {
            abort_goal(goal_handle, "selected path disappeared");
            return;
        }

        path_loader::Path path = paths[path_index];
        uint32_t point_index = 0;
        rclcpp::WallRate loop_rate(CONTROL_RATE_HZ);

        while (rclcpp::ok()) {
            if (goal_handle->is_canceling()) {
                cancel_goal(goal_handle, "path goal canceled by user");
                return;
            }

            geometry_msgs::msg::Pose2D current_pose_copy;
            double pose_age = 0.0;
            {
                std::lock_guard<std::mutex> lock(pose_mutex);
                if (!pose_received) {
                    abort_goal(goal_handle, "pose1 is not available");
                    return;
                }

                current_pose_copy = current_pose;
                pose_age = std::chrono::duration<double>(
                    std::chrono::steady_clock::now() - last_pose_time).count();
            }

            if (pose_age > params.pose1_timeout) {
                abort_goal(goal_handle, "pose1 timed out");
                return;
            }

            const geometry_msgs::msg::Pose2D target_pose =
                target_pose_for_field(path.poses[point_index]);
            const double target_theta = nearest_equivalent_angle(
                current_pose_copy.theta,
                target_pose.theta
            );

            const double error_x = target_pose.x - current_pose_copy.x;
            const double error_y = target_pose.y - current_pose_copy.y;
            const double error_yaw = target_theta - current_pose_copy.theta;
            const bool final_point = point_index + 1 >= path.poses.size();

            const double global_vx = params.kp_xy * error_x;
            const double global_vy = params.kp_xy * error_y;
            const double omega = params.kp_yaw * error_yaw;

            const double local_vx =
                std::cos(-current_pose_copy.theta) * global_vx -
                std::sin(-current_pose_copy.theta) * global_vy;
            const double local_vy =
                std::sin(-current_pose_copy.theta) * global_vx +
                std::cos(-current_pose_copy.theta) * global_vy;

            can_pub->publish(omni::can_packet(
                static_cast<float>(local_vx),
                static_cast<float>(local_vy),
                static_cast<float>(omega)
            ));

            auto feedback = std::make_shared<custom_msgs::action::FollowPath::Feedback>();
            feedback->path_name = path.name;
            feedback->index = point_index;
            feedback->ref_x = static_cast<float>(target_pose.x);
            feedback->ref_y = static_cast<float>(target_pose.y);
            feedback->ref_yaw = static_cast<float>(target_pose.theta);
            feedback->now_x = static_cast<float>(current_pose_copy.x);
            feedback->now_y = static_cast<float>(current_pose_copy.y);
            feedback->now_yaw = static_cast<float>(current_pose_copy.theta);
            goal_handle->publish_feedback(feedback);

            if (final_point) {
                loop_rate.sleep();
                succeed_goal(goal_handle, "path playback finished");
                return;
            }

            ++point_index;
            loop_rate.sleep();
        }

        can_pub->publish(omni::stop_packet());
        clear_active_goal(goal_handle);
    }


    void succeed_goal(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::FollowPath>> goal_handle,
        const std::string & message)
    {
        can_pub -> publish(omni::stop_packet());
        auto result = std::make_shared<custom_msgs::action::FollowPath::Result>();
        result->success = true;
        result->message = message;
        goal_handle->succeed(result);
        clear_active_goal(goal_handle);
        RCLCPP_INFO(get_logger(), "%s", message.c_str());
    }

    void cancel_goal(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::FollowPath>> goal_handle,
        const std::string & message)
    {
        can_pub -> publish(omni::stop_packet());
        auto result = std::make_shared<custom_msgs::action::FollowPath::Result>();
        result->success = false;
        result->message = message;
        goal_handle->canceled(result);
        clear_active_goal(goal_handle);
        RCLCPP_INFO(get_logger(), "%s", message.c_str());
    }

    void abort_goal(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::FollowPath>> goal_handle,
        const std::string & message)
    {
        if (goal_handle->is_canceling()) {
            cancel_goal(goal_handle, "path goal canceled by user");
            return;
        }

        can_pub -> publish(omni::stop_packet());
        auto result = std::make_shared<custom_msgs::action::FollowPath::Result>();
        result->success = false;
        result->message = message;
        goal_handle->abort(result);
        clear_active_goal(goal_handle);
        RCLCPP_WARN(get_logger(), "%s", message.c_str());
    }

    void clear_active_goal(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::FollowPath>> goal_handle)
    {
        std::lock_guard<std::mutex> lock(active_goal_mutex);
        if (active_goal_handle == goal_handle) {
            active_goal_handle.reset();
        }
    }


};


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PathFollowServer>());
    rclcpp::shutdown();
    return 0;
}
