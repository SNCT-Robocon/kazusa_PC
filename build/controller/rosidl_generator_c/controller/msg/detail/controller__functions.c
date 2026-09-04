// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from controller:msg/Controller.idl
// generated code does not contain a copyright notice
#include "controller/msg/detail/controller__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `fieldcolor`
// Member `mode`
// Member `column1`
// Member `column2`
// Member `column3`
#include "rosidl_runtime_c/string_functions.h"

bool
controller__msg__Controller__init(controller__msg__Controller * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // theta
  // hata_turn_x
  // hata_turn_y
  // hata_turn_theta
  // baketu_turn_x
  // baketu_turn_y
  // baketu_turn_theta
  // hoju_turn_x
  // hoju_turn_y
  // hoju_turn_theta
  // hata_speed
  // baketu_speed
  // fieldcolor
  if (!rosidl_runtime_c__String__init(&msg->fieldcolor)) {
    controller__msg__Controller__fini(msg);
    return false;
  }
  // dengen
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    controller__msg__Controller__fini(msg);
    return false;
  }
  // column1
  if (!rosidl_runtime_c__String__init(&msg->column1)) {
    controller__msg__Controller__fini(msg);
    return false;
  }
  // column2
  if (!rosidl_runtime_c__String__init(&msg->column2)) {
    controller__msg__Controller__fini(msg);
    return false;
  }
  // column3
  if (!rosidl_runtime_c__String__init(&msg->column3)) {
    controller__msg__Controller__fini(msg);
    return false;
  }
  // execute
  // refill
  // reload1
  // reload2
  // reload3
  // firehata
  // firebaketu
  // hojuposition
  // left
  // right
  // up
  // down
  // circle
  // triangle
  // square
  // cross
  // l1
  // l2
  // r1
  // r2
  return true;
}

void
controller__msg__Controller__fini(controller__msg__Controller * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // theta
  // hata_turn_x
  // hata_turn_y
  // hata_turn_theta
  // baketu_turn_x
  // baketu_turn_y
  // baketu_turn_theta
  // hoju_turn_x
  // hoju_turn_y
  // hoju_turn_theta
  // hata_speed
  // baketu_speed
  // fieldcolor
  rosidl_runtime_c__String__fini(&msg->fieldcolor);
  // dengen
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
  // column1
  rosidl_runtime_c__String__fini(&msg->column1);
  // column2
  rosidl_runtime_c__String__fini(&msg->column2);
  // column3
  rosidl_runtime_c__String__fini(&msg->column3);
  // execute
  // refill
  // reload1
  // reload2
  // reload3
  // firehata
  // firebaketu
  // hojuposition
  // left
  // right
  // up
  // down
  // circle
  // triangle
  // square
  // cross
  // l1
  // l2
  // r1
  // r2
}

bool
controller__msg__Controller__are_equal(const controller__msg__Controller * lhs, const controller__msg__Controller * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // theta
  if (lhs->theta != rhs->theta) {
    return false;
  }
  // hata_turn_x
  if (lhs->hata_turn_x != rhs->hata_turn_x) {
    return false;
  }
  // hata_turn_y
  if (lhs->hata_turn_y != rhs->hata_turn_y) {
    return false;
  }
  // hata_turn_theta
  if (lhs->hata_turn_theta != rhs->hata_turn_theta) {
    return false;
  }
  // baketu_turn_x
  if (lhs->baketu_turn_x != rhs->baketu_turn_x) {
    return false;
  }
  // baketu_turn_y
  if (lhs->baketu_turn_y != rhs->baketu_turn_y) {
    return false;
  }
  // baketu_turn_theta
  if (lhs->baketu_turn_theta != rhs->baketu_turn_theta) {
    return false;
  }
  // hoju_turn_x
  if (lhs->hoju_turn_x != rhs->hoju_turn_x) {
    return false;
  }
  // hoju_turn_y
  if (lhs->hoju_turn_y != rhs->hoju_turn_y) {
    return false;
  }
  // hoju_turn_theta
  if (lhs->hoju_turn_theta != rhs->hoju_turn_theta) {
    return false;
  }
  // hata_speed
  if (lhs->hata_speed != rhs->hata_speed) {
    return false;
  }
  // baketu_speed
  if (lhs->baketu_speed != rhs->baketu_speed) {
    return false;
  }
  // fieldcolor
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->fieldcolor), &(rhs->fieldcolor)))
  {
    return false;
  }
  // dengen
  if (lhs->dengen != rhs->dengen) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  // column1
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->column1), &(rhs->column1)))
  {
    return false;
  }
  // column2
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->column2), &(rhs->column2)))
  {
    return false;
  }
  // column3
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->column3), &(rhs->column3)))
  {
    return false;
  }
  // execute
  if (lhs->execute != rhs->execute) {
    return false;
  }
  // refill
  if (lhs->refill != rhs->refill) {
    return false;
  }
  // reload1
  if (lhs->reload1 != rhs->reload1) {
    return false;
  }
  // reload2
  if (lhs->reload2 != rhs->reload2) {
    return false;
  }
  // reload3
  if (lhs->reload3 != rhs->reload3) {
    return false;
  }
  // firehata
  if (lhs->firehata != rhs->firehata) {
    return false;
  }
  // firebaketu
  if (lhs->firebaketu != rhs->firebaketu) {
    return false;
  }
  // hojuposition
  if (lhs->hojuposition != rhs->hojuposition) {
    return false;
  }
  // left
  if (lhs->left != rhs->left) {
    return false;
  }
  // right
  if (lhs->right != rhs->right) {
    return false;
  }
  // up
  if (lhs->up != rhs->up) {
    return false;
  }
  // down
  if (lhs->down != rhs->down) {
    return false;
  }
  // circle
  if (lhs->circle != rhs->circle) {
    return false;
  }
  // triangle
  if (lhs->triangle != rhs->triangle) {
    return false;
  }
  // square
  if (lhs->square != rhs->square) {
    return false;
  }
  // cross
  if (lhs->cross != rhs->cross) {
    return false;
  }
  // l1
  if (lhs->l1 != rhs->l1) {
    return false;
  }
  // l2
  if (lhs->l2 != rhs->l2) {
    return false;
  }
  // r1
  if (lhs->r1 != rhs->r1) {
    return false;
  }
  // r2
  if (lhs->r2 != rhs->r2) {
    return false;
  }
  return true;
}

