from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # ユーザーのホームディレクトリからの相対で bag 保存先を取得（環境に依存させないため）
    home_dir = os.path.expanduser('~')
    base_dir = os.path.join(home_dir, "kazusa", "records")
    os.makedirs(base_dir, exist_ok=True)

    # base_dir 内の既存フォルダをチェックして最大番号を取得
    existing = [
        int(name) for name in os.listdir(base_dir)
        if name.isdigit()
    ]
    next_index = max(existing, default=0) + 1
    output_dir = os.path.join(base_dir, str(next_index))

    # --- 各パッケージの share ディレクトリを取得（相対パス化の要） ---
    # ※ もし amcl.yaml や 2026_r.yaml が my_cart2 ではなく
    # 別個の「amcl_config」パッケージにある場合は、そちらのパッケージ名に変えてください。
    my_cart_share = get_package_share_directory("my_cart2")
    amcl_config_pkg = get_package_share_directory("amcl_config")
    cartographer_config_dir = os.path.join(
        get_package_share_directory("my_cart2"),
        "config"
    )
    # 例：パッケージ内の適切なパスを結合
    amcl_config_path = os.path.join(amcl_config_pkg, 'config', 'amcl.yaml')
    map_yaml_path = os.path.join(amcl_config_pkg, 'map', '2026_r_2.yaml')

    color_arg = DeclareLaunchArgument(
        'field_color', 
        default_value='red',
        description='Field color'
    )

    return LaunchDescription([
        color_arg,
        # シミュレーション時間の設定
        DeclareLaunchArgument("use_sim_time", default_value="false", description="Use simulation (Gazebo) clock if true"),
       
          Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{'yaml_filename': map_yaml_path}]
        ),
        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_localization',
            output='screen',
            parameters=[{
                'use_sim_time': LaunchConfiguration('use_sim_time'),
                'autostart': True,
                'node_names': ['map_server']
            }]
        )
,
Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            # x, y, z, yaw, pitch, roll, frame, child
            # 元の x=0.07445, y=0.2317   -> 新しい x=-0.2317, y=0.07445
            # 元の yaw=1.16309  -> 新しい yaw=2.73389
            arguments=["0.0", "0.0", "0", "0.0", "0", "0", "map", "base_link"]
        ),

       
    ])