// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from controller:msg/Controller.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER__MSG__DETAIL__CONTROLLER__TRAITS_HPP_
#define CONTROLLER__MSG__DETAIL__CONTROLLER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "controller/msg/detail/controller__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace controller
{

namespace msg
{

inline void to_flow_style_yaml(
  const Controller & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << ", ";
  }

  // member: hata_turn_x
  {
    out << "hata_turn_x: ";
    rosidl_generator_traits::value_to_yaml(msg.hata_turn_x, out);
    out << ", ";
  }

  // member: hata_turn_y
  {
    out << "hata_turn_y: ";
    rosidl_generator_traits::value_to_yaml(msg.hata_turn_y, out);
    out << ", ";
  }

  // member: hata_turn_theta
  {
    out << "hata_turn_theta: ";
    rosidl_generator_traits::value_to_yaml(msg.hata_turn_theta, out);
    out << ", ";
  }

  // member: baketu_turn_x
  {
    out << "baketu_turn_x: ";
    rosidl_generator_traits::value_to_yaml(msg.baketu_turn_x, out);
    out << ", ";
  }

  // member: baketu_turn_y
  {
    out << "baketu_turn_y: ";
    rosidl_generator_traits::value_to_yaml(msg.baketu_turn_y, out);
    out << ", ";
  }

  // member: baketu_turn_theta
  {
    out << "baketu_turn_theta: ";
    rosidl_generator_traits::value_to_yaml(msg.baketu_turn_theta, out);
    out << ", ";
  }

  // member: hoju_turn_x
  {
    out << "hoju_turn_x: ";
    rosidl_generator_traits::value_to_yaml(msg.hoju_turn_x, out);
    out << ", ";
  }

  // member: hoju_turn_y
  {
    out << "hoju_turn_y: ";
    rosidl_generator_traits::value_to_yaml(msg.hoju_turn_y, out);
    out << ", ";
  }

  // member: hoju_turn_theta
  {
    out << "hoju_turn_theta: ";
    rosidl_generator_traits::value_to_yaml(msg.hoju_turn_theta, out);
    out << ", ";
  }

  // member: hata_speed
  {
    out << "hata_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.hata_speed, out);
    out << ", ";
  }

  // member: baketu_speed
  {
    out << "baketu_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.baketu_speed, out);
    out << ", ";
  }

  // member: fieldcolor
  {
    out << "fieldcolor: ";
    rosidl_generator_traits::value_to_yaml(msg.fieldcolor, out);
    out << ", ";
  }

  // member: dengen
  {
    out << "dengen: ";
    rosidl_generator_traits::value_to_yaml(msg.dengen, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: column1
  {
    out << "column1: ";
    rosidl_generator_traits::value_to_yaml(msg.column1, out);
    out << ", ";
  }

  // member: column2
  {
    out << "column2: ";
    rosidl_generator_traits::value_to_yaml(msg.column2, out);
    out << ", ";
  }

  // member: column3
  {
    out << "column3: ";
    rosidl_generator_traits::value_to_yaml(msg.column3, out);
    out << ", ";
  }

  // member: execute
  {
    out << "execute: ";
    rosidl_generator_traits::value_to_yaml(msg.execute, out);
    out << ", ";
  }

  // member: refill
  {
    out << "refill: ";
    rosidl_generator_traits::value_to_yaml(msg.refill, out);
    out << ", ";
  }

  // member: reload1
  {
    out << "reload1: ";
    rosidl_generator_traits::value_to_yaml(msg.reload1, out);
    out << ", ";
  }

  // member: reload2
  {
    out << "reload2: ";
    rosidl_generator_traits::value_to_yaml(msg.reload2, out);
    out << ", ";
  }

  // member: reload3
  {
    out << "reload3: ";
    rosidl_generator_traits::value_to_yaml(msg.reload3, out);
    out << ", ";
  }

  // member: firehata
  {
    out << "firehata: ";
    rosidl_generator_traits::value_to_yaml(msg.firehata, out);
    out << ", ";
  }

  // member: firebaketu
  {
    out << "firebaketu: ";
    rosidl_generator_traits::value_to_yaml(msg.firebaketu, out);
    out << ", ";
  }

  // member: hojuposition
  {
    out << "hojuposition: ";
    rosidl_generator_traits::value_to_yaml(msg.hojuposition, out);
    out << ", ";
  }

  // member: left
  {
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << ", ";
  }

  // member: right
  {
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
    out << ", ";
  }

  // member: up
  {
    out << "up: ";
    rosidl_generator_traits::value_to_yaml(msg.up, out);
    out << ", ";
  }

  // member: down
  {
    out << "down: ";
    rosidl_generator_traits::value_to_yaml(msg.down, out);
    out << ", ";
  }

  // member: circle
  {
    out << "circle: ";
    rosidl_generator_traits::value_to_yaml(msg.circle, out);
    out << ", ";
  }

  // member: triangle
  {
    out << "triangle: ";
    rosidl_generator_traits::value_to_yaml(msg.triangle, out);
    out << ", ";
  }

  // member: square
  {
    out << "square: ";
    rosidl_generator_traits::value_to_yaml(msg.square, out);
    out << ", ";
  }

  // member: cross
  {
    out << "cross: ";
    rosidl_generator_traits::value_to_yaml(msg.cross, out);
    out << ", ";
  }

  // member: l1
  {
    out << "l1: ";
    rosidl_generator_traits::value_to_yaml(msg.l1, out);
    out << ", ";
  }

  // member: l2
  {
    out << "l2: ";
    rosidl_generator_traits::value_to_yaml(msg.l2, out);
    out << ", ";
  }

  // member: r1
  {
    out << "r1: ";
    rosidl_generator_traits::value_to_yaml(msg.r1, out);
    out << ", ";
  }

  // member: r2
  {
    out << "r2: ";
    rosidl_generator_traits::value_to_yaml(msg.r2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Controller & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }

  // member: hata_turn_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hata_turn_x: ";
    rosidl_generator_traits::value_to_yaml(msg.hata_turn_x, out);
    out << "\n";
  }

  // member: hata_turn_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hata_turn_y: ";
    rosidl_generator_traits::value_to_yaml(msg.hata_turn_y, out);
    out << "\n";
  }

  // member: hata_turn_theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hata_turn_theta: ";
    rosidl_generator_traits::value_to_yaml(msg.hata_turn_theta, out);
    out << "\n";
  }

  // member: baketu_turn_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "baketu_turn_x: ";
    rosidl_generator_traits::value_to_yaml(msg.baketu_turn_x, out);
    out << "\n";
  }

  // member: baketu_turn_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "baketu_turn_y: ";
    rosidl_generator_traits::value_to_yaml(msg.baketu_turn_y, out);
    out << "\n";
  }

  // member: baketu_turn_theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "baketu_turn_theta: ";
    rosidl_generator_traits::value_to_yaml(msg.baketu_turn_theta, out);
    out << "\n";
  }

  // member: hoju_turn_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hoju_turn_x: ";
    rosidl_generator_traits::value_to_yaml(msg.hoju_turn_x, out);
    out << "\n";
  }

  // member: hoju_turn_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hoju_turn_y: ";
    rosidl_generator_traits::value_to_yaml(msg.hoju_turn_y, out);
    out << "\n";
  }

  // member: hoju_turn_theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hoju_turn_theta: ";
    rosidl_generator_traits::value_to_yaml(msg.hoju_turn_theta, out);
    out << "\n";
  }

  // member: hata_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hata_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.hata_speed, out);
    out << "\n";
  }

  // member: baketu_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "baketu_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.baketu_speed, out);
    out << "\n";
  }

  // member: fieldcolor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fieldcolor: ";
    rosidl_generator_traits::value_to_yaml(msg.fieldcolor, out);
    out << "\n";
  }

  // member: dengen
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dengen: ";
    rosidl_generator_traits::value_to_yaml(msg.dengen, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: column1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "column1: ";
    rosidl_generator_traits::value_to_yaml(msg.column1, out);
    out << "\n";
  }

  // member: column2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "column2: ";
    rosidl_generator_traits::value_to_yaml(msg.column2, out);
    out << "\n";
  }

  // member: column3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "column3: ";
    rosidl_generator_traits::value_to_yaml(msg.column3, out);
    out << "\n";
  }

  // member: execute
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "execute: ";
    rosidl_generator_traits::value_to_yaml(msg.execute, out);
    out << "\n";
  }

  // member: refill
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "refill: ";
    rosidl_generator_traits::value_to_yaml(msg.refill, out);
    out << "\n";
  }

  // member: reload1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reload1: ";
    rosidl_generator_traits::value_to_yaml(msg.reload1, out);
    out << "\n";
  }

  // member: reload2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reload2: ";
    rosidl_generator_traits::value_to_yaml(msg.reload2, out);
    out << "\n";
  }

  // member: reload3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reload3: ";
    rosidl_generator_traits::value_to_yaml(msg.reload3, out);
    out << "\n";
  }

  // member: firehata
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "firehata: ";
    rosidl_generator_traits::value_to_yaml(msg.firehata, out);
    out << "\n";
  }

  // member: firebaketu
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "firebaketu: ";
    rosidl_generator_traits::value_to_yaml(msg.firebaketu, out);
    out << "\n";
  }

  // member: hojuposition
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hojuposition: ";
    rosidl_generator_traits::value_to_yaml(msg.hojuposition, out);
    out << "\n";
  }

  // member: left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << "\n";
  }

  // member: right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
    out << "\n";
  }

  // member: up
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "up: ";
    rosidl_generator_traits::value_to_yaml(msg.up, out);
    out << "\n";
  }

  // member: down
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "down: ";
    rosidl_generator_traits::value_to_yaml(msg.down, out);
    out << "\n";
  }

  // member: circle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "circle: ";
    rosidl_generator_traits::value_to_yaml(msg.circle, out);
    out << "\n";
  }

  // member: triangle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "triangle: ";
    rosidl_generator_traits::value_to_yaml(msg.triangle, out);
    out << "\n";
  }

  // member: square
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "square: ";
    rosidl_generator_traits::value_to_yaml(msg.square, out);
    out << "\n";
  }

  // member: cross
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cross: ";
    rosidl_generator_traits::value_to_yaml(msg.cross, out);
    out << "\n";
  }

  // member: l1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l1: ";
    rosidl_generator_traits::value_to_yaml(msg.l1, out);
    out << "\n";
  }

  // member: l2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l2: ";
    rosidl_generator_traits::value_to_yaml(msg.l2, out);
    out << "\n";
  }

  // member: r1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r1: ";
    rosidl_generator_traits::value_to_yaml(msg.r1, out);
    out << "\n";
  }

  // member: r2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r2: ";
    rosidl_generator_traits::value_to_yaml(msg.r2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Controller & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace controller

namespace rosidl_generator_traits
{

[[deprecated("use controller::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const controller::msg::Controller & msg,
  std::ostream & out, size_t indentation = 0)
{
  controller::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use controller::msg::to_yaml() instead")]]
inline std::string to_yaml(const controller::msg::Controller & msg)
{
  return controller::msg::to_yaml(msg);
}

template<>
inline const char * data_type<controller::msg::Controller>()
{
  return "controller::msg::Controller";
}

template<>
inline const char * name<controller::msg::Controller>()
{
  return "controller/msg/Controller";
}

template<>
struct has_fixed_size<controller::msg::Controller>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<controller::msg::Controller>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<controller::msg::Controller>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CONTROLLER__MSG__DETAIL__CONTROLLER__TRAITS_HPP_
