// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from controller:msg/Controller.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER__MSG__DETAIL__CONTROLLER__STRUCT_HPP_
#define CONTROLLER__MSG__DETAIL__CONTROLLER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__controller__msg__Controller __attribute__((deprecated))
#else
# define DEPRECATED__controller__msg__Controller __declspec(deprecated)
#endif

namespace controller
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Controller_
{
  using Type = Controller_<ContainerAllocator>;

  explicit Controller_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->theta = 0.0f;
      this->hata_turn_x = 0.0f;
      this->hata_turn_y = 0.0f;
      this->hata_turn_theta = 0.0f;
      this->baketu_turn_x = 0.0f;
      this->baketu_turn_y = 0.0f;
      this->baketu_turn_theta = 0.0f;
      this->hoju_turn_x = 0.0f;
      this->hoju_turn_y = 0.0f;
      this->hoju_turn_theta = 0.0f;
      this->hata_speed = 0.0f;
      this->baketu_speed = 0.0f;
      this->fieldcolor = "";
      this->dengen = false;
      this->mode = "";
      this->column1 = "";
      this->column2 = "";
      this->column3 = "";
      this->execute = false;
      this->refill = false;
      this->reload1 = false;
      this->reload2 = false;
      this->reload3 = false;
      this->firehata = false;
      this->firebaketu = false;
      this->hojuposition = false;
      this->left = false;
      this->right = false;
      this->up = false;
      this->down = false;
      this->circle = false;
      this->triangle = false;
      this->square = false;
      this->cross = false;
      this->l1 = false;
      this->l2 = false;
      this->r1 = false;
      this->r2 = false;
    }
  }

  explicit Controller_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fieldcolor(_alloc),
    mode(_alloc),
    column1(_alloc),
    column2(_alloc),
    column3(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->theta = 0.0f;
      this->hata_turn_x = 0.0f;
      this->hata_turn_y = 0.0f;
      this->hata_turn_theta = 0.0f;
      this->baketu_turn_x = 0.0f;
      this->baketu_turn_y = 0.0f;
      this->baketu_turn_theta = 0.0f;
      this->hoju_turn_x = 0.0f;
      this->hoju_turn_y = 0.0f;
      this->hoju_turn_theta = 0.0f;
      this->hata_speed = 0.0f;
      this->baketu_speed = 0.0f;
      this->fieldcolor = "";
      this->dengen = false;
      this->mode = "";
      this->column1 = "";
      this->column2 = "";
      this->column3 = "";
      this->execute = false;
      this->refill = false;
      this->reload1 = false;
      this->reload2 = false;
      this->reload3 = false;
      this->firehata = false;
      this->firebaketu = false;
      this->hojuposition = false;
      this->left = false;
      this->right = false;
      this->up = false;
      this->down = false;
      this->circle = false;
      this->triangle = false;
      this->square = false;
      this->cross = false;
      this->l1 = false;
      this->l2 = false;
      this->r1 = false;
      this->r2 = false;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _theta_type =
    float;
  _theta_type theta;
  using _hata_turn_x_type =
    float;
  _hata_turn_x_type hata_turn_x;
  using _hata_turn_y_type =
    float;
  _hata_turn_y_type hata_turn_y;
  using _hata_turn_theta_type =
    float;
  _hata_turn_theta_type hata_turn_theta;
  using _baketu_turn_x_type =
    float;
  _baketu_turn_x_type baketu_turn_x;
  using _baketu_turn_y_type =
    float;
  _baketu_turn_y_type baketu_turn_y;
  using _baketu_turn_theta_type =
    float;
  _baketu_turn_theta_type baketu_turn_theta;
  using _hoju_turn_x_type =
    float;
  _hoju_turn_x_type hoju_turn_x;
  using _hoju_turn_y_type =
    float;
  _hoju_turn_y_type hoju_turn_y;
  using _hoju_turn_theta_type =
    float;
  _hoju_turn_theta_type hoju_turn_theta;
  using _hata_speed_type =
    float;
  _hata_speed_type hata_speed;
  using _baketu_speed_type =
    float;
  _baketu_speed_type baketu_speed;
  using _fieldcolor_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _fieldcolor_type fieldcolor;
  using _dengen_type =
    bool;
  _dengen_type dengen;
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;
  using _column1_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _column1_type column1;
  using _column2_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _column2_type column2;
  using _column3_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _column3_type column3;
  using _execute_type =
    bool;
  _execute_type execute;
  using _refill_type =
    bool;
  _refill_type refill;
  using _reload1_type =
    bool;
  _reload1_type reload1;
  using _reload2_type =
    bool;
  _reload2_type reload2;
  using _reload3_type =
    bool;
  _reload3_type reload3;
  using _firehata_type =
    bool;
  _firehata_type firehata;
  using _firebaketu_type =
    bool;
  _firebaketu_type firebaketu;
  using _hojuposition_type =
    bool;
  _hojuposition_type hojuposition;
  using _left_type =
    bool;
  _left_type left;
  using _right_type =
    bool;
  _right_type right;
  using _up_type =
    bool;
  _up_type up;
  using _down_type =
    bool;
  _down_type down;
  using _circle_type =
    bool;
  _circle_type circle;
  using _triangle_type =
    bool;
  _triangle_type triangle;
  using _square_type =
    bool;
  _square_type square;
  using _cross_type =
    bool;
  _cross_type cross;
  using _l1_type =
    bool;
  _l1_type l1;
  using _l2_type =
    bool;
  _l2_type l2;
  using _r1_type =
    bool;
  _r1_type r1;
  using _r2_type =
    bool;
  _r2_type r2;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__theta(
    const float & _arg)
  {
    this->theta = _arg;
    return *this;
  }
  Type & set__hata_turn_x(
    const float & _arg)
  {
    this->hata_turn_x = _arg;
    return *this;
  }
  Type & set__hata_turn_y(
    const float & _arg)
  {
    this->hata_turn_y = _arg;
    return *this;
  }
  Type & set__hata_turn_theta(
    const float & _arg)
  {
    this->hata_turn_theta = _arg;
    return *this;
  }
  Type & set__baketu_turn_x(
    const float & _arg)
  {
    this->baketu_turn_x = _arg;
    return *this;
  }
  Type & set__baketu_turn_y(
    const float & _arg)
  {
    this->baketu_turn_y = _arg;
    return *this;
  }
  Type & set__baketu_turn_theta(
    const float & _arg)
  {
    this->baketu_turn_theta = _arg;
    return *this;
  }
  Type & set__hoju_turn_x(
    const float & _arg)
  {
    this->hoju_turn_x = _arg;
    return *this;
  }
  Type & set__hoju_turn_y(
    const float & _arg)
  {
    this->hoju_turn_y = _arg;
    return *this;
  }
  Type & set__hoju_turn_theta(
    const float & _arg)
  {
    this->hoju_turn_theta = _arg;
    return *this;
  }
  Type & set__hata_speed(
    const float & _arg)
  {
    this->hata_speed = _arg;
    return *this;
  }
  Type & set__baketu_speed(
    const float & _arg)
  {
    this->baketu_speed = _arg;
    return *this;
  }
  Type & set__fieldcolor(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->fieldcolor = _arg;
    return *this;
  }
  Type & set__dengen(
    const bool & _arg)
  {
    this->dengen = _arg;
    return *this;
  }
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__column1(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->column1 = _arg;
    return *this;
  }
  Type & set__column2(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->column2 = _arg;
    return *this;
  }
  Type & set__column3(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->column3 = _arg;
    return *this;
  }
  Type & set__execute(
    const bool & _arg)
  {
    this->execute = _arg;
    return *this;
  }
  Type & set__refill(
    const bool & _arg)
  {
    this->refill = _arg;
    return *this;
  }
  Type & set__reload1(
    const bool & _arg)
  {
    this->reload1 = _arg;
    return *this;
  }
  Type & set__reload2(
    const bool & _arg)
  {
    this->reload2 = _arg;
    return *this;
  }
  Type & set__reload3(
    const bool & _arg)
  {
    this->reload3 = _arg;
    return *this;
  }
  Type & set__firehata(
    const bool & _arg)
  {
    this->firehata = _arg;
    return *this;
  }
  Type & set__firebaketu(
    const bool & _arg)
  {
    this->firebaketu = _arg;
    return *this;
  }
  Type & set__hojuposition(
    const bool & _arg)
  {
    this->hojuposition = _arg;
    return *this;
  }
  Type & set__left(
    const bool & _arg)
  {
    this->left = _arg;
    return *this;
  }
  Type & set__right(
    const bool & _arg)
  {
    this->right = _arg;
    return *this;
  }
  Type & set__up(
    const bool & _arg)
  {
    this->up = _arg;
    return *this;
  }
  Type & set__down(
    const bool & _arg)
  {
    this->down = _arg;
    return *this;
  }
  Type & set__circle(
    const bool & _arg)
  {
    this->circle = _arg;
    return *this;
  }
  Type & set__triangle(
    const bool & _arg)
  {
    this->triangle = _arg;
    return *this;
  }
  Type & set__square(
    const bool & _arg)
  {
    this->square = _arg;
    return *this;
  }
  Type & set__cross(
    const bool & _arg)
  {
    this->cross = _arg;
    return *this;
  }
  Type & set__l1(
    const bool & _arg)
  {
    this->l1 = _arg;
    return *this;
  }
  Type & set__l2(
    const bool & _arg)
  {
    this->l2 = _arg;
    return *this;
  }
  Type & set__r1(
    const bool & _arg)
  {
    this->r1 = _arg;
    return *this;
  }
  Type & set__r2(
    const bool & _arg)
  {
    this->r2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    controller::msg::Controller_<ContainerAllocator> *;
  using ConstRawPtr =
    const controller::msg::Controller_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<controller::msg::Controller_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<controller::msg::Controller_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      controller::msg::Controller_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<controller::msg::Controller_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      controller::msg::Controller_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<controller::msg::Controller_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<controller::msg::Controller_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<controller::msg::Controller_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__controller__msg__Controller
    std::shared_ptr<controller::msg::Controller_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__controller__msg__Controller
    std::shared_ptr<controller::msg::Controller_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Controller_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    if (this->hata_turn_x != other.hata_turn_x) {
      return false;
    }
    if (this->hata_turn_y != other.hata_turn_y) {
      return false;
    }
    if (this->hata_turn_theta != other.hata_turn_theta) {
      return false;
    }
    if (this->baketu_turn_x != other.baketu_turn_x) {
      return false;
    }
    if (this->baketu_turn_y != other.baketu_turn_y) {
      return false;
    }
    if (this->baketu_turn_theta != other.baketu_turn_theta) {
      return false;
    }
    if (this->hoju_turn_x != other.hoju_turn_x) {
      return false;
    }
    if (this->hoju_turn_y != other.hoju_turn_y) {
      return false;
    }
    if (this->hoju_turn_theta != other.hoju_turn_theta) {
      return false;
    }
    if (this->hata_speed != other.hata_speed) {
      return false;
    }
    if (this->baketu_speed != other.baketu_speed) {
      return false;
    }
    if (this->fieldcolor != other.fieldcolor) {
      return false;
    }
    if (this->dengen != other.dengen) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->column1 != other.column1) {
      return false;
    }
    if (this->column2 != other.column2) {
      return false;
    }
    if (this->column3 != other.column3) {
      return false;
    }
    if (this->execute != other.execute) {
      return false;
    }
    if (this->refill != other.refill) {
      return false;
    }
    if (this->reload1 != other.reload1) {
      return false;
    }
    if (this->reload2 != other.reload2) {
      return false;
    }
    if (this->reload3 != other.reload3) {
      return false;
    }
    if (this->firehata != other.firehata) {
      return false;
    }
    if (this->firebaketu != other.firebaketu) {
      return false;
    }
    if (this->hojuposition != other.hojuposition) {
      return false;
    }
    if (this->left != other.left) {
      return false;
    }
    if (this->right != other.right) {
      return false;
    }
    if (this->up != other.up) {
      return false;
    }
    if (this->down != other.down) {
      return false;
    }
    if (this->circle != other.circle) {
      return false;
    }
    if (this->triangle != other.triangle) {
      return false;
    }
    if (this->square != other.square) {
      return false;
    }
    if (this->cross != other.cross) {
      return false;
    }
    if (this->l1 != other.l1) {
      return false;
    }
    if (this->l2 != other.l2) {
      return false;
    }
    if (this->r1 != other.r1) {
      return false;
    }
    if (this->r2 != other.r2) {
      return false;
    }
    return true;
  }
  bool operator!=(const Controller_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Controller_

// alias to use template instance with default allocator
using Controller =
  controller::msg::Controller_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace controller

#endif  // CONTROLLER__MSG__DETAIL__CONTROLLER__STRUCT_HPP_
