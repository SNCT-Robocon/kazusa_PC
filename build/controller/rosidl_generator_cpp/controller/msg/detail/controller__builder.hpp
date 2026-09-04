// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from controller:msg/Controller.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER__MSG__DETAIL__CONTROLLER__BUILDER_HPP_
#define CONTROLLER__MSG__DETAIL__CONTROLLER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "controller/msg/detail/controller__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace controller
{

namespace msg
{

namespace builder
{

class Init_Controller_r2
{
public:
  explicit Init_Controller_r2(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  ::controller::msg::Controller r2(::controller::msg::Controller::_r2_type arg)
  {
    msg_.r2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_r1
{
public:
  explicit Init_Controller_r1(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_r2 r1(::controller::msg::Controller::_r1_type arg)
  {
    msg_.r1 = std::move(arg);
    return Init_Controller_r2(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_l2
{
public:
  explicit Init_Controller_l2(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_r1 l2(::controller::msg::Controller::_l2_type arg)
  {
    msg_.l2 = std::move(arg);
    return Init_Controller_r1(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_l1
{
public:
  explicit Init_Controller_l1(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_l2 l1(::controller::msg::Controller::_l1_type arg)
  {
    msg_.l1 = std::move(arg);
    return Init_Controller_l2(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_cross
{
public:
  explicit Init_Controller_cross(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_l1 cross(::controller::msg::Controller::_cross_type arg)
  {
    msg_.cross = std::move(arg);
    return Init_Controller_l1(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_square
{
public:
  explicit Init_Controller_square(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_cross square(::controller::msg::Controller::_square_type arg)
  {
    msg_.square = std::move(arg);
    return Init_Controller_cross(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_triangle
{
public:
  explicit Init_Controller_triangle(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_square triangle(::controller::msg::Controller::_triangle_type arg)
  {
    msg_.triangle = std::move(arg);
    return Init_Controller_square(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_circle
{
public:
  explicit Init_Controller_circle(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_triangle circle(::controller::msg::Controller::_circle_type arg)
  {
    msg_.circle = std::move(arg);
    return Init_Controller_triangle(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_down
{
public:
  explicit Init_Controller_down(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_circle down(::controller::msg::Controller::_down_type arg)
  {
    msg_.down = std::move(arg);
    return Init_Controller_circle(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_up
{
public:
  explicit Init_Controller_up(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_down up(::controller::msg::Controller::_up_type arg)
  {
    msg_.up = std::move(arg);
    return Init_Controller_down(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_right
{
public:
  explicit Init_Controller_right(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_up right(::controller::msg::Controller::_right_type arg)
  {
    msg_.right = std::move(arg);
    return Init_Controller_up(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_left
{
public:
  explicit Init_Controller_left(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_right left(::controller::msg::Controller::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_Controller_right(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_hojuposition
{
public:
  explicit Init_Controller_hojuposition(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_left hojuposition(::controller::msg::Controller::_hojuposition_type arg)
  {
    msg_.hojuposition = std::move(arg);
    return Init_Controller_left(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_firebaketu
{
public:
  explicit Init_Controller_firebaketu(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_hojuposition firebaketu(::controller::msg::Controller::_firebaketu_type arg)
  {
    msg_.firebaketu = std::move(arg);
    return Init_Controller_hojuposition(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_firehata
{
public:
  explicit Init_Controller_firehata(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_firebaketu firehata(::controller::msg::Controller::_firehata_type arg)
  {
    msg_.firehata = std::move(arg);
    return Init_Controller_firebaketu(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_reload3
{
public:
  explicit Init_Controller_reload3(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_firehata reload3(::controller::msg::Controller::_reload3_type arg)
  {
    msg_.reload3 = std::move(arg);
    return Init_Controller_firehata(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_reload2
{
public:
  explicit Init_Controller_reload2(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_reload3 reload2(::controller::msg::Controller::_reload2_type arg)
  {
    msg_.reload2 = std::move(arg);
    return Init_Controller_reload3(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_reload1
{
public:
  explicit Init_Controller_reload1(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_reload2 reload1(::controller::msg::Controller::_reload1_type arg)
  {
    msg_.reload1 = std::move(arg);
    return Init_Controller_reload2(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_refill
{
public:
  explicit Init_Controller_refill(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_reload1 refill(::controller::msg::Controller::_refill_type arg)
  {
    msg_.refill = std::move(arg);
    return Init_Controller_reload1(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_execute
{
public:
  explicit Init_Controller_execute(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_refill execute(::controller::msg::Controller::_execute_type arg)
  {
    msg_.execute = std::move(arg);
    return Init_Controller_refill(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_column3
{
public:
  explicit Init_Controller_column3(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_execute column3(::controller::msg::Controller::_column3_type arg)
  {
    msg_.column3 = std::move(arg);
    return Init_Controller_execute(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_column2
{
public:
  explicit Init_Controller_column2(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_column3 column2(::controller::msg::Controller::_column2_type arg)
  {
    msg_.column2 = std::move(arg);
    return Init_Controller_column3(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_column1
{
public:
  explicit Init_Controller_column1(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_column2 column1(::controller::msg::Controller::_column1_type arg)
  {
    msg_.column1 = std::move(arg);
    return Init_Controller_column2(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_mode
{
public:
  explicit Init_Controller_mode(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_column1 mode(::controller::msg::Controller::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_Controller_column1(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_dengen
{
public:
  explicit Init_Controller_dengen(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_mode dengen(::controller::msg::Controller::_dengen_type arg)
  {
    msg_.dengen = std::move(arg);
    return Init_Controller_mode(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_fieldcolor
{
public:
  explicit Init_Controller_fieldcolor(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_dengen fieldcolor(::controller::msg::Controller::_fieldcolor_type arg)
  {
    msg_.fieldcolor = std::move(arg);
    return Init_Controller_dengen(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_baketu_speed
{
public:
  explicit Init_Controller_baketu_speed(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_fieldcolor baketu_speed(::controller::msg::Controller::_baketu_speed_type arg)
  {
    msg_.baketu_speed = std::move(arg);
    return Init_Controller_fieldcolor(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_hata_speed
{
public:
  explicit Init_Controller_hata_speed(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_baketu_speed hata_speed(::controller::msg::Controller::_hata_speed_type arg)
  {
    msg_.hata_speed = std::move(arg);
    return Init_Controller_baketu_speed(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_hoju_turn_theta
{
public:
  explicit Init_Controller_hoju_turn_theta(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_hata_speed hoju_turn_theta(::controller::msg::Controller::_hoju_turn_theta_type arg)
  {
    msg_.hoju_turn_theta = std::move(arg);
    return Init_Controller_hata_speed(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_hoju_turn_y
{
public:
  explicit Init_Controller_hoju_turn_y(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_hoju_turn_theta hoju_turn_y(::controller::msg::Controller::_hoju_turn_y_type arg)
  {
    msg_.hoju_turn_y = std::move(arg);
    return Init_Controller_hoju_turn_theta(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_hoju_turn_x
{
public:
  explicit Init_Controller_hoju_turn_x(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_hoju_turn_y hoju_turn_x(::controller::msg::Controller::_hoju_turn_x_type arg)
  {
    msg_.hoju_turn_x = std::move(arg);
    return Init_Controller_hoju_turn_y(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_baketu_turn_theta
{
public:
  explicit Init_Controller_baketu_turn_theta(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_hoju_turn_x baketu_turn_theta(::controller::msg::Controller::_baketu_turn_theta_type arg)
  {
    msg_.baketu_turn_theta = std::move(arg);
    return Init_Controller_hoju_turn_x(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_baketu_turn_y
{
public:
  explicit Init_Controller_baketu_turn_y(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_baketu_turn_theta baketu_turn_y(::controller::msg::Controller::_baketu_turn_y_type arg)
  {
    msg_.baketu_turn_y = std::move(arg);
    return Init_Controller_baketu_turn_theta(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_baketu_turn_x
{
public:
  explicit Init_Controller_baketu_turn_x(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_baketu_turn_y baketu_turn_x(::controller::msg::Controller::_baketu_turn_x_type arg)
  {
    msg_.baketu_turn_x = std::move(arg);
    return Init_Controller_baketu_turn_y(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_hata_turn_theta
{
public:
  explicit Init_Controller_hata_turn_theta(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_baketu_turn_x hata_turn_theta(::controller::msg::Controller::_hata_turn_theta_type arg)
  {
    msg_.hata_turn_theta = std::move(arg);
    return Init_Controller_baketu_turn_x(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_hata_turn_y
{
public:
  explicit Init_Controller_hata_turn_y(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_hata_turn_theta hata_turn_y(::controller::msg::Controller::_hata_turn_y_type arg)
  {
    msg_.hata_turn_y = std::move(arg);
    return Init_Controller_hata_turn_theta(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_hata_turn_x
{
public:
  explicit Init_Controller_hata_turn_x(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_hata_turn_y hata_turn_x(::controller::msg::Controller::_hata_turn_x_type arg)
  {
    msg_.hata_turn_x = std::move(arg);
    return Init_Controller_hata_turn_y(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_theta
{
public:
  explicit Init_Controller_theta(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_hata_turn_x theta(::controller::msg::Controller::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_Controller_hata_turn_x(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_y
{
public:
  explicit Init_Controller_y(::controller::msg::Controller & msg)
  : msg_(msg)
  {}
  Init_Controller_theta y(::controller::msg::Controller::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Controller_theta(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

class Init_Controller_x
{
public:
  Init_Controller_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Controller_y x(::controller::msg::Controller::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Controller_y(msg_);
  }

private:
  ::controller::msg::Controller msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::controller::msg::Controller>()
{
  return controller::msg::builder::Init_Controller_x();
}

}  // namespace controller

#endif  // CONTROLLER__MSG__DETAIL__CONTROLLER__BUILDER_HPP_
