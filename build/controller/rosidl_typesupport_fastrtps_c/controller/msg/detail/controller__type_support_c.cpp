// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from controller:msg/Controller.idl
// generated code does not contain a copyright notice
#include "controller/msg/detail/controller__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "controller/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "controller/msg/detail/controller__struct.h"
#include "controller/msg/detail/controller__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // column1, column2, column3, fieldcolor, mode
#include "rosidl_runtime_c/string_functions.h"  // column1, column2, column3, fieldcolor, mode

// forward declare type support functions


using _Controller__ros_msg_type = controller__msg__Controller;

static bool _Controller__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Controller__ros_msg_type * ros_message = static_cast<const _Controller__ros_msg_type *>(untyped_ros_message);
  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: theta
  {
    cdr << ros_message->theta;
  }

  // Field name: hata_turn_x
  {
    cdr << ros_message->hata_turn_x;
  }

  // Field name: hata_turn_y
  {
    cdr << ros_message->hata_turn_y;
  }

  // Field name: hata_turn_theta
  {
    cdr << ros_message->hata_turn_theta;
  }

  // Field name: baketu_turn_x
  {
    cdr << ros_message->baketu_turn_x;
  }

  // Field name: baketu_turn_y
  {
    cdr << ros_message->baketu_turn_y;
  }

  // Field name: baketu_turn_theta
  {
    cdr << ros_message->baketu_turn_theta;
  }

  // Field name: hoju_turn_x
  {
    cdr << ros_message->hoju_turn_x;
  }

  // Field name: hoju_turn_y
  {
    cdr << ros_message->hoju_turn_y;
  }

  // Field name: hoju_turn_theta
  {
    cdr << ros_message->hoju_turn_theta;
  }

  // Field name: hata_speed
  {
    cdr << ros_message->hata_speed;
  }

  // Field name: baketu_speed
  {
    cdr << ros_message->baketu_speed;
  }

  // Field name: fieldcolor
  {
    const rosidl_runtime_c__String * str = &ros_message->fieldcolor;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: dengen
  {
    cdr << (ros_message->dengen ? true : false);
  }

  // Field name: mode
  {
    const rosidl_runtime_c__String * str = &ros_message->mode;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: column1
  {
    const rosidl_runtime_c__String * str = &ros_message->column1;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: column2
  {
    const rosidl_runtime_c__String * str = &ros_message->column2;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: column3
  {
    const rosidl_runtime_c__String * str = &ros_message->column3;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: execute
  {
    cdr << (ros_message->execute ? true : false);
  }

  // Field name: refill
  {
    cdr << (ros_message->refill ? true : false);
  }

  // Field name: reload1
  {
    cdr << (ros_message->reload1 ? true : false);
  }

  // Field name: reload2
  {
    cdr << (ros_message->reload2 ? true : false);
  }

  // Field name: reload3
  {
    cdr << (ros_message->reload3 ? true : false);
  }

  // Field name: firehata
  {
    cdr << (ros_message->firehata ? true : false);
  }

  // Field name: firebaketu
  {
    cdr << (ros_message->firebaketu ? true : false);
  }

  // Field name: hojuposition
  {
    cdr << (ros_message->hojuposition ? true : false);
  }

  // Field name: left
  {
    cdr << (ros_message->left ? true : false);
  }

  // Field name: right
  {
    cdr << (ros_message->right ? true : false);
  }

  // Field name: up
  {
    cdr << (ros_message->up ? true : false);
  }

  // Field name: down
  {
    cdr << (ros_message->down ? true : false);
  }

  // Field name: circle
  {
    cdr << (ros_message->circle ? true : false);
  }

  // Field name: triangle
  {
    cdr << (ros_message->triangle ? true : false);
  }

  // Field name: square
  {
    cdr << (ros_message->square ? true : false);
  }

  // Field name: cross
  {
    cdr << (ros_message->cross ? true : false);
  }

  // Field name: l1
  {
    cdr << (ros_message->l1 ? true : false);
  }

  // Field name: l2
  {
    cdr << (ros_message->l2 ? true : false);
  }

  // Field name: r1
  {
    cdr << (ros_message->r1 ? true : false);
  }

  // Field name: r2
  {
    cdr << (ros_message->r2 ? true : false);
  }

  return true;
}

static bool _Controller__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Controller__ros_msg_type * ros_message = static_cast<_Controller__ros_msg_type *>(untyped_ros_message);
  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: theta
  {
    cdr >> ros_message->theta;
  }

  // Field name: hata_turn_x
  {
    cdr >> ros_message->hata_turn_x;
  }

  // Field name: hata_turn_y
  {
    cdr >> ros_message->hata_turn_y;
  }

  // Field name: hata_turn_theta
  {
    cdr >> ros_message->hata_turn_theta;
  }

  // Field name: baketu_turn_x
  {
    cdr >> ros_message->baketu_turn_x;
  }

  // Field name: baketu_turn_y
  {
    cdr >> ros_message->baketu_turn_y;
  }

  // Field name: baketu_turn_theta
  {
    cdr >> ros_message->baketu_turn_theta;
  }

  // Field name: hoju_turn_x
  {
    cdr >> ros_message->hoju_turn_x;
  }

  // Field name: hoju_turn_y
  {
    cdr >> ros_message->hoju_turn_y;
  }

  // Field name: hoju_turn_theta
  {
    cdr >> ros_message->hoju_turn_theta;
  }

  // Field name: hata_speed
  {
    cdr >> ros_message->hata_speed;
  }

  // Field name: baketu_speed
  {
    cdr >> ros_message->baketu_speed;
  }

  // Field name: fieldcolor
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->fieldcolor.data) {
      rosidl_runtime_c__String__init(&ros_message->fieldcolor);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->fieldcolor,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'fieldcolor'\n");
      return false;
    }
  }

  // Field name: dengen
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->dengen = tmp ? true : false;
  }

  // Field name: mode
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->mode.data) {
      rosidl_runtime_c__String__init(&ros_message->mode);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->mode,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'mode'\n");
      return false;
    }
  }

  // Field name: column1
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->column1.data) {
      rosidl_runtime_c__String__init(&ros_message->column1);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->column1,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'column1'\n");
      return false;
    }
  }

  // Field name: column2
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->column2.data) {
      rosidl_runtime_c__String__init(&ros_message->column2);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->column2,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'column2'\n");
      return false;
    }
  }

  // Field name: column3
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->column3.data) {
      rosidl_runtime_c__String__init(&ros_message->column3);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->column3,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'column3'\n");
      return false;
    }
  }

  // Field name: execute
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->execute = tmp ? true : false;
  }

  // Field name: refill
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->refill = tmp ? true : false;
  }

  // Field name: reload1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->reload1 = tmp ? true : false;
  }

  // Field name: reload2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->reload2 = tmp ? true : false;
  }

  // Field name: reload3
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->reload3 = tmp ? true : false;
  }

  // Field name: firehata
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->firehata = tmp ? true : false;
  }

  // Field name: firebaketu
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->firebaketu = tmp ? true : false;
  }

  // Field name: hojuposition
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hojuposition = tmp ? true : false;
  }

  // Field name: left
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->left = tmp ? true : false;
  }

  // Field name: right
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->right = tmp ? true : false;
  }

  // Field name: up
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->up = tmp ? true : false;
  }

  // Field name: down
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->down = tmp ? true : false;
  }

  // Field name: circle
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->circle = tmp ? true : false;
  }

  // Field name: triangle
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->triangle = tmp ? true : false;
  }

  // Field name: square
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->square = tmp ? true : false;
  }

  // Field name: cross
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->cross = tmp ? true : false;
  }

  // Field name: l1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->l1 = tmp ? true : false;
  }

  // Field name: l2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->l2 = tmp ? true : false;
  }

  // Field name: r1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->r1 = tmp ? true : false;
  }

  // Field name: r2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->r2 = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_controller
