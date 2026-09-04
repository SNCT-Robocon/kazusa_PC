# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target controller::controller
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${controller_TARGETS}.
if(controller_TARGETS AND NOT TARGET controller::controller)
  add_library(controller::controller INTERFACE IMPORTED)
  set_target_properties(controller::controller PROPERTIES
    INTERFACE_LINK_LIBRARIES "${controller_TARGETS}")
endif()
