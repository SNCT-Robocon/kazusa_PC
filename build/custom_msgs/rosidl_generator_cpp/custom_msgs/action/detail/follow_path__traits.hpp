// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:action/FollowPath.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__ACTION__DETAIL__FOLLOW_PATH__TRAITS_HPP_
#define CUSTOM_MSGS__ACTION__DETAIL__FOLLOW_PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/action/detail/follow_path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowPath_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: path_name
  {
    out << "path_name: ";
    rosidl_generator_traits::value_to_yaml(msg.path_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowPath_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: path_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path_name: ";
    rosidl_generator_traits::value_to_yaml(msg.path_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowPath_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::action::FollowPath_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::action::FollowPath_Goal & msg)
{
  return custom_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::action::FollowPath_Goal>()
{
  return "custom_msgs::action::FollowPath_Goal";
}

template<>
inline const char * name<custom_msgs::action::FollowPath_Goal>()
{
  return "custom_msgs/action/FollowPath_Goal";
}

template<>
struct has_fixed_size<custom_msgs::action::FollowPath_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::action::FollowPath_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::action::FollowPath_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowPath_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowPath_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowPath_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::action::FollowPath_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::action::FollowPath_Result & msg)
{
  return custom_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::action::FollowPath_Result>()
{
  return "custom_msgs::action::FollowPath_Result";
}

template<>
inline const char * name<custom_msgs::action::FollowPath_Result>()
{
  return "custom_msgs/action/FollowPath_Result";
}

template<>
struct has_fixed_size<custom_msgs::action::FollowPath_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::action::FollowPath_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::action::FollowPath_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowPath_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: path_name
  {
    out << "path_name: ";
    rosidl_generator_traits::value_to_yaml(msg.path_name, out);
    out << ", ";
  }

  // member: index
  {
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << ", ";
  }

  // member: ref_x
  {
    out << "ref_x: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_x, out);
    out << ", ";
  }

  // member: ref_y
  {
    out << "ref_y: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_y, out);
    out << ", ";
  }

  // member: ref_yaw
  {
    out << "ref_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_yaw, out);
    out << ", ";
  }

  // member: now_x
  {
    out << "now_x: ";
    rosidl_generator_traits::value_to_yaml(msg.now_x, out);
    out << ", ";
  }

  // member: now_y
  {
    out << "now_y: ";
    rosidl_generator_traits::value_to_yaml(msg.now_y, out);
    out << ", ";
  }

  // member: now_yaw
  {
    out << "now_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.now_yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowPath_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: path_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path_name: ";
    rosidl_generator_traits::value_to_yaml(msg.path_name, out);
    out << "\n";
  }

  // member: index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << "\n";
  }

  // member: ref_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ref_x: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_x, out);
    out << "\n";
  }

  // member: ref_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ref_y: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_y, out);
    out << "\n";
  }

  // member: ref_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ref_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_yaw, out);
    out << "\n";
  }

  // member: now_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "now_x: ";
    rosidl_generator_traits::value_to_yaml(msg.now_x, out);
    out << "\n";
  }

  // member: now_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "now_y: ";
    rosidl_generator_traits::value_to_yaml(msg.now_y, out);
    out << "\n";
  }

  // member: now_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "now_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.now_yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowPath_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::action::FollowPath_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::action::FollowPath_Feedback & msg)
{
  return custom_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::action::FollowPath_Feedback>()
{
  return "custom_msgs::action::FollowPath_Feedback";
}

template<>
inline const char * name<custom_msgs::action::FollowPath_Feedback>()
{
  return "custom_msgs/action/FollowPath_Feedback";
}

template<>
struct has_fixed_size<custom_msgs::action::FollowPath_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::action::FollowPath_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::action::FollowPath_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "custom_msgs/action/detail/follow_path__traits.hpp"

namespace custom_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowPath_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowPath_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowPath_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::action::FollowPath_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::action::FollowPath_SendGoal_Request & msg)
{
  return custom_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::action::FollowPath_SendGoal_Request>()
{
  return "custom_msgs::action::FollowPath_SendGoal_Request";
}

template<>
inline const char * name<custom_msgs::action::FollowPath_SendGoal_Request>()
{
  return "custom_msgs/action/FollowPath_SendGoal_Request";
}

template<>
struct has_fixed_size<custom_msgs::action::FollowPath_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<custom_msgs::action::FollowPath_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<custom_msgs::action::FollowPath_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<custom_msgs::action::FollowPath_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<custom_msgs::action::FollowPath_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace custom_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowPath_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowPath_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowPath_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::action::FollowPath_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::action::FollowPath_SendGoal_Response & msg)
{
  return custom_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::action::FollowPath_SendGoal_Response>()
{
  return "custom_msgs::action::FollowPath_SendGoal_Response";
}

template<>
inline const char * name<custom_msgs::action::FollowPath_SendGoal_Response>()
{
  return "custom_msgs/action/FollowPath_SendGoal_Response";
}

template<>
struct has_fixed_size<custom_msgs::action::FollowPath_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<custom_msgs::action::FollowPath_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<custom_msgs::action::FollowPath_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msgs::action::FollowPath_SendGoal>()
{
  return "custom_msgs::action::FollowPath_SendGoal";
}

template<>
inline const char * name<custom_msgs::action::FollowPath_SendGoal>()
{
  return "custom_msgs/action/FollowPath_SendGoal";
}

template<>
struct has_fixed_size<custom_msgs::action::FollowPath_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_msgs::action::FollowPath_SendGoal_Request>::value &&
    has_fixed_size<custom_msgs::action::FollowPath_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_msgs::action::FollowPath_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_msgs::action::FollowPath_SendGoal_Request>::value &&
    has_bounded_size<custom_msgs::action::FollowPath_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<custom_msgs::action::FollowPath_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<custom_msgs::action::FollowPath_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_msgs::action::FollowPath_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace custom_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowPath_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowPath_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowPath_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::action::FollowPath_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::action::FollowPath_GetResult_Request & msg)
{
  return custom_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::action::FollowPath_GetResult_Request>()
{
  return "custom_msgs::action::FollowPath_GetResult_Request";
}

template<>
inline const char * name<custom_msgs::action::FollowPath_GetResult_Request>()
{
  return "custom_msgs/action/FollowPath_GetResult_Request";
}

template<>
struct has_fixed_size<custom_msgs::action::FollowPath_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<custom_msgs::action::FollowPath_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<custom_msgs::action::FollowPath_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "custom_msgs/action/detail/follow_path__traits.hpp"

namespace custom_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowPath_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowPath_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowPath_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::action::FollowPath_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::action::FollowPath_GetResult_Response & msg)
{
  return custom_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::action::FollowPath_GetResult_Response>()
{
  return "custom_msgs::action::FollowPath_GetResult_Response";
}

template<>
inline const char * name<custom_msgs::action::FollowPath_GetResult_Response>()
{
  return "custom_msgs/action/FollowPath_GetResult_Response";
}

template<>
struct has_fixed_size<custom_msgs::action::FollowPath_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<custom_msgs::action::FollowPath_Result>::value> {};

template<>
struct has_bounded_size<custom_msgs::action::FollowPath_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<custom_msgs::action::FollowPath_Result>::value> {};

template<>
struct is_message<custom_msgs::action::FollowPath_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msgs::action::FollowPath_GetResult>()
{
  return "custom_msgs::action::FollowPath_GetResult";
}

template<>
inline const char * name<custom_msgs::action::FollowPath_GetResult>()
{
  return "custom_msgs/action/FollowPath_GetResult";
}

template<>
struct has_fixed_size<custom_msgs::action::FollowPath_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_msgs::action::FollowPath_GetResult_Request>::value &&
    has_fixed_size<custom_msgs::action::FollowPath_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_msgs::action::FollowPath_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_msgs::action::FollowPath_GetResult_Request>::value &&
    has_bounded_size<custom_msgs::action::FollowPath_GetResult_Response>::value
  >
{
};

template<>
struct is_service<custom_msgs::action::FollowPath_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<custom_msgs::action::FollowPath_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_msgs::action::FollowPath_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "custom_msgs/action/detail/follow_path__traits.hpp"

namespace custom_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowPath_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowPath_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowPath_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::action::FollowPath_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::action::FollowPath_FeedbackMessage & msg)
{
  return custom_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::action::FollowPath_FeedbackMessage>()
{
  return "custom_msgs::action::FollowPath_FeedbackMessage";
}

template<>
inline const char * name<custom_msgs::action::FollowPath_FeedbackMessage>()
{
  return "custom_msgs/action/FollowPath_FeedbackMessage";
}

template<>
struct has_fixed_size<custom_msgs::action::FollowPath_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<custom_msgs::action::FollowPath_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<custom_msgs::action::FollowPath_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<custom_msgs::action::FollowPath_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<custom_msgs::action::FollowPath_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<custom_msgs::action::FollowPath>
  : std::true_type
{
};

template<>
struct is_action_goal<custom_msgs::action::FollowPath_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<custom_msgs::action::FollowPath_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<custom_msgs::action::FollowPath_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // CUSTOM_MSGS__ACTION__DETAIL__FOLLOW_PATH__TRAITS_HPP_
