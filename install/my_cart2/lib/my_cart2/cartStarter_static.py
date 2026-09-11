#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
import subprocess
import signal
import time
import os
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from tf2_ros import Buffer, TransformListener, LookupException, ConnectivityException, ExtrapolationException, DurabilityPolicy


class CartStarter(Node):
    def __init__(self):
        super().__init__('cart_starter')
        self.get_logger().info('CartStarter started.')

        qos_profile = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE
        )

        self.sub = self.create_subscription(Bool, '/cartrigger', self.callback, qos_profile)
        self.launched = False
        self.process_cart = None
        self.process_bag = None
        self.process_imu = None

        # rosbag保存ディレクトリを準備
        self.base_dir = "/home/suzuka/kannon/records"
        os.makedirs(self.base_dir, exist_ok=True)

    def start_rosbag(self):
        existing = [int(name) for name in os.listdir(self.base_dir) if name.isdigit()]
        next_index = max(existing, default=0) + 1
        output_dir = os.path.join(self.base_dir, str(next_index))

        self.get_logger().info(f'Starting rosbag recording in {output_dir}')
        return subprocess.Popen(['ros2', 'bag', 'record', '-a', '-o', output_dir])

    def start_autosetimu(self):
        script_path = '/home/suzuka/autoset_imu_offset.py'
        if not os.path.exists(script_path):
            self.get_logger().error(f'IMU script not found: {script_path}')
            return None
        self.get_logger().info('Starting autoset_imu_offset.py')
        return subprocess.Popen(['python3', script_path])

    def stop_process(self, proc, name):
        if proc is None:
            return
        try:
            proc.send_signal(signal.SIGINT)
            self.get_logger().info(f'Sent SIGINT to {name}')
            time.sleep(3)

            if proc.poll() is None:
                self.get_logger().warn(f'{name} still alive, sending SIGTERM...')
                proc.terminate()
                time.sleep(3)

            if proc.poll() is None:
                self.get_logger().error(f'Force killing {name}...')
                proc.kill()

            proc.wait(timeout=5)
            self.get_logger().info(f'{name} terminated.')
        except Exception as e:
            self.get_logger().error(f'Failed to terminate {name}: {e}')

    def callback(self, msg):
        if msg.data and not self.launched:
            self.get_logger().info('Received "True". Launching target node, rosbag, and IMU offset...')
            self.process_cart = subprocess.Popen(['ros2', 'launch', 'launcher', 'cartALONE_static.py'])
            self.process_bag = self.start_rosbag()
            self.process_imu = self.start_autosetimu()
            self.launched = True

        elif not msg.data and self.launched:
            self.get_logger().info('Received "False". Terminating all processes...')
            self.stop_process(self.process_cart, "cart process")
            self.stop_process(self.process_bag, "rosbag")
            self.stop_process(self.process_imu, "autoset_imu_offset.py")

            self.process_cart = None
            self.process_bag = None
            self.process_imu = None
            self.launched = False


def main(args=None):
    try:
        rclpy.init(args=args)
        node = CartStarter()
        rclpy.spin(node)
    except Exception as e:
        print(f"[ERROR] {e}")
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
