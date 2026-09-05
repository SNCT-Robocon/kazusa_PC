#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "custom_msgs/msg/can_packet.hpp"
#include "custom_msgs/action/hoju.hpp"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <memory>
#include <mutex>
#include <string>
#include <string_view>
#include <thread>
#include <rclcpp/logging.hpp>
#include <rclcpp_action/server.hpp>
#include <rclcpp_action/server_goal_handle.hpp>
#include <rclcpp_action/types.hpp>
#include <vector>


/*

ノーマリーを定義する
z軸が、


初期位置
回収前
回収後
射出後1
射出後2
射出後3

*/

enum class ArmMode{
    INITIAL,// z=0 x=0 pitch=0 hands=allopen
    PRE_GET,// z=0.135 x=0.0 pitch=0.0 hands=allopen
    AFTER_GET,// z=0.135 x=0.0 pitch=0.0 hands=allclose
    AFTER_PUSU1,// z=0.135 x=0.0 pitch=0.0 hands=011
    AFTER_PUSH2,// z=0.135 x=0.15 pitch=0.0 hands=001
};

constexpr uint32_t actions_sum = 5;
constexpr std::string_view ActionNames[actions_sum] = {
    "GET",// 回収 initial or preget
    "HOJU_0",// 1列目を補充 after get
    "HOJU_1",// 2列目を補充 after push1
    "HOJU_2",// 3列目を補充 after push2
    "RETURN_NORMALLY"// 回収前位置に戻る preget以外からpregetへ
};




struct ArmState{
    float z;
    float x;
    float pitch;
};

struct TimedArmState
{
    float time_sec;
    ArmState state;
};


struct HandState{
    bool data[3];
};

struct TimedHandState
{
    float time_sec;
    HandState state;
};

struct HojuState{
    ArmState arm_state;
    HandState hand_state;
};





ArmState min_jark_trajectory(ArmState start_pos, ArmState finish_pos, float min_time, float max_time, float current_time){

    const float duration = max_time - min_time;

    if (duration <= 0.0f) {
        return finish_pos;
    }

    const float t = std::clamp(
        (current_time - min_time) / duration,
        0.0f,
        1.0f
    );

    const float t2 = t * t;
    const float t3 = t2 * t;
    const float t4 = t3 * t;
    const float t5 = t4 * t;

    const float blend = 10.0f * t3 - 15.0f * t4 + 6.0f * t5;

    auto interpolate = [blend](float start, float finish) {
        return start + (finish - start) * blend;
    };

    ArmState result{
        interpolate(start_pos.z, finish_pos.z),
        interpolate(start_pos.x, finish_pos.x),
        interpolate(start_pos.pitch, finish_pos.pitch)
    };

    return result;

}


