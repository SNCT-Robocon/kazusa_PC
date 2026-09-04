
cmake_minimum_required(VERSION 3.8)
project(my_cart2)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(cartographer_ros REQUIRED)
find_package(cartographer REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(message_filters REQUIRED)
find_package(tf2 REQUIRED)

add_executable(laser_scan_merger_cpp scripts/merge_scan.cpp)
ament_target_dependencies(laser_scan_merger_cpp
  rclcpp sensor_msgs geometry_msgs message_filters tf2 tf2_ros)
# 依存関係をエクスポート
ament_export_dependencies(cartographer_ros cartographer tf2_ros sensor_msgs geometry_msgs nav_msgs)

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


# 設定ファイル (config) をインストール
install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}/
)
install(TARGETS
  laser_scan_merger_cpp
  DESTINATION lib/${PROJECT_NAME}
)
# Python スクリプトをインストール
install(PROGRAMS
  scripts/pose1_pub.py
  scripts/imu_reader.py
  scripts/i2c_pub.py
  scripts/merge_scan.py
  scripts/cartStarter.py
  scripts/cartStarter_static.py
  scripts/odom_fusion.py
  scripts/merge_scan_cpu.py
  scripts/noise_test.py
  scripts/emcl_degree.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
