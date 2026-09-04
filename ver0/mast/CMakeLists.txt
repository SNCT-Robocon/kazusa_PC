cmake_minimum_required(VERSION 3.8)
project(mast)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(custom_msgs REQUIRED)
find_package(controller REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rcl_interfaces REQUIRED)


include_directories(
  include
)

add_executable(mast_node src/mast.cpp)
ament_target_dependencies(mast_node rclcpp sensor_msgs custom_msgs controller geometry_msgs ament_index_cpp std_msgs rclcpp_action)
target_link_libraries(mast_node yaml-cpp)


add_executable(hoju_node src/hoju.cpp)
ament_target_dependencies(hoju_node
  rclcpp
  sensor_msgs
  custom_msgs
  controller
  geometry_msgs
  std_msgs
  rclcpp_action
)



add_executable(path_follow_node src/path_follow.cpp)
ament_target_dependencies(path_follow_node
  rclcpp
  rclcpp_action
  rcl_interfaces
  custom_msgs
  geometry_msgs
  ament_index_cpp
)
target_link_libraries(path_follow_node yaml-cpp)



# add_executable(latency_test_node src/latency_test.cpp)
# ament_target_dependencies(latency_test_node rclcpp custom_msgs controller)

install(
  TARGETS
  mast_node
  hoju_node
  path_follow_node
  # latency_test_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY path/
  DESTINATION share/${PROJECT_NAME}/path
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