std::size_t generate_hoju_trajectory(
    std::vector<HojuState> * trajectory,
    const ArmState & initial_arm_state,
    const HandState & initial_hand_state,
    const std::vector<TimedArmState> & arm_targets,
    const std::vector<TimedHandState> & hand_targets)
{
    constexpr float control_frequency_hz = 100.0f;

    if (trajectory == nullptr) {
        return 0;
    }

    trajectory->clear();

    float previous_arm_time = 0.0f;
    for (std::size_t i = 0; i < arm_targets.size(); ++i) {
        const float time_sec = arm_targets[i].time_sec;

        if (!std::isfinite(time_sec) || time_sec <= previous_arm_time) {
            return 0;
        }

        previous_arm_time = time_sec;
    }

    float previous_hand_time = 0.0f;
    for (std::size_t i = 0; i < hand_targets.size(); ++i) {
        const float time_sec = hand_targets[i].time_sec;

        if (
            !std::isfinite(time_sec) ||
            time_sec < 0.0f ||
            (i > 0 && time_sec <= previous_hand_time)
        ) {
            return 0;
        }

        previous_hand_time = time_sec;
    }

    float finish_time = 0.0f;

    if (!arm_targets.empty()) {
        finish_time = arm_targets.back().time_sec;
    }

    if (!hand_targets.empty()) {
        finish_time = std::max(finish_time, hand_targets.back().time_sec);
    }

    const std::size_t loop_count =
        static_cast<std::size_t>(std::ceil(finish_time * control_frequency_hz)) + 1;

    trajectory->reserve(loop_count);

    std::size_t arm_target_index = 0;
    float arm_segment_start_time = 0.0f;
    ArmState arm_segment_start_state = initial_arm_state;

    std::size_t hand_target_index = 0;
    HandState current_hand_state = initial_hand_state;

    for (std::size_t loop_index = 0; loop_index < loop_count; ++loop_index) {
        const float current_time =
            static_cast<float>(loop_index) / control_frequency_hz;

        while (
            arm_target_index < arm_targets.size() &&
            current_time >= arm_targets[arm_target_index].time_sec
        ) {
            arm_segment_start_time = arm_targets[arm_target_index].time_sec;
            arm_segment_start_state = arm_targets[arm_target_index].state;
            ++arm_target_index;
        }

        ArmState current_arm_state = arm_segment_start_state;

        if (arm_target_index < arm_targets.size()) {
            current_arm_state = min_jark_trajectory(
                arm_segment_start_state,
                arm_targets[arm_target_index].state,
                arm_segment_start_time,
                arm_targets[arm_target_index].time_sec,
                current_time
            );
        }

        while (
            hand_target_index < hand_targets.size() &&
            current_time >= hand_targets[hand_target_index].time_sec
        ) {
            current_hand_state = hand_targets[hand_target_index].state;
            ++hand_target_index;
        }

        trajectory->push_back(HojuState{
            current_arm_state,
            current_hand_state
        });
    }

    return trajectory->size();
}











class Hoju : public rclcpp::Node
{
public:
    Hoju() : Node("hoju_node")
    {

        rclcpp::QoS qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        qos_profile.best_effort();
        qos_profile.durability_volatile();

        can_pub = this -> create_publisher<custom_msgs::msg::CanPacket>("can_tx_line", qos_profile);

        action_server = rclcpp_action::create_server<custom_msgs::action::Hoju>(
            this,
            "hoju",
            std::bind(&Hoju::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&Hoju::handle_cancel, this, std::placeholders::_1),
            std::bind(&Hoju::handle_accepted, this, std::placeholders::_1)
        );
            
        RCLCPP_INFO(this->get_logger(), "Hoju Node Started.");
    }
    

private:

    rclcpp_action::Server<custom_msgs::action::Hoju>::SharedPtr action_server;
    rclcpp::Publisher<custom_msgs::msg::CanPacket>::SharedPtr can_pub;

    ArmMode arm_mode = ArmMode::INITIAL;

    std::mutex active_goal_mutex;
    std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::Hoju>> active_goal_handle;

