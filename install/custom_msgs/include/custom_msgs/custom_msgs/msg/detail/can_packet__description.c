// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/CanPacket.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/can_packet__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__CanPacket__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x50, 0x5a, 0xa6, 0x9d, 0x26, 0xcb, 0x76, 0x56,
      0x23, 0x46, 0x1f, 0x8b, 0xb7, 0x5a, 0x7f, 0x9a,
      0xc0, 0x7f, 0x18, 0x21, 0x47, 0x41, 0xf7, 0x76,
      0x11, 0x49, 0x69, 0x9c, 0x6f, 0xfa, 0xfa, 0xcf,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__CanPacket__TYPE_NAME[] = "custom_msgs/msg/CanPacket";

// Define type names, field names, and default values
static char custom_msgs__msg__CanPacket__FIELD_NAME__id[] = "id";
static char custom_msgs__msg__CanPacket__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__CanPacket__FIELDS[] = {
  {
    {custom_msgs__msg__CanPacket__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__CanPacket__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_ARRAY,
      32,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__msg__CanPacket__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__CanPacket__TYPE_NAME, 25, 25},
      {custom_msgs__msg__CanPacket__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint16 id\n"
  "uint8[32] data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__CanPacket__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__CanPacket__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 24, 24},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__CanPacket__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__CanPacket__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
