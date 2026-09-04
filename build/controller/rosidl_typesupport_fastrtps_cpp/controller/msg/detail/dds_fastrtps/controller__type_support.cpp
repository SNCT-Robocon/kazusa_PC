// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from controller:msg/Controller.idl
// generated code does not contain a copyright notice
#include "controller/msg/detail/controller__rosidl_typesupport_fastrtps_cpp.hpp"
#include "controller/msg/detail/controller__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace controller
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_controller
cdr_serialize(
  const controller::msg::Controller & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: x
  cdr << ros_message.x;
  // Member: y
  cdr << ros_message.y;
  // Member: theta
  cdr << ros_message.theta;
  // Member: hata_turn_x
  cdr << ros_message.hata_turn_x;
  // Member: hata_turn_y
  cdr << ros_message.hata_turn_y;
  // Member: hata_turn_theta
  cdr << ros_message.hata_turn_theta;
  // Member: baketu_turn_x
  cdr << ros_message.baketu_turn_x;
  // Member: baketu_turn_y
  cdr << ros_message.baketu_turn_y;
  // Member: baketu_turn_theta
  cdr << ros_message.baketu_turn_theta;
  // Member: hoju_turn_x
  cdr << ros_message.hoju_turn_x;
  // Member: hoju_turn_y
  cdr << ros_message.hoju_turn_y;
  // Member: hoju_turn_theta
  cdr << ros_message.hoju_turn_theta;
  // Member: hata_speed
  cdr << ros_message.hata_speed;
  // Member: baketu_speed
  cdr << ros_message.baketu_speed;
  // Member: fieldcolor
  cdr << ros_message.fieldcolor;
  // Member: dengen
  cdr << (ros_message.dengen ? true : false);
  // Member: mode
  cdr << ros_message.mode;
  // Member: column1
  cdr << ros_message.column1;
  // Member: column2
  cdr << ros_message.column2;
  // Member: column3
  cdr << ros_message.column3;
  // Member: execute
  cdr << (ros_message.execute ? true : false);
  // Member: refill
  cdr << (ros_message.refill ? true : false);
  // Member: reload1
  cdr << (ros_message.reload1 ? true : false);
  // Member: reload2
  cdr << (ros_message.reload2 ? true : false);
  // Member: reload3
  cdr << (ros_message.reload3 ? true : false);
  // Member: firehata
  cdr << (ros_message.firehata ? true : false);
  // Member: firebaketu
  cdr << (ros_message.firebaketu ? true : false);
  // Member: hojuposition
  cdr << (ros_message.hojuposition ? true : false);
  // Member: left
  cdr << (ros_message.left ? true : false);
  // Member: right
  cdr << (ros_message.right ? true : false);
  // Member: up
  cdr << (ros_message.up ? true : false);
  // Member: down
  cdr << (ros_message.down ? true : false);
  // Member: circle
  cdr << (ros_message.circle ? true : false);
  // Member: triangle
  cdr << (ros_message.triangle ? true : false);
  // Member: square
  cdr << (ros_message.square ? true : false);
  // Member: cross
  cdr << (ros_message.cross ? true : false);
  // Member: l1
  cdr << (ros_message.l1 ? true : false);
  // Member: l2
  cdr << (ros_message.l2 ? true : false);
  // Member: r1
  cdr << (ros_message.r1 ? true : false);
  // Member: r2
  cdr << (ros_message.r2 ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_controller
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  controller::msg::Controller & ros_message)
{
  // Member: x
  cdr >> ros_message.x;

  // Member: y
  cdr >> ros_message.y;

  // Member: theta
  cdr >> ros_message.theta;

  // Member: hata_turn_x
  cdr >> ros_message.hata_turn_x;

  // Member: hata_turn_y
  cdr >> ros_message.hata_turn_y;

  // Member: hata_turn_theta
  cdr >> ros_message.hata_turn_theta;

  // Member: baketu_turn_x
  cdr >> ros_message.baketu_turn_x;

  // Member: baketu_turn_y
  cdr >> ros_message.baketu_turn_y;

  // Member: baketu_turn_theta
  cdr >> ros_message.baketu_turn_theta;

  // Member: hoju_turn_x
  cdr >> ros_message.hoju_turn_x;

  // Member: hoju_turn_y
  cdr >> ros_message.hoju_turn_y;

  // Member: hoju_turn_theta
  cdr >> ros_message.hoju_turn_theta;

  // Member: hata_speed
  cdr >> ros_message.hata_speed;

  // Member: baketu_speed
  cdr >> ros_message.baketu_speed;

  // Member: fieldcolor
  cdr >> ros_message.fieldcolor;

  // Member: dengen
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.dengen = tmp ? true : false;
  }

  // Member: mode
  cdr >> ros_message.mode;

  // Member: column1
  cdr >> ros_message.column1;

  // Member: column2
  cdr >> ros_message.column2;

  // Member: column3
  cdr >> ros_message.column3;

  // Member: execute
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.execute = tmp ? true : false;
  }

  // Member: refill
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.refill = tmp ? true : false;
  }

  // Member: reload1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.reload1 = tmp ? true : false;
  }

  // Member: reload2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.reload2 = tmp ? true : false;
  }

  // Member: reload3
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.reload3 = tmp ? true : false;
  }

  // Member: firehata
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.firehata = tmp ? true : false;
  }

  // Member: firebaketu
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.firebaketu = tmp ? true : false;
  }

  // Member: hojuposition
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hojuposition = tmp ? true : false;
  }

  // Member: left
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.left = tmp ? true : false;
  }

  // Member: right
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.right = tmp ? true : false;
  }

  // Member: up
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.up = tmp ? true : false;
  }

  // Member: down
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.down = tmp ? true : false;
  }

  // Member: circle
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.circle = tmp ? true : false;
  }

  // Member: triangle
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.triangle = tmp ? true : false;
  }

  // Member: square
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.square = tmp ? true : false;
  }

  // Member: cross
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.cross = tmp ? true : false;
  }

  // Member: l1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.l1 = tmp ? true : false;
  }

  // Member: l2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.l2 = tmp ? true : false;
  }

  // Member: r1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.r1 = tmp ? true : false;
  }

  // Member: r2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.r2 = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_controller
