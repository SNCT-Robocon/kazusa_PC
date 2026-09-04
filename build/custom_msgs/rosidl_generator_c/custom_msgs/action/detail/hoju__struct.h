// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:action/Hoju.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__ACTION__DETAIL__HOJU__STRUCT_H_
#define CUSTOM_MSGS__ACTION__DETAIL__HOJU__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'action_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Hoju in the package custom_msgs.
typedef struct custom_msgs__action__Hoju_Goal
{
  rosidl_runtime_c__String action_name;
} custom_msgs__action__Hoju_Goal;

// Struct for a sequence of custom_msgs__action__Hoju_Goal.
typedef struct custom_msgs__action__Hoju_Goal__Sequence
{
  custom_msgs__action__Hoju_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__Hoju_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Hoju in the package custom_msgs.
typedef struct custom_msgs__action__Hoju_Result
{
  /// Result
  bool success;
  rosidl_runtime_c__String message;
  uint8_t arm_mode;
} custom_msgs__action__Hoju_Result;

// Struct for a sequence of custom_msgs__action__Hoju_Result.
typedef struct custom_msgs__action__Hoju_Result__Sequence
{
  custom_msgs__action__Hoju_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__Hoju_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Hoju in the package custom_msgs.
typedef struct custom_msgs__action__Hoju_Feedback
{
  /// Feedback
  float z;
  float x;
  float pitch;
  bool hand[9];
} custom_msgs__action__Hoju_Feedback;

// Struct for a sequence of custom_msgs__action__Hoju_Feedback.
typedef struct custom_msgs__action__Hoju_Feedback__Sequence
{
  custom_msgs__action__Hoju_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__Hoju_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "custom_msgs/action/detail/hoju__struct.h"

/// Struct defined in action/Hoju in the package custom_msgs.
typedef struct custom_msgs__action__Hoju_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_msgs__action__Hoju_Goal goal;
} custom_msgs__action__Hoju_SendGoal_Request;

// Struct for a sequence of custom_msgs__action__Hoju_SendGoal_Request.
typedef struct custom_msgs__action__Hoju_SendGoal_Request__Sequence
{
  custom_msgs__action__Hoju_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__Hoju_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Hoju in the package custom_msgs.
typedef struct custom_msgs__action__Hoju_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} custom_msgs__action__Hoju_SendGoal_Response;

// Struct for a sequence of custom_msgs__action__Hoju_SendGoal_Response.
typedef struct custom_msgs__action__Hoju_SendGoal_Response__Sequence
{
  custom_msgs__action__Hoju_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__Hoju_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Hoju in the package custom_msgs.
typedef struct custom_msgs__action__Hoju_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} custom_msgs__action__Hoju_GetResult_Request;

// Struct for a sequence of custom_msgs__action__Hoju_GetResult_Request.
typedef struct custom_msgs__action__Hoju_GetResult_Request__Sequence
{
  custom_msgs__action__Hoju_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__Hoju_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "custom_msgs/action/detail/hoju__struct.h"

/// Struct defined in action/Hoju in the package custom_msgs.
typedef struct custom_msgs__action__Hoju_GetResult_Response
{
  int8_t status;
  custom_msgs__action__Hoju_Result result;
} custom_msgs__action__Hoju_GetResult_Response;

// Struct for a sequence of custom_msgs__action__Hoju_GetResult_Response.
typedef struct custom_msgs__action__Hoju_GetResult_Response__Sequence
{
  custom_msgs__action__Hoju_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__Hoju_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "custom_msgs/action/detail/hoju__struct.h"

/// Struct defined in action/Hoju in the package custom_msgs.
typedef struct custom_msgs__action__Hoju_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_msgs__action__Hoju_Feedback feedback;
} custom_msgs__action__Hoju_FeedbackMessage;

// Struct for a sequence of custom_msgs__action__Hoju_FeedbackMessage.
typedef struct custom_msgs__action__Hoju_FeedbackMessage__Sequence
{
  custom_msgs__action__Hoju_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__action__Hoju_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__ACTION__DETAIL__HOJU__STRUCT_H_
