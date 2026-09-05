#include "custom_msgs/msg/can_packet.hpp"
#include "custom_msgs/action/follow_path.hpp"
#include "custom_msgs/action/hoju.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstring>
#include <future>
#include <fstream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <rclcpp/logging.hpp>
#include "controller/msg/controller.hpp"
#include "geometry_msgs/msg/pose2_d.hpp"
#include "pid_control.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include "ament_index_cpp/get_package_share_directory.hpp"
#include "yaml-cpp/yaml.h"

#include "omni.hpp"
#include "path_loader.hpp"
#include "shoot.hpp"




float nearest_equivalent_angle(float current_theta, float base_angle){
    float diff = base_angle - current_theta;
    while(diff > static_cast<float>(M_PI))   diff -= 2.0f * static_cast<float>(M_PI);
    while(diff <= -static_cast<float>(M_PI)) diff += 2.0f * static_cast<float>(M_PI);
    return current_theta + diff;
}





enum class ControlMode{
    JOY,
    AUTO
};




class Mast : public rclcpp::Node
{
public:
    Mast() : Node("mast_node")
    {
        field_color = this -> declare_parameter<std::string>("field_color", "blue");

        rclcpp::QoS qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        qos_profile.best_effort();
        qos_profile.durability_volatile();

        pose1_sub = this -> create_subscription<geometry_msgs::msg::Pose2D>(
            "pose1",
            qos_profile,
            [this](const geometry_msgs::msg::Pose2D::SharedPtr msg) {
                std::lock_guard<std::mutex> lock(pose_mutex);
                current_pose = *msg;
                pose_received = true;
            }
        );

        controller_sub = this -> create_subscription<controller::msg::Controller>(
            "controller_val",
            qos_profile,
            [this](const controller::msg::Controller::SharedPtr msg) {
                current_controller_val = *msg;
            }
        );

        can_pub = this -> create_publisher<custom_msgs::msg::CanPacket>("can_tx_line", qos_profile);

        hoju_client = rclcpp_action::create_client<custom_msgs::action::Hoju>(
            this,
            "hoju"
        );

        path_follow_client = rclcpp_action::create_client<custom_msgs::action::FollowPath>(
            this,
            "follow_path"
        );

        paths = path_loader::load_paths(
            ament_index_cpp::get_package_share_directory("mast") + "/path/"
        );

        main_timer = this -> create_wall_timer(
            std::chrono::milliseconds(10),
            std::bind(&Mast::main_loop, this)
        );
            
        RCLCPP_INFO(
            this -> get_logger(),
            "Mast Node Started. field_color: %s",
            field_color.c_str()
        );
    }

    ~ Mast() override
    {
        if(execute_thread.joinable()){
            execute_thread.join();
        }
    }


private:


    geometry_msgs::msg::Pose2D target_pose_for_field(
        const geometry_msgs::msg::Pose2D & target_pose) const
    {
        geometry_msgs::msg::Pose2D result = target_pose;
        if(field_color == "red"){
            result.y = -result.y;
        }
        return result;
    }



