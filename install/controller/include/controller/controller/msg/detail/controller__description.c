// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from controller:msg/Controller.idl
// generated code does not contain a copyright notice

#include "controller/msg/detail/controller__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_controller
const rosidl_type_hash_t *
controller__msg__Controller__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa5, 0x85, 0x9d, 0xfa, 0xf2, 0x3b, 0xbf, 0x38,
      0x54, 0x36, 0xd2, 0xd3, 0x9f, 0xda, 0xc6, 0xbb,
      0x44, 0x73, 0x42, 0x87, 0x3f, 0x08, 0x82, 0x10,
      0xf2, 0xb5, 0x5f, 0x3c, 0x01, 0xf5, 0x88, 0xea,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char controller__msg__Controller__TYPE_NAME[] = "controller/msg/Controller";

// Define type names, field names, and default values
static char controller__msg__Controller__FIELD_NAME__x[] = "x";
static char controller__msg__Controller__FIELD_NAME__y[] = "y";
static char controller__msg__Controller__FIELD_NAME__theta[] = "theta";
static char controller__msg__Controller__FIELD_NAME__hata_turn_x[] = "hata_turn_x";
static char controller__msg__Controller__FIELD_NAME__hata_turn_y[] = "hata_turn_y";
static char controller__msg__Controller__FIELD_NAME__hata_turn_theta[] = "hata_turn_theta";
static char controller__msg__Controller__FIELD_NAME__baketu_turn_x[] = "baketu_turn_x";
static char controller__msg__Controller__FIELD_NAME__baketu_turn_y[] = "baketu_turn_y";
static char controller__msg__Controller__FIELD_NAME__baketu_turn_theta[] = "baketu_turn_theta";
static char controller__msg__Controller__FIELD_NAME__hoju_turn_x[] = "hoju_turn_x";
static char controller__msg__Controller__FIELD_NAME__hoju_turn_y[] = "hoju_turn_y";
static char controller__msg__Controller__FIELD_NAME__hoju_turn_theta[] = "hoju_turn_theta";
static char controller__msg__Controller__FIELD_NAME__hata_speed[] = "hata_speed";
static char controller__msg__Controller__FIELD_NAME__baketu_speed[] = "baketu_speed";
static char controller__msg__Controller__FIELD_NAME__fieldcolor[] = "fieldcolor";
static char controller__msg__Controller__FIELD_NAME__dengen[] = "dengen";
static char controller__msg__Controller__FIELD_NAME__mode[] = "mode";
static char controller__msg__Controller__FIELD_NAME__column1[] = "column1";
static char controller__msg__Controller__FIELD_NAME__column2[] = "column2";
static char controller__msg__Controller__FIELD_NAME__column3[] = "column3";
static char controller__msg__Controller__FIELD_NAME__execute[] = "execute";
static char controller__msg__Controller__FIELD_NAME__refill[] = "refill";
static char controller__msg__Controller__FIELD_NAME__reload1[] = "reload1";
static char controller__msg__Controller__FIELD_NAME__reload2[] = "reload2";
static char controller__msg__Controller__FIELD_NAME__reload3[] = "reload3";
static char controller__msg__Controller__FIELD_NAME__firehata[] = "firehata";
static char controller__msg__Controller__FIELD_NAME__firebaketu[] = "firebaketu";
static char controller__msg__Controller__FIELD_NAME__hojuposition[] = "hojuposition";
static char controller__msg__Controller__FIELD_NAME__left[] = "left";
static char controller__msg__Controller__FIELD_NAME__right[] = "right";
static char controller__msg__Controller__FIELD_NAME__up[] = "up";
static char controller__msg__Controller__FIELD_NAME__down[] = "down";
static char controller__msg__Controller__FIELD_NAME__circle[] = "circle";
static char controller__msg__Controller__FIELD_NAME__triangle[] = "triangle";
static char controller__msg__Controller__FIELD_NAME__square[] = "square";
static char controller__msg__Controller__FIELD_NAME__cross[] = "cross";
static char controller__msg__Controller__FIELD_NAME__l1[] = "l1";
static char controller__msg__Controller__FIELD_NAME__l2[] = "l2";
static char controller__msg__Controller__FIELD_NAME__r1[] = "r1";
static char controller__msg__Controller__FIELD_NAME__r2[] = "r2";

static rosidl_runtime_c__type_description__Field controller__msg__Controller__FIELDS[] = {
  {
    {controller__msg__Controller__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__theta, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__hata_turn_x, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__hata_turn_y, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__hata_turn_theta, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__baketu_turn_x, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__baketu_turn_y, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__baketu_turn_theta, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__hoju_turn_x, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__hoju_turn_y, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__hoju_turn_theta, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__hata_speed, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__baketu_speed, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__fieldcolor, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__dengen, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__column1, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__column2, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__column3, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__execute, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__refill, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__reload1, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__reload2, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__reload3, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__firehata, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__firebaketu, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__hojuposition, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__left, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__right, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__up, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__down, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__circle, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__triangle, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__square, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__cross, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__l1, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__l2, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__r1, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controller__msg__Controller__FIELD_NAME__r2, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
controller__msg__Controller__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {controller__msg__Controller__TYPE_NAME, 25, 25},
      {controller__msg__Controller__FIELDS, 40, 40},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 x\n"
  "float32 y\n"
  "float32 theta\n"
  "float32 hata_turn_x\n"
  "float32 hata_turn_y\n"
  "float32 hata_turn_theta\n"
  "float32 baketu_turn_x\n"
  "float32 baketu_turn_y\n"
  "float32 baketu_turn_theta\n"
  "float32 hoju_turn_x\n"
  "float32 hoju_turn_y\n"
  "float32 hoju_turn_theta\n"
  "float32 hata_speed\n"
  "float32 baketu_speed\n"
  "\n"
  "string fieldcolor\n"
  "bool dengen\n"
  "string mode\n"
  "string column1\n"
  "string column2\n"
  "string column3\n"
  "bool execute\n"
  "bool refill\n"
  "bool reload1\n"
  "bool reload2\n"
  "bool reload3\n"
  "bool firehata\n"
  "bool firebaketu\n"
  "bool hojuposition\n"
  "\n"
  "bool left\n"
  "bool right\n"
  "bool up\n"
  "bool down\n"
  "bool circle\n"
  "bool triangle\n"
  "bool square\n"
  "bool cross\n"
  "bool l1\n"
  "bool l2\n"
  "bool r1\n"
  "bool r2";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
controller__msg__Controller__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {controller__msg__Controller__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 593, 593},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
controller__msg__Controller__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *controller__msg__Controller__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
