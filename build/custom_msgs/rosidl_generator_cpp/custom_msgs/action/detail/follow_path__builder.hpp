// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:action/FollowPath.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__ACTION__DETAIL__FOLLOW_PATH__BUILDER_HPP_
#define CUSTOM_MSGS__ACTION__DETAIL__FOLLOW_PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/action/detail/follow_path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_FollowPath_Goal_path_name
{
public:
  Init_FollowPath_Goal_path_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msgs::action::FollowPath_Goal path_name(::custom_msgs::action::FollowPath_Goal::_path_name_type arg)
  {
    msg_.path_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::FollowPath_Goal>()
{
  return custom_msgs::action::builder::Init_FollowPath_Goal_path_name();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_FollowPath_Result_message
{
public:
  explicit Init_FollowPath_Result_message(::custom_msgs::action::FollowPath_Result & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::FollowPath_Result message(::custom_msgs::action::FollowPath_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_Result msg_;
};

class Init_FollowPath_Result_success
{
public:
  Init_FollowPath_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowPath_Result_message success(::custom_msgs::action::FollowPath_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_FollowPath_Result_message(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::FollowPath_Result>()
{
  return custom_msgs::action::builder::Init_FollowPath_Result_success();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_FollowPath_Feedback_now_yaw
{
public:
  explicit Init_FollowPath_Feedback_now_yaw(::custom_msgs::action::FollowPath_Feedback & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::FollowPath_Feedback now_yaw(::custom_msgs::action::FollowPath_Feedback::_now_yaw_type arg)
  {
    msg_.now_yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_Feedback msg_;
};

class Init_FollowPath_Feedback_now_y
{
public:
  explicit Init_FollowPath_Feedback_now_y(::custom_msgs::action::FollowPath_Feedback & msg)
  : msg_(msg)
  {}
  Init_FollowPath_Feedback_now_yaw now_y(::custom_msgs::action::FollowPath_Feedback::_now_y_type arg)
  {
    msg_.now_y = std::move(arg);
    return Init_FollowPath_Feedback_now_yaw(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_Feedback msg_;
};

class Init_FollowPath_Feedback_now_x
{
public:
  explicit Init_FollowPath_Feedback_now_x(::custom_msgs::action::FollowPath_Feedback & msg)
  : msg_(msg)
  {}
  Init_FollowPath_Feedback_now_y now_x(::custom_msgs::action::FollowPath_Feedback::_now_x_type arg)
  {
    msg_.now_x = std::move(arg);
    return Init_FollowPath_Feedback_now_y(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_Feedback msg_;
};

class Init_FollowPath_Feedback_ref_yaw
{
public:
  explicit Init_FollowPath_Feedback_ref_yaw(::custom_msgs::action::FollowPath_Feedback & msg)
  : msg_(msg)
  {}
  Init_FollowPath_Feedback_now_x ref_yaw(::custom_msgs::action::FollowPath_Feedback::_ref_yaw_type arg)
  {
    msg_.ref_yaw = std::move(arg);
    return Init_FollowPath_Feedback_now_x(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_Feedback msg_;
};

class Init_FollowPath_Feedback_ref_y
{
public:
  explicit Init_FollowPath_Feedback_ref_y(::custom_msgs::action::FollowPath_Feedback & msg)
  : msg_(msg)
  {}
  Init_FollowPath_Feedback_ref_yaw ref_y(::custom_msgs::action::FollowPath_Feedback::_ref_y_type arg)
  {
    msg_.ref_y = std::move(arg);
    return Init_FollowPath_Feedback_ref_yaw(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_Feedback msg_;
};

class Init_FollowPath_Feedback_ref_x
{
public:
  explicit Init_FollowPath_Feedback_ref_x(::custom_msgs::action::FollowPath_Feedback & msg)
  : msg_(msg)
  {}
  Init_FollowPath_Feedback_ref_y ref_x(::custom_msgs::action::FollowPath_Feedback::_ref_x_type arg)
  {
    msg_.ref_x = std::move(arg);
    return Init_FollowPath_Feedback_ref_y(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_Feedback msg_;
};

class Init_FollowPath_Feedback_index
{
public:
  explicit Init_FollowPath_Feedback_index(::custom_msgs::action::FollowPath_Feedback & msg)
  : msg_(msg)
  {}
  Init_FollowPath_Feedback_ref_x index(::custom_msgs::action::FollowPath_Feedback::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_FollowPath_Feedback_ref_x(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_Feedback msg_;
};

class Init_FollowPath_Feedback_path_name
{
public:
  Init_FollowPath_Feedback_path_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowPath_Feedback_index path_name(::custom_msgs::action::FollowPath_Feedback::_path_name_type arg)
  {
    msg_.path_name = std::move(arg);
    return Init_FollowPath_Feedback_index(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::FollowPath_Feedback>()
{
  return custom_msgs::action::builder::Init_FollowPath_Feedback_path_name();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_FollowPath_SendGoal_Request_goal
{
public:
  explicit Init_FollowPath_SendGoal_Request_goal(::custom_msgs::action::FollowPath_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::FollowPath_SendGoal_Request goal(::custom_msgs::action::FollowPath_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_SendGoal_Request msg_;
};

class Init_FollowPath_SendGoal_Request_goal_id
{
public:
  Init_FollowPath_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowPath_SendGoal_Request_goal goal_id(::custom_msgs::action::FollowPath_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_FollowPath_SendGoal_Request_goal(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::FollowPath_SendGoal_Request>()
{
  return custom_msgs::action::builder::Init_FollowPath_SendGoal_Request_goal_id();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_FollowPath_SendGoal_Response_stamp
{
public:
  explicit Init_FollowPath_SendGoal_Response_stamp(::custom_msgs::action::FollowPath_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::FollowPath_SendGoal_Response stamp(::custom_msgs::action::FollowPath_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_SendGoal_Response msg_;
};

class Init_FollowPath_SendGoal_Response_accepted
{
public:
  Init_FollowPath_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowPath_SendGoal_Response_stamp accepted(::custom_msgs::action::FollowPath_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_FollowPath_SendGoal_Response_stamp(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::FollowPath_SendGoal_Response>()
{
  return custom_msgs::action::builder::Init_FollowPath_SendGoal_Response_accepted();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_FollowPath_GetResult_Request_goal_id
{
public:
  Init_FollowPath_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msgs::action::FollowPath_GetResult_Request goal_id(::custom_msgs::action::FollowPath_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::FollowPath_GetResult_Request>()
{
  return custom_msgs::action::builder::Init_FollowPath_GetResult_Request_goal_id();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_FollowPath_GetResult_Response_result
{
public:
  explicit Init_FollowPath_GetResult_Response_result(::custom_msgs::action::FollowPath_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::FollowPath_GetResult_Response result(::custom_msgs::action::FollowPath_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_GetResult_Response msg_;
};

class Init_FollowPath_GetResult_Response_status
{
public:
  Init_FollowPath_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowPath_GetResult_Response_result status(::custom_msgs::action::FollowPath_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_FollowPath_GetResult_Response_result(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::FollowPath_GetResult_Response>()
{
  return custom_msgs::action::builder::Init_FollowPath_GetResult_Response_status();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace action
{

namespace builder
{

class Init_FollowPath_FeedbackMessage_feedback
{
public:
  explicit Init_FollowPath_FeedbackMessage_feedback(::custom_msgs::action::FollowPath_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::custom_msgs::action::FollowPath_FeedbackMessage feedback(::custom_msgs::action::FollowPath_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_FeedbackMessage msg_;
};

class Init_FollowPath_FeedbackMessage_goal_id
{
public:
  Init_FollowPath_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowPath_FeedbackMessage_feedback goal_id(::custom_msgs::action::FollowPath_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_FollowPath_FeedbackMessage_feedback(msg_);
  }

private:
  ::custom_msgs::action::FollowPath_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::action::FollowPath_FeedbackMessage>()
{
  return custom_msgs::action::builder::Init_FollowPath_FeedbackMessage_goal_id();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__ACTION__DETAIL__FOLLOW_PATH__BUILDER_HPP_
