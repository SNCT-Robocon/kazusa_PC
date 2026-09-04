// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/CanPacket.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__CAN_PACKET__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__CAN_PACKET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/can_packet__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_CanPacket_data
{
public:
  explicit Init_CanPacket_data(::custom_msgs::msg::CanPacket & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::CanPacket data(::custom_msgs::msg::CanPacket::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::CanPacket msg_;
};

class Init_CanPacket_id
{
public:
  Init_CanPacket_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CanPacket_data id(::custom_msgs::msg::CanPacket::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_CanPacket_data(msg_);
  }

private:
  ::custom_msgs::msg::CanPacket msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::CanPacket>()
{
  return custom_msgs::msg::builder::Init_CanPacket_id();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__CAN_PACKET__BUILDER_HPP_
