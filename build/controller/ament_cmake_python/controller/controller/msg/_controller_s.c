// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from controller:msg/Controller.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "controller/msg/detail/controller__struct.h"
#include "controller/msg/detail/controller__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool controller__msg__controller__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("controller.msg._controller.Controller", full_classname_dest, 37) == 0);
  }
  controller__msg__Controller * ros_message = _ros_message;
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // theta
    PyObject * field = PyObject_GetAttrString(_pymsg, "theta");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->theta = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // hata_turn_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "hata_turn_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->hata_turn_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // hata_turn_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "hata_turn_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->hata_turn_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // hata_turn_theta
    PyObject * field = PyObject_GetAttrString(_pymsg, "hata_turn_theta");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->hata_turn_theta = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // baketu_turn_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "baketu_turn_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->baketu_turn_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // baketu_turn_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "baketu_turn_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->baketu_turn_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // baketu_turn_theta
    PyObject * field = PyObject_GetAttrString(_pymsg, "baketu_turn_theta");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->baketu_turn_theta = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // hoju_turn_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "hoju_turn_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->hoju_turn_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // hoju_turn_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "hoju_turn_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->hoju_turn_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // hoju_turn_theta
    PyObject * field = PyObject_GetAttrString(_pymsg, "hoju_turn_theta");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->hoju_turn_theta = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // hata_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "hata_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->hata_speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // baketu_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "baketu_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->baketu_speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // fieldcolor
    PyObject * field = PyObject_GetAttrString(_pymsg, "fieldcolor");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->fieldcolor, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // dengen
    PyObject * field = PyObject_GetAttrString(_pymsg, "dengen");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->dengen = (Py_True == field);
    Py_DECREF(field);
  }
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->mode, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // column1
    PyObject * field = PyObject_GetAttrString(_pymsg, "column1");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->column1, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // column2
    PyObject * field = PyObject_GetAttrString(_pymsg, "column2");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->column2, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // column3
    PyObject * field = PyObject_GetAttrString(_pymsg, "column3");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->column3, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // execute
    PyObject * field = PyObject_GetAttrString(_pymsg, "execute");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->execute = (Py_True == field);
    Py_DECREF(field);
  }
  {  // refill
    PyObject * field = PyObject_GetAttrString(_pymsg, "refill");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->refill = (Py_True == field);
    Py_DECREF(field);
  }
  {  // reload1
    PyObject * field = PyObject_GetAttrString(_pymsg, "reload1");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->reload1 = (Py_True == field);
    Py_DECREF(field);
  }
  {  // reload2
    PyObject * field = PyObject_GetAttrString(_pymsg, "reload2");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->reload2 = (Py_True == field);
    Py_DECREF(field);
  }
  {  // reload3
    PyObject * field = PyObject_GetAttrString(_pymsg, "reload3");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->reload3 = (Py_True == field);
    Py_DECREF(field);
  }
  {  // firehata
    PyObject * field = PyObject_GetAttrString(_pymsg, "firehata");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->firehata = (Py_True == field);
    Py_DECREF(field);
  }
  {  // firebaketu
    PyObject * field = PyObject_GetAttrString(_pymsg, "firebaketu");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->firebaketu = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hojuposition
    PyObject * field = PyObject_GetAttrString(_pymsg, "hojuposition");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hojuposition = (Py_True == field);
    Py_DECREF(field);
  }
  {  // left
    PyObject * field = PyObject_GetAttrString(_pymsg, "left");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->left = (Py_True == field);
    Py_DECREF(field);
  }
  {  // right
    PyObject * field = PyObject_GetAttrString(_pymsg, "right");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->right = (Py_True == field);
    Py_DECREF(field);
  }
  {  // up
    PyObject * field = PyObject_GetAttrString(_pymsg, "up");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->up = (Py_True == field);
    Py_DECREF(field);
  }
  {  // down
    PyObject * field = PyObject_GetAttrString(_pymsg, "down");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->down = (Py_True == field);
    Py_DECREF(field);
  }
  {  // circle
    PyObject * field = PyObject_GetAttrString(_pymsg, "circle");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->circle = (Py_True == field);
    Py_DECREF(field);
  }
  {  // triangle
    PyObject * field = PyObject_GetAttrString(_pymsg, "triangle");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->triangle = (Py_True == field);
    Py_DECREF(field);
  }
  {  // square
    PyObject * field = PyObject_GetAttrString(_pymsg, "square");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->square = (Py_True == field);
    Py_DECREF(field);
  }
  {  // cross
    PyObject * field = PyObject_GetAttrString(_pymsg, "cross");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->cross = (Py_True == field);
    Py_DECREF(field);
  }
  {  // l1
    PyObject * field = PyObject_GetAttrString(_pymsg, "l1");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->l1 = (Py_True == field);
    Py_DECREF(field);
  }
  {  // l2
    PyObject * field = PyObject_GetAttrString(_pymsg, "l2");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->l2 = (Py_True == field);
    Py_DECREF(field);
  }
  {  // r1
    PyObject * field = PyObject_GetAttrString(_pymsg, "r1");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->r1 = (Py_True == field);
    Py_DECREF(field);
  }
  {  // r2
    PyObject * field = PyObject_GetAttrString(_pymsg, "r2");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->r2 = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * controller__msg__controller__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Controller */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("controller.msg._controller");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Controller");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  controller__msg__Controller * ros_message = (controller__msg__Controller *)raw_ros_message;
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // theta
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->theta);
    {
      int rc = PyObject_SetAttrString(_pymessage, "theta", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hata_turn_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->hata_turn_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hata_turn_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hata_turn_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->hata_turn_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hata_turn_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hata_turn_theta
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->hata_turn_theta);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hata_turn_theta", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // baketu_turn_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->baketu_turn_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "baketu_turn_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // baketu_turn_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->baketu_turn_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "baketu_turn_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // baketu_turn_theta
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->baketu_turn_theta);
    {
      int rc = PyObject_SetAttrString(_pymessage, "baketu_turn_theta", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hoju_turn_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->hoju_turn_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hoju_turn_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hoju_turn_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->hoju_turn_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hoju_turn_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hoju_turn_theta
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->hoju_turn_theta);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hoju_turn_theta", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hata_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->hata_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hata_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // baketu_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->baketu_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "baketu_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fieldcolor
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->fieldcolor.data,
      strlen(ros_message->fieldcolor.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "fieldcolor", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dengen
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->dengen ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dengen", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mode
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->mode.data,
      strlen(ros_message->mode.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // column1
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->column1.data,
      strlen(ros_message->column1.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "column1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // column2
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->column2.data,
      strlen(ros_message->column2.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "column2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // column3
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->column3.data,
      strlen(ros_message->column3.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "column3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // execute
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->execute ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "execute", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // refill
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->refill ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "refill", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reload1
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->reload1 ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reload1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reload2
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->reload2 ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reload2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reload3
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->reload3 ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reload3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // firehata
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->firehata ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "firehata", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // firebaketu
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->firebaketu ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "firebaketu", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hojuposition
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hojuposition ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hojuposition", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->left ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->right ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // up
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->up ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "up", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // down
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->down ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "down", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // circle
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->circle ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "circle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // triangle
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->triangle ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "triangle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // square
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->square ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "square", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cross
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->cross ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cross", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // l1
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->l1 ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "l1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // l2
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->l2 ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "l2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // r1
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->r1 ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "r1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // r2
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->r2 ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "r2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
