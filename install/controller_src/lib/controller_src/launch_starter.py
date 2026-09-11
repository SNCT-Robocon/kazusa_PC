#!/usr/bin/env python3
import subprocess
import rclpy
from rclpy.node import Node
from controller.msg import Controller
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy

class LaunchStarter(Node):
    def __init__(self):
        super().__init__('launch_starter')
        self.is_launched = False
        qos_profile = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE
        )
        
        self.subscription = self.create_subscription(
            Controller,
            '/controller_val',
            self.controller_callback,
            qos_profile
        )
        self.get_logger().info("Waiting for valid /controller_val topic to start launch...")

    def controller_callback(self, msg: Controller):
        if self.is_launched:
            return

        # 1. コントローラメッセージから map_id または field_color を取得
        raw_map_id = str(getattr(msg, 'fieldcolor', '')).lower()
        # ※ もし Controller.msg 内にスタートボタン等のフラグ（例: msg.start_button）がある場合は、
        #    if not msg.start_button: return のようにチェックを挟むのが最も確実です。

        # self.get_logger().info(f"rawdata:{raw_map_id}")
        # # 2. 明示的に "red" か "blue" が指定されているか判定
        field_color = None
        if "redmap" in raw_map_id:
            field_color = "red"
        elif "bluemap" in raw_map_id:
            field_color = "blue"
        else:
            # 初期値や関係ない文字列（空文字など）が届いている間は起動せずに待機
            return

        # 3. 有効な値が受け取れた場合のみ launch を実行
        self.get_logger().info(f"Received valid topic! Starting launch with field_color: {field_color}")
        self.is_launched = True

        cmd = [
            "ros2", "launch", "launcher", "202689.py",
            f"field_color:={field_color}"
        ]
        
        subprocess.Popen(cmd)

def main(args=None):
    rclpy.init(args=args)
    node = LaunchStarter()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()