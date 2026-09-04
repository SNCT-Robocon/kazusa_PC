
include "map_builder.lua"
include "trajectory_builder.lua"

options = {
  map_builder = MAP_BUILDER,
  trajectory_builder = TRAJECTORY_BUILDER,
  map_frame = "odom",
  tracking_frame = "base_link",
  published_frame = "base_link",
  odom_frame = "odom",
  provide_odom_frame = false,
  publish_frame_projected_to_2d = true,
  use_pose_extrapolator = true,
  use_odometry = false,
  use_nav_sat = false,
  use_landmarks = false,
  num_laser_scans = 1,
  num_multi_echo_laser_scans = 0,
  num_subdivisions_per_laser_scan = 1,
  num_point_clouds = 0,
  lookup_transform_timeout_sec = 0.2,
  submap_publish_period_sec = 0.3,
  pose_publish_period_sec = 5e-3,
  trajectory_publish_period_sec = 30e-3,
  rangefinder_sampling_ratio = 1.,
  odometry_sampling_ratio = 1.,
  fixed_frame_pose_sampling_ratio = 1.,
  imu_sampling_ratio = 1.,
  landmarks_sampling_ratio = 1.,
  
  --pure_localization = false,
}

MAP_BUILDER.use_trajectory_builder_2d = true

TRAJECTORY_BUILDER_2D.use_imu_data = false


--added

TRAJECTORY_BUILDER_2D.min_range = 0.
TRAJECTORY_BUILDER_2D.max_range = 13.                     -- 自分の Lidar の性能に合わせる。 LD06 Lidar なら 12m + α
-- TRAJECTORY_BUILDER_2D.missing_data_ray_length = 5      --'max_range' を超える点は、この長さで空白部として挿入されます。

TRAJECTORY_BUILDER_2D.use_online_correlative_scan_matching = true    -- 相関スキャンマッチャーというのを有効にします。
TRAJECTORY_BUILDER_2D.num_accumulated_range_data = 2                 -- 1 (歪み対策。増やすとレスポンス低下したので 1 or 2?)


TRAJECTORY_BUILDER_2D.real_time_correlative_scan_matcher.linear_search_window = 0.3
                                                                   -- デフォルト: 0.1 -> 0.15
TRAJECTORY_BUILDER_2D.real_time_correlative_scan_matcher.angular_search_window = math.rad(15)
                                                                   -- デフォルト: math.rad(20.) -> math.rad(35.)
-- これを追加（バックグラウンドの全体最適化を無効化）
POSE_GRAPH.optimize_every_n_nodes = 0              -- デフォルト: 1e1 -> 1e3
TRAJECTORY_BUILDER_2D.ceres_scan_matcher.occupied_space_weight = 10
                                                                   -- デフォルト: 1.  -> 10
TRAJECTORY_BUILDER_2D.submaps.num_range_data = 40               -- デフォルト: 90  -> 
TRAJECTORY_BUILDER_2D.motion_filter.max_distance_meters = 0.1      -- デフォルト: 0.2 -> 0.1
TRAJECTORY_BUILDER_2D.motion_filter.max_angle_radians = math.rad(0.2)
                                                                   -- デフォルト: math.rad(1.) -> math.rad(0.2)
TRAJECTORY_BUILDER_2D.ceres_scan_matcher.rotation_weight = 1
TRAJECTORY_BUILDER_2D.ceres_scan_matcher.translation_weight = 1
TRAJECTORY_BUILDER_2D.real_time_correlative_scan_matcher.rotation_delta_cost_weight = 1e-1
TRAJECTORY_BUILDER_2D.real_time_correlative_scan_matcher.translation_delta_cost_weight = 5e-1
TRAJECTORY_BUILDER_2D.adaptive_voxel_filter.max_length = 0.3

return options
