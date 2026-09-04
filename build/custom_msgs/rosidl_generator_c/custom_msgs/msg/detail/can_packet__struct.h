// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/CanPacket.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__CAN_PACKET__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__CAN_PACKET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/CanPacket in the package custom_msgs.
typedef struct custom_msgs__msg__CanPacket
{
  uint16_t id;
  uint8_t data[32];
} custom_msgs__msg__CanPacket;

// Struct for a sequence of custom_msgs__msg__CanPacket.
typedef struct custom_msgs__msg__CanPacket__Sequence
{
  custom_msgs__msg__CanPacket * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__CanPacket__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__CAN_PACKET__STRUCT_H_