    void can_ref_send(ArmState arm_state_, HandState hand_state_){

        custom_msgs::msg::CanPacket txpacket;
        txpacket.id = 0x120;
        memcpy(&txpacket.data[0], &arm_state_.z, 4);
        memcpy(&txpacket.data[4], &arm_state_.x, 4);
        memcpy(&txpacket.data[8], &arm_state_.pitch, 4);
        uint32_t hand_packet = 0;
        hand_packet |= (hand_state_.data[0] << 0);
        hand_packet |= (hand_state_.data[1] << 1);
        hand_packet |= (hand_state_.data[2] << 2);
        hand_packet |= (hand_state_.data[0] << 3);
        hand_packet |= (hand_state_.data[1] << 4);
        hand_packet |= (hand_state_.data[2] << 5);
        hand_packet |= (hand_state_.data[0] << 6);
        hand_packet |= (hand_state_.data[1] << 7);
        hand_packet |= (hand_state_.data[2] << 8);
        
        memcpy(&txpacket.data[12], &hand_packet, 4);
        can_pub -> publish(txpacket);

    }

    

    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const custom_msgs::action::Hoju::Goal> goal
    ){
        (void)uuid;
        RCLCPP_INFO(this->get_logger(), "Received goal request name : %s", goal -> action_name.c_str());

        bool goal_valid = false;

        for(size_t i = 0; i < actions_sum; i++){
            if(goal -> action_name == ActionNames[i]){
                goal_valid = true;
                break;
            }
        }

        if(goal_valid == false){
            RCLCPP_INFO(this -> get_logger(), "invalid goal name : %s", goal -> action_name.c_str());
            return rclcpp_action::GoalResponse::REJECT;
        }

        {
            std::lock_guard<std::mutex> lock(active_goal_mutex);
            if(active_goal_handle != nullptr && active_goal_handle -> is_active()){
                RCLCPP_INFO(this -> get_logger(), "another goal is already active, rejecting new goal");
                return rclcpp_action::GoalResponse::REJECT;
            }
        }

        RCLCPP_INFO(this -> get_logger(), "goal name is %s", goal -> action_name.c_str());
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;

    }



    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::Hoju>> goal_handle
    ){
        std::lock_guard<std::mutex> lock(active_goal_mutex);

        if(active_goal_handle == nullptr){
            RCLCPP_INFO(this -> get_logger(), "cancel rejected : no active goal");
            return rclcpp_action::CancelResponse::REJECT;
        }

        if(goal_handle != active_goal_handle){
            RCLCPP_INFO(this -> get_logger(), "cancel rejected : no match goal handle");
            return rclcpp_action::CancelResponse::REJECT;
        }

        RCLCPP_FATAL(
            this -> get_logger(),
            "cancel requested for active goal; shutting down hoju_node"
        );

        rclcpp::shutdown();

        return rclcpp_action::CancelResponse::ACCEPT;
    }



    void handle_accepted(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::Hoju>> goal_handle
    ){
        {
            std::lock_guard<std::mutex> lock(active_goal_mutex);
            active_goal_handle = goal_handle;
        }

        std::thread{
            [this, goal_handle](){
                this -> execute(goal_handle);
            }
        }.detach();

    }

    void execute(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::Hoju>> goal_handle
    ){
        
		std::shared_ptr<custom_msgs::action::Hoju::Feedback> feedback = 
            std::make_shared<custom_msgs::action::Hoju::Feedback>();
            
		std::shared_ptr<custom_msgs::action::Hoju::Result> result =
            std::make_shared<custom_msgs::action::Hoju::Result>();


        std::vector<HojuState> hoju_trajectorys;
        std::size_t trajectory_loop_count = 0;
        
        uint32_t action_index = actions_sum;
        for(size_t i = 0; i < actions_sum; i++){
            if(goal_handle -> get_goal() -> action_name == ActionNames[i]){
                action_index = i;
            }
        }

        if(action_index == 0){
            // GET

            if(arm_mode == ArmMode::INITIAL){
                trajectory_loop_count = generate_hoju_trajectory(
                    &hoju_trajectorys,
                    {0.0f, 0.0f, 0.0f},
                    {false, false, false},
                    {
                        {0.5f, {0.135f, 0.0f, 0.0f}},
                        {1.5f, {0.135f, 0.5f, 0.76f}},
                        {2.0f, {0.08f, 0.5f, 0.76f}},
                        {2.5f, {0.08f, 0.5f, 0.76f}},
                        {3.0f, {0.135f, 0.5f, 0.76f}},
                        {3.5f, {0.135f, 0.0f, 0.0f}},
                    },
                    {
                        {2.25f, {true, true, true}}
                    }
                );
            }
            else if(arm_mode == ArmMode::PRE_GET){
                trajectory_loop_count = generate_hoju_trajectory(
                    &hoju_trajectorys,
                    {0.135f, 0.0f, 0.0f},
                    {false, false, false},
                    {
                        {1.0f, {0.135f, 0.5f, 0.76f}},
                        {1.5f, {0.08f, 0.5f, 0.76f}},
                        {2.0f, {0.08f, 0.5f, 0.76f}},
                        {2.5f, {0.135f, 0.5f, 0.76f}},
                        {3.0f, {0.135f, 0.0f, 0.0f}},
                    },
                    {
                        {1.75f, {true, true, true}}
                    }
                );
            }
            else{
                abort_action(goal_handle, result, "no match pre section");
                return;
            }
            
        }
        else if(action_index == 1){
            // HOJU_0
            if(arm_mode == ArmMode::AFTER_GET){
                trajectory_loop_count = generate_hoju_trajectory(
                    &hoju_trajectorys,
                    {0.135f, 0.0f, 0.0f},
                    {true, true, true},
                    {
                        {0.5f, {0.135f, 0.05f, 0.0f}},
                        {1.0f, {0.0f, 0.05f, 0.0f}},
                        {1.5f, {0.0f, 0.0f, 0.0f}},
                        {2.0f, {0.0f, 0.0f, 0.0f}},
                        {2.5f, {0.135f, 0.0f, 0.0f}},
                    },
                    {
                        {1.75f, {false, true, true}}
                    }
                );
            }
            else{
                abort_action(goal_handle, result, "no match pre section");
                return;
            }

        }
        else if(action_index == 2){
            // HOJU_1

            if(arm_mode == ArmMode::AFTER_PUSU1){
                trajectory_loop_count = generate_hoju_trajectory(
                    &hoju_trajectorys,
                    {0.135f, 0.0f, 0.0f},
                    {false, true, true},
                    {
                        {0.5f, {0.135f, 0.20f, 0.0f}},
                        {1.0f, {0.0f, 0.20f, 0.0f}},
                        {1.5f, {0.0f, 0.15f, 0.0f}},
                        {2.0f, {0.0f, 0.15f, 0.0f}},
                        {2.5f, {0.135f, 0.15f, 0.0f}},
                    },
                    {
                        {1.75f, {false, false, true}}
                    }
                );
            }
            else{
                abort_action(goal_handle, result, "no match pre section");
                return;
            }

        }
        else if(action_index == 3){
            // HOJU_2
            if(arm_mode == ArmMode::AFTER_PUSH2){
                trajectory_loop_count = generate_hoju_trajectory(
                    &hoju_trajectorys,
                    {0.135f, 0.15f, 0.0f},
                    {false, false, true},
                    {
                        {0.5f, {0.135f, 0.35f, 0.0f}},
                        {1.0f, {0.0f, 0.35f, 0.0f}},
                        {1.5f, {0.0f, 0.30f, 0.0f}},
                        {2.0f, {0.0f, 0.30f, 0.0f}},
                        {2.5f, {0.135f, 0.30f, 0.0f}},
                        {3.0f, {0.135f, 0.0f, 0.0f}}
                    },
                    {
                        {1.75f, {false, false, false}}
                    }
                );
            }
            else{
                abort_action(goal_handle, result, "no match pre section");
                return;
            }

        }

        else if(action_index == 4){
            // RETURN_NORMALLY

            if(arm_mode == ArmMode::INITIAL){
                trajectory_loop_count = generate_hoju_trajectory(
                    &hoju_trajectorys,
                    {0.0f, 0.0f, 0.0f},
                    {false, false, false},
                    {
                        {0.5f, {0.135f, 0.0f, 0.0f}}
                    },
                    {
                        {0.0f, {false, false, false}}
                    }
                );
            }
            else if(arm_mode == ArmMode::AFTER_GET){
                trajectory_loop_count = generate_hoju_trajectory(
                    &hoju_trajectorys,
                    {0.135f, 0.0f, 0.0f},
                    {true, true, true},
                    {
                        {0.5f, {0.135f, 0.0f, 0.0f}}
                    },
                    {
                        {0.0f, {false, false, false}}
                    }
                );
            }
            else if(arm_mode == ArmMode::AFTER_PUSU1){
                trajectory_loop_count = generate_hoju_trajectory(
                    &hoju_trajectorys,
                    {0.135f, 0.0f, 0.0f},
                    {false, true, true},
                    {
                        {0.5f, {0.135f, 0.0f, 0.0f}}
                    },
                    {
                        {0.0f, {false, false, false}}
                    }
                );
            }
            else if(arm_mode == ArmMode::AFTER_PUSH2){
                trajectory_loop_count = generate_hoju_trajectory(
                    &hoju_trajectorys,
                    {0.135f, 0.15f, 0.0f},
                    {false, false, true},
                    {
                        {0.5f, {0.135f, 0.0f, 0.0f}}
                    },
                    {
                        {0.0f, {false, false, false}}
                    }
                );
            }
            else{
                abort_action(goal_handle, result, "no match pre section");
                return;
            }

        }
        else{
            abort_action(goal_handle, result, "invalid action index");
            return;
        }

        if(
            trajectory_loop_count == 0 ||
            trajectory_loop_count != hoju_trajectorys.size()
        ){
            abort_action(goal_handle, result, "failed to generate trajectory");
            return;
        }

        rclcpp::WallRate loop_rate(100.0);

        for (
            std::size_t loop_index = 0;
            loop_index < trajectory_loop_count;
            ++loop_index
        ) {
            if (!rclcpp::ok()) {
                clear_active_goal(goal_handle);
                return;
            }

            if (goal_handle -> is_canceling()) {
                {
                    std::lock_guard<std::mutex> lock(active_goal_mutex);

                    RCLCPP_FATAL(
                        this -> get_logger(),
                        "active goal entered canceling state; shutting down hoju_node"
                    );

                    if (active_goal_handle == goal_handle) {
                        active_goal_handle.reset();
                    }

                    if (rclcpp::ok()) {
                        rclcpp::shutdown();
                    }
                }

                return;
            }

            can_ref_send(
                hoju_trajectorys[loop_index].arm_state,
                hoju_trajectorys[loop_index].hand_state
            );

            feedback -> z = hoju_trajectorys[loop_index].arm_state.z;
            feedback -> x = hoju_trajectorys[loop_index].arm_state.x;
            feedback -> pitch = hoju_trajectorys[loop_index].arm_state.pitch;

            for (std::size_t hand_group = 0; hand_group < 3; ++hand_group) {
                for (std::size_t hand_index = 0; hand_index < 3; ++hand_index) {
                    feedback -> hand[hand_group * 3 + hand_index] =
                        hoju_trajectorys[loop_index].hand_state.data[hand_group];
                }
            }

            goal_handle -> publish_feedback(feedback);

            loop_rate.sleep();
        }

        {
            std::lock_guard<std::mutex> lock(active_goal_mutex);

            if (!rclcpp::ok() || goal_handle -> is_canceling()) {
                if (active_goal_handle == goal_handle) {
                    active_goal_handle.reset();
                }
                return;
            }

            if(action_index == 0){
                arm_mode = ArmMode::AFTER_GET;
            }
            else if(action_index == 1){
                arm_mode = ArmMode::AFTER_PUSU1;
            }
            else if(action_index == 2){
                arm_mode = ArmMode::AFTER_PUSH2;
            }
            else if(action_index == 3){
                arm_mode = ArmMode::PRE_GET;
            }
            else if(action_index == 4){
                arm_mode = ArmMode::PRE_GET;
            }

            result -> success = true;
            result -> message = "goal completed";
            result -> arm_mode = static_cast<uint8_t>(arm_mode);

            goal_handle -> succeed(result);

            if (active_goal_handle == goal_handle) {
                active_goal_handle.reset();
            }
        }

        RCLCPP_INFO(this -> get_logger(), "goal completed");
    }

    void clear_active_goal(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::Hoju>> goal_handle)
    {
        std::lock_guard<std::mutex> lock(active_goal_mutex);

        if (active_goal_handle == goal_handle) {
            active_goal_handle.reset();
        }
    }

    void abort_action(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<custom_msgs::action::Hoju>> goal_handle,
        const std::shared_ptr<custom_msgs::action::Hoju::Result> result,
        const std::string & message)
    {
        std::lock_guard<std::mutex> lock(active_goal_mutex);

        if (!rclcpp::ok() || goal_handle->is_canceling()) {
            if (active_goal_handle == goal_handle) {
                active_goal_handle.reset();
            }
            return;
        }

        // 必要なら、ここでアームの停止指令を送る
        // stop_arm();

        result->success = false;
        result->message = message;
        result->arm_mode = static_cast<uint8_t>(arm_mode);

        RCLCPP_WARN(
            this->get_logger(),
            "%s",
            message.c_str()
        );

        goal_handle->abort(result);

        if (active_goal_handle == goal_handle) {
            active_goal_handle.reset();
        }
    }




};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Hoju>());
    rclcpp::shutdown();
    return 0;
}
