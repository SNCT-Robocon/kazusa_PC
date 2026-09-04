// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:action/FollowPath.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__ACTION__DETAIL__FOLLOW_PATH__STRUCT_H_
#define CUSTOM_MSGS__ACTION__DETAIL__FOLLOW_PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'path_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/FollowPath in the package custom_msgs.
typedef struct custom_msgs__action__FollowPath_Goal
{
  rosidl_runtime_c__String path_name;
} custom_msgs__action__FollowPath_Goal;

// Struct for a sequence of custom_msgs__action__FollowPath_Goal.
typedef struct custom_msgs__action__FollowPath_Goal__Sequence
{
  custom_msgs__action__FollowPath_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__FollowPath_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/FollowPath in the package custom_msgs.
typedef struct custom_msgs__action__FollowPath_Result
{
  bool success;
  rosidl_runtime_c__String message;
} custom_msgs__action__FollowPath_Result;

// Struct for a sequence of custom_msgs__action__FollowPath_Result.
typedef struct custom_msgs__action__FollowPath_Result__Sequence
{
  custom_msgs__action__FollowPath_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__FollowPath_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'path_name'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/FollowPath in the package custom_msgs.
typedef struct custom_msgs__action__FollowPath_Feedback
{
  rosidl_runtime_c__String path_name;
  uint32_t index;
  float ref_x;
  float ref_y;
  float ref_yaw;
  float now_x;
  float now_y;
  float now_yaw;
} custom_msgs__action__FollowPath_Feedback;

// Struct for a sequence of custom_msgs__action__FollowPath_Feedback.
typedef struct custom_msgs__action__FollowPath_Feedback__Sequence
{
  custom_msgs__action__FollowPath_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__FollowPath_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "custom_msgs/action/detail/follow_path__struct.h"

/// Struct defined in action/FollowPath in the package custom_msgs.
typedef struct custom_msgs__action__FollowPath_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_msgs__action__FollowPath_Goal goal;
} custom_msgs__action__FollowPath_SendGoal_Request;

// Struct for a sequence of custom_msgs__action__FollowPath_SendGoal_Request.
typedef struct custom_msgs__action__FollowPath_SendGoal_Request__Sequence
{
  custom_msgs__action__FollowPath_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__FollowPath_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/FollowPath in the package custom_msgs.
typedef struct custom_msgs__action__FollowPath_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} custom_msgs__action__FollowPath_SendGoal_Response;

// Struct for a sequence of custom_msgs__action__FollowPath_SendGoal_Response.
typedef struct custom_msgs__action__FollowPath_SendGoal_Response__Sequence
{
  custom_msgs__action__FollowPath_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__FollowPath_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/FollowPath in the package custom_msgs.
typedef struct custom_msgs__action__FollowPath_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} custom_msgs__action__FollowPath_GetResult_Request;

// Struct for a sequence of custom_msgs__action__FollowPath_GetResult_Request.
typedef struct custom_msgs__action__FollowPath_GetResult_Request__Sequence
{
  custom_msgs__action__FollowPath_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__FollowPath_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "custom_msgs/action/detail/follow_path__struct.h"

/// Struct defined in action/FollowPath in the package custom_msgs.
typedef struct custom_msgs__action__FollowPath_GetResult_Response
{
  int8_t status;
  custom_msgs__action__FollowPath_Result result;
} custom_msgs__action__FollowPath_GetResult_Response;

// Struct for a sequence of custom_msgs__action__FollowPath_GetResult_Response.
typedef struct custom_msgs__action__FollowPath_GetResult_Response__Sequence
{
  custom_msgs__action__FollowPath_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__FollowPath_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "custom_msgs/action/detail/follow_path__struct.h"

/// Struct defined in action/FollowPath in the package custom_msgs.
typedef struct custom_msgs__action__FollowPath_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_msgs__action__FollowPath_Feedback feedback;
} custom_msgs__action__FollowPath_FeedbackMessage;

// Struct for a sequence of custom_msgs__action__FollowPath_FeedbackMessage.
typedef struct custom_msgs__action__FollowPath_FeedbackMessage__Sequence
{
  custom_msgs__action__FollowPath_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__FollowPath_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__ACTION__DETAIL__FOLLOW_PATH__STRUCT_H_