    void main_loop(){

        int32_t dengen_on;
        if(current_controller_val.dengen){
            dengen_on = 1;
        }
        else{
            dengen_on = 0;
        }

        custom_msgs::msg::CanPacket txpacket;
        txpacket.id = 0x160;
        memcpy(&txpacket.data[0], &dengen_on, 4);
        can_pub -> publish(txpacket);

        if(!current_controller_val.execute){
            execute_button_latched = false;
        }

        if(control_mode.load() == ControlMode::AUTO){
            return;
        }

        if(current_controller_val.execute && !execute_button_latched){
            execute_button_latched = true;
            control_mode.store(ControlMode::AUTO);

            if(execute_thread.joinable()){
                execute_thread.join();
            }

            execute_thread = std::thread([this](){
                this -> execute();
            });

            return;
        }

        if(current_controller_val.hojuposition){

            geometry_msgs::msg::Pose2D hoju_pose{};
            hoju_pose.x = 4080.0 + current_controller_val.hoju_turn_y;
            hoju_pose.y = 500.0 - current_controller_val.hoju_turn_x;
            hoju_pose.theta = 0.0 + current_controller_val.hoju_turn_theta * (M_PI / 180.0);

            hoju_pose = target_pose_for_field(hoju_pose);

            positioning(hoju_pose);

            return;
        }

        float x_speed = current_controller_val.y * 3.672f;
        float y_speed = current_controller_val.x * - 3.672f;

        auto filter_deadzone_ = [](float value, float deadzone, float maxValue) {
            if (std::abs(value) < deadzone) return 0.0f;
            float remapped = (std::abs(value) - deadzone) / (maxValue - deadzone);
            remapped = std::clamp(remapped, 0.0f, 1.0f);
            return std::copysign(remapped, value);
        };

        float yaw_speed = filter_deadzone_(current_controller_val.theta * - 1.0f, 0.02f, 1.0f) * 4.9;
                
        static float lp_x   = 0.0f;
        static float lp_y   = 0.0f;
        static float lp_yaw = 0.0f;
        constexpr float ALPHA = 0.15f;

        lp_x   = ALPHA * x_speed   + (1.0f - ALPHA) * lp_x;
        lp_y   = ALPHA * y_speed   + (1.0f - ALPHA) * lp_y;
        lp_yaw = ALPHA * yaw_speed + (1.0f - ALPHA) * lp_yaw;

        x_speed   = lp_x;
        y_speed   = lp_y;
        yaw_speed = lp_yaw;

        can_pub -> publish(omni::can_packet(x_speed, y_speed, yaw_speed));

    }
    


    void execute(){

        RCLCPP_INFO(this -> get_logger(), "automatic sequence started");

        const auto fail = [this](const std::string & message) {
            RCLCPP_ERROR(this -> get_logger(), "automatic sequence stopped: %s", message.c_str());
            can_pub -> publish(omni::stop_packet());
            control_mode.store(ControlMode::JOY);
        };

        if(!wait_for_pose(std::chrono::seconds(2))){
            fail("pose1 is not available");
            return;
        }

        if(
            !hoju_client -> wait_for_action_server(std::chrono::seconds(5)) ||
            !path_follow_client -> wait_for_action_server(std::chrono::seconds(5))
        ){
            fail("action server is not available");
            return;
        }

        can_pub -> publish(omni::stop_packet());

        // geometry_msgs::msg::Pose2D start_pose;
        // start_pose.x = 4050.0;
        // start_pose.y = 465.0;
        // start_pose.theta = 0.0;

        // RCLCPP_INFO(this -> get_logger(), "positioning at the refill point for 2 seconds");
        // if(!position_for(start_pose, std::chrono::seconds(2))){
        //     fail("initial positioning was interrupted");
        //     return;
        // }

        if(!send_hoju_goal_and_wait("GET")){
            fail("GET failed");
            return;
        }

        if(!send_parallel_goals_and_wait("start_to_bucket", "HOJU_0")){
            fail("start_to_bucket or HOJU_0 failed");
            return;
        }

        const uint32_t start_to_bucket_index =
            path_loader::find_path_index("start_to_bucket");
        geometry_msgs::msg::Pose2D bucket_pose =
            paths[start_to_bucket_index].poses.back();

        RCLCPP_INFO(this -> get_logger(), "positioning at the end of start_to_bucket");
        if(!position_until_reached(bucket_pose, std::chrono::seconds(10))){
            fail("bucket positioning for index 2 timed out");
            return;
        }

        shoot(0, 4.4f);

        // if(!interruptible_delay(std::chrono::seconds(2))){
        //     fail("sequence was interrupted after firing index 2");
        //     return;
        // }

        bucket_pose.y += 100.0;
        if(!position_until_reached(bucket_pose, std::chrono::seconds(10))){
            fail("bucket positioning for index 1 timed out");
            return;
        }
        shoot(1, 4.4f);

        bucket_pose.y += 100.0;
        if(!position_until_reached(bucket_pose, std::chrono::seconds(10))){
            fail("bucket positioning for index 0 timed out");
            return;
        }
        shoot(2, 4.4f);

        if(!send_parallel_goals_and_wait("bucket_to_flag", "HOJU_1")){
            fail("bucket_to_flag or HOJU_1 failed");
            return;
        }

        const uint32_t bucket_to_flag_index =
            path_loader::find_path_index("bucket_to_flag");
        const geometry_msgs::msg::Pose2D flag_pose =
            paths[bucket_to_flag_index].poses.back();

        if(!position_until_reached(flag_pose, std::chrono::seconds(10))){
            fail("flag positioning timed out");
            return;
        }

        if(!shoot_three(10.0f)){
            fail("first flag shooting sequence was interrupted");
            return;
        }

        if(!send_hoju_goal_and_wait("HOJU_2")){
            fail("HOJU_2 failed");
            return;
        }

        if(!shoot_three(10.0f)){
            fail("second flag shooting sequence was interrupted");
            return;
        }

        if(!send_path_goal_and_wait("flag_to_start")){
            fail("flag_to_start failed");
            return;
        }

        geometry_msgs::msg::Pose2D finish_pose{};
        finish_pose.x = 4080.0;
        finish_pose.y = 500.0;
        finish_pose.theta = 0.0;

        RCLCPP_INFO(this -> get_logger(), "holding at the finish pose for 1 second");
        if(!position_for(finish_pose, std::chrono::seconds(1))){
            fail("final positioning was interrupted");
            return;
        }

        can_pub -> publish(omni::stop_packet());
        control_mode.store(ControlMode::JOY);
        RCLCPP_INFO(this -> get_logger(), "automatic sequence completed");

    }