get_serialized_size(
  const controller::msg::Controller & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: x
  {
    size_t item_size = sizeof(ros_message.x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: y
  {
    size_t item_size = sizeof(ros_message.y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: theta
  {
    size_t item_size = sizeof(ros_message.theta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hata_turn_x
  {
    size_t item_size = sizeof(ros_message.hata_turn_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hata_turn_y
  {
    size_t item_size = sizeof(ros_message.hata_turn_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hata_turn_theta
  {
    size_t item_size = sizeof(ros_message.hata_turn_theta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: baketu_turn_x
  {
    size_t item_size = sizeof(ros_message.baketu_turn_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: baketu_turn_y
  {
    size_t item_size = sizeof(ros_message.baketu_turn_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: baketu_turn_theta
  {
    size_t item_size = sizeof(ros_message.baketu_turn_theta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hoju_turn_x
  {
    size_t item_size = sizeof(ros_message.hoju_turn_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hoju_turn_y
  {
    size_t item_size = sizeof(ros_message.hoju_turn_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hoju_turn_theta
  {
    size_t item_size = sizeof(ros_message.hoju_turn_theta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hata_speed
  {
    size_t item_size = sizeof(ros_message.hata_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: baketu_speed
  {
    size_t item_size = sizeof(ros_message.baketu_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fieldcolor
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.fieldcolor.size() + 1);
  // Member: dengen
  {
    size_t item_size = sizeof(ros_message.dengen);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: mode
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.mode.size() + 1);
  // Member: column1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.column1.size() + 1);
  // Member: column2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.column2.size() + 1);
  // Member: column3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.column3.size() + 1);
  // Member: execute
  {
    size_t item_size = sizeof(ros_message.execute);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: refill
  {
    size_t item_size = sizeof(ros_message.refill);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reload1
  {
    size_t item_size = sizeof(ros_message.reload1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reload2
  {
    size_t item_size = sizeof(ros_message.reload2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reload3
  {
    size_t item_size = sizeof(ros_message.reload3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: firehata
  {
    size_t item_size = sizeof(ros_message.firehata);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: firebaketu
  {
    size_t item_size = sizeof(ros_message.firebaketu);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hojuposition
  {
    size_t item_size = sizeof(ros_message.hojuposition);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left
  {
    size_t item_size = sizeof(ros_message.left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right
  {
    size_t item_size = sizeof(ros_message.right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: up
  {
    size_t item_size = sizeof(ros_message.up);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: down
  {
    size_t item_size = sizeof(ros_message.down);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: circle
  {
    size_t item_size = sizeof(ros_message.circle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: triangle
  {
    size_t item_size = sizeof(ros_message.triangle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: square
  {
    size_t item_size = sizeof(ros_message.square);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cross
  {
    size_t item_size = sizeof(ros_message.cross);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: l1
  {
    size_t item_size = sizeof(ros_message.l1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: l2
  {
    size_t item_size = sizeof(ros_message.l2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: r1
  {
    size_t item_size = sizeof(ros_message.r1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: r2
  {
    size_t item_size = sizeof(ros_message.r2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_controller
max_serialized_size_Controller(
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


  // Member: x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: theta
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: hata_turn_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: hata_turn_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: hata_turn_theta
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: baketu_turn_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: baketu_turn_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: baketu_turn_theta
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: hoju_turn_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: hoju_turn_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: hoju_turn_theta
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: hata_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: baketu_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: fieldcolor
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

  // Member: dengen
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: mode
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

  // Member: column1
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

  // Member: column2
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

  // Member: column3
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

  // Member: execute
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: refill
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reload1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reload2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reload3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: firehata
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: firebaketu
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hojuposition
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: left
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: right
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: up
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: down
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: circle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: triangle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: square
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cross
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: l1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: l2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: r1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: r2
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
    using DataType = controller::msg::Controller;
    is_plain =
      (
      offsetof(DataType, r2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Controller__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const controller::msg::Controller *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Controller__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<controller::msg::Controller *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Controller__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const controller::msg::Controller *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Controller__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Controller(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Controller__callbacks = {
  "controller::msg",
  "Controller",
  _Controller__cdr_serialize,
  _Controller__cdr_deserialize,
  _Controller__get_serialized_size,
  _Controller__max_serialized_size
};

static rosidl_message_type_support_t _Controller__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Controller__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace controller

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_controller
const rosidl_message_type_support_t *
get_message_type_support_handle<controller::msg::Controller>()
{
  return &controller::msg::typesupport_fastrtps_cpp::_Controller__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, controller, msg, Controller)() {
  return &controller::msg::typesupport_fastrtps_cpp::_Controller__handle;
}

#ifdef __cplusplus
}
#endif
