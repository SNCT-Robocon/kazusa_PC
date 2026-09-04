// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from controller:msg/Controller.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER__MSG__DETAIL__CONTROLLER__STRUCT_H_
#define CONTROLLER__MSG__DETAIL__CONTROLLER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'fieldcolor'
// Member 'mode'
// Member 'column1'
// Member 'column2'
// Member 'column3'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Controller in the package controller.
typedef struct controller__msg__Controller
{
  float x;
  float y;
  float theta;
  float hata_turn_x;
  float hata_turn_y;
  float hata_turn_theta;
  float baketu_turn_x;
  float baketu_turn_y;
  float baketu_turn_theta;
  float hoju_turn_x;
  float hoju_turn_y;
  float hoju_turn_theta;
  float hata_speed;
  float baketu_speed;
  rosidl_runtime_c__String fieldcolor;
  bool dengen;
  rosidl_runtime_c__String mode;
  rosidl_runtime_c__String column1;
  rosidl_runtime_c__String column2;
  rosidl_runtime_c__String column3;
  bool execute;
  bool refill;
  bool reload1;
  bool reload2;
  bool reload3;
  bool firehata;
  bool firebaketu;
  bool hojuposition;
  bool left;
  bool right;
  bool up;
  bool down;
  bool circle;
  bool triangle;
  bool square;
  bool cross;
  bool l1;
  bool l2;
  bool r1;
  bool r2;
} controller__msg__Controller;

// Struct for a sequence of controller__msg__Controller.
typedef struct controller__msg__Controller__Sequence
{
  controller__msg__Controller * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} controller__msg__Controller__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROLLER__MSG__DETAIL__CONTROLLER__STRUCT_H_
