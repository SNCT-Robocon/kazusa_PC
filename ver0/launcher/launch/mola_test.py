# my_robot_bringup/launch/mola_localization.launch.py

import os
from launch import LaunchDescription
from launch.actions import SetEnvironmentVariable, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution


def generate_launch_description():
    pipeline_yaml = PathJoinSubstitution([
        FindPackageShare('mola_conf'),
        'config',
        'lidar2d.yaml'
    ])

    mola_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('mola_lidar_odometry'),
                'ros2-launchs',
                'ros2-lidar-odometry.launch.py'
            ])
        ]),
        launch_arguments={
            'lidar_topic_name': '/merged_scan',
            'lidar_topic_type': 'LaserScan',
            'start_active': 'True',
            # 既存のstatic mapを変換した.mmファイルを読み込んでローカリゼーション
            'mola_initial_map_mm_file': PathJoinSubstitution([
                FindPackageShare('mola_conf'),
                'maps',
                'maps.mm'
            ]),
            'publish_localization_following_rep105': 'True',
            'mola_tf_base_link': 'base_link',
        }.items()
    )

    return LaunchDescription([
        SetEnvironmentVariable('MOLA_ODOMETRY_PIPELINE_YAML', pipeline_yaml),
        SetEnvironmentVariable(
            'MOLA_STATE_ESTIMATOR',
            'mola::state_estimation_smoother::StateEstimationSmoother'
        ),
        SetEnvironmentVariable('MOLA_LOCAL_MAP_MAX_SIZE', '15.0'),
        SetEnvironmentVariable('MOLA_ADAPT_THRESHOLD_ALPHA', '0.9'),
        mola_launch,
    ])