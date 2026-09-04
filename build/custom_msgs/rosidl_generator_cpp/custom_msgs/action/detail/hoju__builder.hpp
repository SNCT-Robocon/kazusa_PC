// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:action/Hoju.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__ACTION__DETAIL__HOJU__BUILDER_HPP_
#define CUSTOM_MSGS__ACTION__DETAIL__HOJU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/action/detail/hoju__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_Hoju_Goal_action_name
{
public:
  Init_Hoju_Goal_action_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msgs::action::Hoju_Goal action_name(::custom_msgs::action::Hoju_Goal::_action_name_type arg)
  {
    msg_.action_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::Hoju_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::Hoju_Goal>()
{
  return custom_msgs::action::builder::Init_Hoju_Goal_action_name();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_Hoju_Result_arm_mode
{
public:
  explicit Init_Hoju_Result_arm_mode(::custom_msgs::action::Hoju_Result & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::Hoju_Result arm_mode(::custom_msgs::action::Hoju_Result::_arm_mode_type arg)
  {
    msg_.arm_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::Hoju_Result msg_;
};

class Init_Hoju_Result_message
{
public:
  explicit Init_Hoju_Result_message(::custom_msgs::action::Hoju_Result & msg)
  : msg_(msg)
  {}
  Init_Hoju_Result_arm_mode message(::custom_msgs::action::Hoju_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_Hoju_Result_arm_mode(msg_);
  }

private:
  ::custom_msgs::action::Hoju_Result msg_;
};

class Init_Hoju_Result_success
{
public:
  Init_Hoju_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Hoju_Result_message success(::custom_msgs::action::Hoju_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Hoju_Result_message(msg_);
  }

private:
  ::custom_msgs::action::Hoju_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::Hoju_Result>()
{
  return custom_msgs::action::builder::Init_Hoju_Result_success();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_Hoju_Feedback_hand
{
public:
  explicit Init_Hoju_Feedback_hand(::custom_msgs::action::Hoju_Feedback & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::Hoju_Feedback hand(::custom_msgs::action::Hoju_Feedback::_hand_type arg)
  {
    msg_.hand = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::Hoju_Feedback msg_;
};

class Init_Hoju_Feedback_pitch
{
public:
  explicit Init_Hoju_Feedback_pitch(::custom_msgs::action::Hoju_Feedback & msg)
  : msg_(msg)
  {}
  Init_Hoju_Feedback_hand pitch(::custom_msgs::action::Hoju_Feedback::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Hoju_Feedback_hand(msg_);
  }

private:
  ::custom_msgs::action::Hoju_Feedback msg_;
};

class Init_Hoju_Feedback_x
{
public:
  explicit Init_Hoju_Feedback_x(::custom_msgs::action::Hoju_Feedback & msg)
  : msg_(msg)
  {}
  Init_Hoju_Feedback_pitch x(::custom_msgs::action::Hoju_Feedback::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Hoju_Feedback_pitch(msg_);
  }

private:
  ::custom_msgs::action::Hoju_Feedback msg_;
};

class Init_Hoju_Feedback_z
{
public:
  Init_Hoju_Feedback_z()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Hoju_Feedback_x z(::custom_msgs::action::Hoju_Feedback::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Hoju_Feedback_x(msg_);
  }

private:
  ::custom_msgs::action::Hoju_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::Hoju_Feedback>()
{
  return custom_msgs::action::builder::Init_Hoju_Feedback_z();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_Hoju_SendGoal_Request_goal
{
public:
  explicit Init_Hoju_SendGoal_Request_goal(::custom_msgs::action::Hoju_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::Hoju_SendGoal_Request goal(::custom_msgs::action::Hoju_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::Hoju_SendGoal_Request msg_;
};

class Init_Hoju_SendGoal_Request_goal_id
{
public:
  Init_Hoju_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Hoju_SendGoal_Request_goal goal_id(::custom_msgs::action::Hoju_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Hoju_SendGoal_Request_goal(msg_);
  }

private:
  ::custom_msgs::action::Hoju_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::Hoju_SendGoal_Request>()
{
  return custom_msgs::action::builder::Init_Hoju_SendGoal_Request_goal_id();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_Hoju_SendGoal_Response_stamp
{
public:
  explicit Init_Hoju_SendGoal_Response_stamp(::custom_msgs::action::Hoju_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::Hoju_SendGoal_Response stamp(::custom_msgs::action::Hoju_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::Hoju_SendGoal_Response msg_;
};

class Init_Hoju_SendGoal_Response_accepted
{
public:
  Init_Hoju_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Hoju_SendGoal_Response_stamp accepted(::custom_msgs::action::Hoju_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Hoju_SendGoal_Response_stamp(msg_);
  }

private:
  ::custom_msgs::action::Hoju_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::Hoju_SendGoal_Response>()
{
  return custom_msgs::action::builder::Init_Hoju_SendGoal_Response_accepted();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_Hoju_GetResult_Request_goal_id
{
public:
  Init_Hoju_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msgs::action::Hoju_GetResult_Request goal_id(::custom_msgs::action::Hoju_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::Hoju_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::Hoju_GetResult_Request>()
{
  return custom_msgs::action::builder::Init_Hoju_GetResult_Request_goal_id();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_Hoju_GetResult_Response_result
{
public:
  explicit Init_Hoju_GetResult_Response_result(::custom_msgs::action::Hoju_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::Hoju_GetResult_Response result(::custom_msgs::action::Hoju_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::Hoju_GetResult_Response msg_;
};

class Init_Hoju_GetResult_Response_status
{
public:
  Init_Hoju_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Hoju_GetResult_Response_result status(::custom_msgs::action::Hoju_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Hoju_GetResult_Response_result(msg_);
  }

private:
  ::custom_msgs::action::Hoju_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::Hoju_GetResult_Response>()
{
  return custom_msgs::action::builder::Init_Hoju_GetResult_Response_status();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_Hoju_FeedbackMessage_feedback
{
public:
  explicit Init_Hoju_FeedbackMessage_feedback(::custom_msgs::action::Hoju_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::Hoju_FeedbackMessage feedback(::custom_msgs::action::Hoju_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::Hoju_FeedbackMessage msg_;
};

class Init_Hoju_FeedbackMessage_goal_id
{
public:
  Init_Hoju_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Hoju_FeedbackMessage_feedback goal_id(::custom_msgs::action::Hoju_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Hoju_FeedbackMessage_feedback(msg_);
  }

private:
  ::custom_msgs::action::Hoju_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::Hoju_FeedbackMessage>()
{
  return custom_msgs::action::builder::Init_Hoju_FeedbackMessage_goal_id();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__ACTION__DETAIL__HOJU__BUILDER_HPP_
