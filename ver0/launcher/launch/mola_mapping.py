

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
            'start_mapping_enabled': 'True',        # マッピング有効化
            'generate_simplemap': 'True',            # .simplemap を生成
            'publish_localization_following_rep105': 'False',  # マッピング中はTF競合させない
            'mola_tf_base_link': 'base_link',
            'use_sim_time': 'true',                  # rosbag再生時刻に同期
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
        SetEnvironmentVariable('MOLA_SIMPLEMAP_OUTPUT', '/home/suzuka/kazusa/maps/my_map.simplemap'),
        SetEnvironmentVariable('MOLA_SIMPLEMAP_GENERATE_LAZY_LOAD', 'true'),
        mola_launch,
    ])