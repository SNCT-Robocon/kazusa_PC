# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target custom_msgs::custom_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${custom_msgs_TARGETS}.
if(custom_msgs_TARGETS AND NOT TARGET custom_msgs::custom_msgs)
  add_library(custom_msgs::custom_msgs INTERFACE IMPORTED)
  set_target_properties(custom_msgs::custom_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${custom_msgs_TARGETS}")
endif()