bool
controller__msg__Controller__copy(
  const controller__msg__Controller * input,
  controller__msg__Controller * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // theta
  output->theta = input->theta;
  // hata_turn_x
  output->hata_turn_x = input->hata_turn_x;
  // hata_turn_y
  output->hata_turn_y = input->hata_turn_y;
  // hata_turn_theta
  output->hata_turn_theta = input->hata_turn_theta;
  // baketu_turn_x
  output->baketu_turn_x = input->baketu_turn_x;
  // baketu_turn_y
  output->baketu_turn_y = input->baketu_turn_y;
  // baketu_turn_theta
  output->baketu_turn_theta = input->baketu_turn_theta;
  // hoju_turn_x
  output->hoju_turn_x = input->hoju_turn_x;
  // hoju_turn_y
  output->hoju_turn_y = input->hoju_turn_y;
  // hoju_turn_theta
  output->hoju_turn_theta = input->hoju_turn_theta;
  // hata_speed
  output->hata_speed = input->hata_speed;
  // baketu_speed
  output->baketu_speed = input->baketu_speed;
  // fieldcolor
  if (!rosidl_runtime_c__String__copy(
      &(input->fieldcolor), &(output->fieldcolor)))
  {
    return false;
  }
  // dengen
  output->dengen = input->dengen;
  // mode
  if (!rosidl_runtime_c__String__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  // column1
  if (!rosidl_runtime_c__String__copy(
      &(input->column1), &(output->column1)))
  {
    return false;
  }
  // column2
  if (!rosidl_runtime_c__String__copy(
      &(input->column2), &(output->column2)))
  {
    return false;
  }
  // column3
  if (!rosidl_runtime_c__String__copy(
      &(input->column3), &(output->column3)))
  {
    return false;
  }
  // execute
  output->execute = input->execute;
  // refill
  output->refill = input->refill;
  // reload1
  output->reload1 = input->reload1;
  // reload2
  output->reload2 = input->reload2;
  // reload3
  output->reload3 = input->reload3;
  // firehata
  output->firehata = input->firehata;
  // firebaketu
  output->firebaketu = input->firebaketu;
  // hojuposition
  output->hojuposition = input->hojuposition;
  // left
  output->left = input->left;
  // right
  output->right = input->right;
  // up
  output->up = input->up;
  // down
  output->down = input->down;
  // circle
  output->circle = input->circle;
  // triangle
  output->triangle = input->triangle;
  // square
  output->square = input->square;
  // cross
  output->cross = input->cross;
  // l1
  output->l1 = input->l1;
  // l2
  output->l2 = input->l2;
  // r1
  output->r1 = input->r1;
  // r2
  output->r2 = input->r2;
  return true;
}

controller__msg__Controller *
controller__msg__Controller__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  controller__msg__Controller * msg = (controller__msg__Controller *)allocator.allocate(sizeof(controller__msg__Controller), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(controller__msg__Controller));
  bool success = controller__msg__Controller__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
controller__msg__Controller__destroy(controller__msg__Controller * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    controller__msg__Controller__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
controller__msg__Controller__Sequence__init(controller__msg__Controller__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  controller__msg__Controller * data = NULL;

  if (size) {
    data = (controller__msg__Controller *)allocator.zero_allocate(size, sizeof(controller__msg__Controller), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = controller__msg__Controller__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        controller__msg__Controller__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
controller__msg__Controller__Sequence__fini(controller__msg__Controller__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      controller__msg__Controller__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

controller__msg__Controller__Sequence *
controller__msg__Controller__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  controller__msg__Controller__Sequence * array = (controller__msg__Controller__Sequence *)allocator.allocate(sizeof(controller__msg__Controller__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = controller__msg__Controller__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
controller__msg__Controller__Sequence__destroy(controller__msg__Controller__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    controller__msg__Controller__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
controller__msg__Controller__Sequence__are_equal(const controller__msg__Controller__Sequence * lhs, const controller__msg__Controller__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!controller__msg__Controller__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
controller__msg__Controller__Sequence__copy(
  const controller__msg__Controller__Sequence * input,
  controller__msg__Controller__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(controller__msg__Controller);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    controller__msg__Controller * data =
      (controller__msg__Controller *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!controller__msg__Controller__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          controller__msg__Controller__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!controller__msg__Controller__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