    void positioning(geometry_msgs::msg::Pose2D target_pose){

        geometry_msgs::msg::Pose2D pose;
        {
            std::lock_guard<std::mutex> lock(pose_mutex);
            pose = current_pose;
        }

        target_pose.theta = nearest_equivalent_angle(pose.theta, target_pose.theta);

        float x_speed, y_speed, yaw_speed;
        x_speed = pid_x.calculate_output(target_pose.x - pose.x);
        y_speed = pid_y.calculate_output(target_pose.y - pose.y);
        yaw_speed = pid_yaw.calculate_output(target_pose.theta - pose.theta);

		double local_vx = cos(- pose.theta) * x_speed - sin(- pose.theta) * y_speed;
		double local_vy = sin(- pose.theta) * x_speed + cos(- pose.theta) * y_speed;

        can_pub -> publish(omni::can_packet(local_vx, local_vy, yaw_speed));

    }



    bool wait_for_pose(const std::chrono::milliseconds timeout)
    {
        const auto deadline = std::chrono::steady_clock::now() + timeout;

        while(rclcpp::ok() && std::chrono::steady_clock::now() < deadline){
            {
                std::lock_guard<std::mutex> lock(pose_mutex);
                if(pose_received){
                    return true;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        return false;
    }



    bool position_for(
        const geometry_msgs::msg::Pose2D & target_pose,
        const std::chrono::milliseconds duration)
    {
        const geometry_msgs::msg::Pose2D field_target_pose =
            target_pose_for_field(target_pose);

        pid_x.reset();
        pid_y.reset();
        pid_yaw.reset();

        const auto finish_time = std::chrono::steady_clock::now() + duration;
        while(rclcpp::ok() && std::chrono::steady_clock::now() < finish_time){
            positioning(field_target_pose);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        can_pub -> publish(omni::stop_packet());
        return rclcpp::ok();
    }



    bool position_until_reached(
        const geometry_msgs::msg::Pose2D & target_pose,
        const std::chrono::milliseconds timeout)
    {
        const geometry_msgs::msg::Pose2D field_target_pose =
            target_pose_for_field(target_pose);

        constexpr double POSITION_TOLERANCE_MM = 10.0;
        constexpr double YAW_TOLERANCE_RAD = 0.03;
        constexpr auto STABLE_DURATION = std::chrono::milliseconds(200);

        pid_x.reset();
        pid_y.reset();
        pid_yaw.reset();

        const auto deadline = std::chrono::steady_clock::now() + timeout;
        auto stable_since = std::chrono::steady_clock::time_point{};

        while(rclcpp::ok() && std::chrono::steady_clock::now() < deadline){
            positioning(field_target_pose);

            geometry_msgs::msg::Pose2D pose;
            {
                std::lock_guard<std::mutex> lock(pose_mutex);
                pose = current_pose;
            }

            const double error_xy = std::hypot(
                field_target_pose.x - pose.x,
                field_target_pose.y - pose.y
            );
            const double target_theta = nearest_equivalent_angle(
                pose.theta,
                field_target_pose.theta
            );
            const double error_yaw = std::abs(target_theta - pose.theta);
            const auto now = std::chrono::steady_clock::now();

            if(error_xy <= POSITION_TOLERANCE_MM && error_yaw <= YAW_TOLERANCE_RAD){
                if(stable_since == std::chrono::steady_clock::time_point{}){
                    stable_since = now;
                }
                else if(now - stable_since >= STABLE_DURATION){
                    can_pub -> publish(omni::stop_packet());
                    return true;
                }
            }
            else{
                stable_since = std::chrono::steady_clock::time_point{};
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        can_pub -> publish(omni::stop_packet());
        return false;
    }



    bool interruptible_delay(const std::chrono::milliseconds duration)
    {
        const auto finish_time = std::chrono::steady_clock::now() + duration;
        while(rclcpp::ok() && std::chrono::steady_clock::now() < finish_time){
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        return rclcpp::ok();
    }



    template<typename FutureT>
    bool wait_for_future(FutureT & future, const std::chrono::milliseconds timeout)
    {
        const auto deadline = std::chrono::steady_clock::now() + timeout;
        while(rclcpp::ok() && std::chrono::steady_clock::now() < deadline){
            if(future.wait_for(std::chrono::milliseconds(100)) == std::future_status::ready){
                return true;
            }
        }
        return false;
    }



    bool send_hoju_goal_and_wait(const std::string & action_name)
    {
        custom_msgs::action::Hoju::Goal goal;
        goal.action_name = action_name;

        RCLCPP_INFO(this -> get_logger(), "sending Hoju goal: %s", action_name.c_str());
        auto goal_future = hoju_client -> async_send_goal(goal);
        if(!wait_for_future(goal_future, std::chrono::seconds(5))){
            RCLCPP_ERROR(this -> get_logger(), "Hoju goal response timed out: %s", action_name.c_str());
            return false;
        }

        auto goal_handle = goal_future.get();
        if(!goal_handle){
            RCLCPP_ERROR(this -> get_logger(), "Hoju goal was rejected: %s", action_name.c_str());
            return false;
        }

        auto result_future = hoju_client -> async_get_result(goal_handle);
        if(!wait_for_future(result_future, std::chrono::seconds(30))){
            RCLCPP_ERROR(this -> get_logger(), "Hoju result timed out: %s", action_name.c_str());
            return false;
        }

        const auto wrapped_result = result_future.get();
        return
            wrapped_result.code == rclcpp_action::ResultCode::SUCCEEDED &&
            wrapped_result.result &&
            wrapped_result.result -> success;
    }



    bool send_path_goal_and_wait(const std::string & path_name)
    {
        custom_msgs::action::FollowPath::Goal goal;
        goal.path_name = path_name;

        RCLCPP_INFO(this -> get_logger(), "sending FollowPath goal: %s", path_name.c_str());
        auto goal_future = path_follow_client -> async_send_goal(goal);
        if(!wait_for_future(goal_future, std::chrono::seconds(5))){
            RCLCPP_ERROR(this -> get_logger(), "FollowPath goal response timed out: %s", path_name.c_str());
            return false;
        }

        auto goal_handle = goal_future.get();
        if(!goal_handle){
            RCLCPP_ERROR(this -> get_logger(), "FollowPath goal was rejected: %s", path_name.c_str());
            return false;
        }

        auto result_future = path_follow_client -> async_get_result(goal_handle);
        if(!wait_for_future(result_future, std::chrono::seconds(30))){
            RCLCPP_ERROR(this -> get_logger(), "FollowPath result timed out: %s", path_name.c_str());
            return false;
        }

        const auto wrapped_result = result_future.get();
        return
            wrapped_result.code == rclcpp_action::ResultCode::SUCCEEDED &&
            wrapped_result.result &&
            wrapped_result.result -> success;
    }



    bool send_parallel_goals_and_wait(
        const std::string & path_name,
        const std::string & action_name)
    {
        custom_msgs::action::FollowPath::Goal path_goal;
        path_goal.path_name = path_name;
        custom_msgs::action::Hoju::Goal hoju_goal;
        hoju_goal.action_name = action_name;

        RCLCPP_INFO(
            this -> get_logger(),
            "starting parallel goals: %s and %s",
            path_name.c_str(),
            action_name.c_str()
        );

        auto path_goal_future = path_follow_client -> async_send_goal(path_goal);
        auto hoju_goal_future = hoju_client -> async_send_goal(hoju_goal);

        if(
            !wait_for_future(path_goal_future, std::chrono::seconds(5)) ||
            !wait_for_future(hoju_goal_future, std::chrono::seconds(5))
        ){
            RCLCPP_ERROR(this -> get_logger(), "parallel goal response timed out");
            return false;
        }

        auto path_goal_handle = path_goal_future.get();
        auto hoju_goal_handle = hoju_goal_future.get();
        if(!path_goal_handle || !hoju_goal_handle){
            RCLCPP_ERROR(this -> get_logger(), "one of the parallel goals was rejected");
            return false;
        }

        auto path_result_future = path_follow_client -> async_get_result(path_goal_handle);
        auto hoju_result_future = hoju_client -> async_get_result(hoju_goal_handle);

        if(
            !wait_for_future(path_result_future, std::chrono::seconds(30)) ||
            !wait_for_future(hoju_result_future, std::chrono::seconds(30))
        ){
            RCLCPP_ERROR(this -> get_logger(), "parallel action result timed out");
            return false;
        }

        const auto path_result = path_result_future.get();
        const auto hoju_result = hoju_result_future.get();
        return
            path_result.code == rclcpp_action::ResultCode::SUCCEEDED &&
            path_result.result &&
            path_result.result -> success &&
            hoju_result.code == rclcpp_action::ResultCode::SUCCEEDED &&
            hoju_result.result &&
            hoju_result.result -> success;
    }



    void shoot(const uint32_t machine_index, const float velocity)
    {
        can_pub -> publish(::shoot::can_packet(machine_index, velocity));
        RCLCPP_INFO(
            this -> get_logger(),
            "shoot index %u at %.1f m/s",
            machine_index,
            static_cast<double>(velocity)
        );
    }



    bool shoot_three(const float velocity)
    {
        for(uint32_t machine_index = 0; machine_index < 3; ++machine_index){
            shoot(machine_index, velocity);
            if(machine_index < 2 && !interruptible_delay(std::chrono::seconds(1))){
                return false;
            }
        }
        return true;
    }



    std::atomic<ControlMode> control_mode{ControlMode::JOY};
    std::string field_color{"blue"};
    bool execute_button_latched = false;
    std::thread execute_thread;

    rclcpp::Publisher<custom_msgs::msg::CanPacket>::SharedPtr can_pub;
    rclcpp::Subscription<controller::msg::Controller>::SharedPtr controller_sub;
    controller::msg::Controller current_controller_val;
    rclcpp::Subscription<geometry_msgs::msg::Pose2D>::SharedPtr pose1_sub;
    std::mutex pose_mutex;
    geometry_msgs::msg::Pose2D current_pose;
    bool pose_received = false;

    rclcpp::TimerBase::SharedPtr delay_timer;
    rclcpp::TimerBase::SharedPtr main_timer;

    rclcpp_action::Client<custom_msgs::action::Hoju>::SharedPtr hoju_client;
    rclcpp_action::Client<custom_msgs::action::FollowPath>::SharedPtr path_follow_client;

    std::array<path_loader::Path, path_loader::path_files_name.size()> paths;

    pid_control pid_x{1000.0f, 0.002f, 0.0f, 0.0f, 1700.0f};
    pid_control pid_y{1000.0f, 0.002f, 0.0f, 0.0f, 1700.0f};
    pid_control pid_yaw{1000.0f, 2.0f, 0.0f, 0.0f, 4.0f};

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Mast>());
    rclcpp::shutdown();
    return 0;
}