size_t get_serialized_size_controller__msg__Controller(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Controller__ros_msg_type * ros_message = static_cast<const _Controller__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name theta
  {
    size_t item_size = sizeof(ros_message->theta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hata_turn_x
  {
    size_t item_size = sizeof(ros_message->hata_turn_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hata_turn_y
  {
    size_t item_size = sizeof(ros_message->hata_turn_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hata_turn_theta
  {
    size_t item_size = sizeof(ros_message->hata_turn_theta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name baketu_turn_x
  {
    size_t item_size = sizeof(ros_message->baketu_turn_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name baketu_turn_y
  {
    size_t item_size = sizeof(ros_message->baketu_turn_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name baketu_turn_theta
  {
    size_t item_size = sizeof(ros_message->baketu_turn_theta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hoju_turn_x
  {
    size_t item_size = sizeof(ros_message->hoju_turn_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hoju_turn_y
  {
    size_t item_size = sizeof(ros_message->hoju_turn_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hoju_turn_theta
  {
    size_t item_size = sizeof(ros_message->hoju_turn_theta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hata_speed
  {
    size_t item_size = sizeof(ros_message->hata_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name baketu_speed
  {
    size_t item_size = sizeof(ros_message->baketu_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fieldcolor
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->fieldcolor.size + 1);
  // field.name dengen
  {
    size_t item_size = sizeof(ros_message->dengen);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mode
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->mode.size + 1);
  // field.name column1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->column1.size + 1);
  // field.name column2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->column2.size + 1);
  // field.name column3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->column3.size + 1);
  // field.name execute
  {
    size_t item_size = sizeof(ros_message->execute);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name refill
  {
    size_t item_size = sizeof(ros_message->refill);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reload1
  {
    size_t item_size = sizeof(ros_message->reload1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reload2
  {
    size_t item_size = sizeof(ros_message->reload2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reload3
  {
    size_t item_size = sizeof(ros_message->reload3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name firehata
  {
    size_t item_size = sizeof(ros_message->firehata);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name firebaketu
  {
    size_t item_size = sizeof(ros_message->firebaketu);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hojuposition
  {
    size_t item_size = sizeof(ros_message->hojuposition);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left
  {
    size_t item_size = sizeof(ros_message->left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right
  {
    size_t item_size = sizeof(ros_message->right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name up
  {
    size_t item_size = sizeof(ros_message->up);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name down
  {
    size_t item_size = sizeof(ros_message->down);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name circle
  {
    size_t item_size = sizeof(ros_message->circle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name triangle
  {
    size_t item_size = sizeof(ros_message->triangle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name square
  {
    size_t item_size = sizeof(ros_message->square);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cross
  {
    size_t item_size = sizeof(ros_message->cross);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name l1
  {
    size_t item_size = sizeof(ros_message->l1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name l2
  {
    size_t item_size = sizeof(ros_message->l2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name r1
  {
    size_t item_size = sizeof(ros_message->r1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name r2
  {
    size_t item_size = sizeof(ros_message->r2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Controller__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_controller__msg__Controller(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_controller
size_t max_serialized_size_controller__msg__Controller(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: theta
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: hata_turn_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: hata_turn_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: hata_turn_theta
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: baketu_turn_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: baketu_turn_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: baketu_turn_theta
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: hoju_turn_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: hoju_turn_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: hoju_turn_theta
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: hata_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: baketu_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: fieldcolor
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: dengen
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: mode
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: column1
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: column2
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: column3
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: execute
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: refill
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reload1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reload2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reload3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: firehata
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: firebaketu
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hojuposition
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: left
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: right
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: up
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: down
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: circle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: triangle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: square
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cross
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: l1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: l2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: r1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: r2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = controller__msg__Controller;
    is_plain =
      (
      offsetof(DataType, r2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Controller__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_controller__msg__Controller(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Controller = {
  "controller::msg",
  "Controller",
  _Controller__cdr_serialize,
  _Controller__cdr_deserialize,
  _Controller__get_serialized_size,
  _Controller__max_serialized_size
};

static rosidl_message_type_support_t _Controller__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Controller,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, controller, msg, Controller)() {
  return &_Controller__type_support;
}

#if defined(__cplusplus)
}
#endif
