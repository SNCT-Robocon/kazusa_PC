#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
import subprocess
import signal
import time
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
        self.process = None
     

    def callback(self, msg):
        # Trueで起動
        if msg.data and not self.launched:
            self.get_logger().info('Received "True". Launching target node...')
            self.process = subprocess.Popen(['ros2', 'launch', 'launcher', 'cartALONE.py'])
            self.launched = True

        # Falseで停止
        elif not msg.data and self.launched:
            self.get_logger().info('Received "False". Terminating target node...')
            if self.process is not None:
                try:
                    # SIGINTを送ってみる
                    self.process.send_signal(signal.SIGINT)
                    self.get_logger().info('Sent SIGINT to target process...')
                    time.sleep(3)

                    # 終了していなければSIGTERMを送る
                    if self.process.poll() is None:
                        self.get_logger().warn('Process still alive, sending SIGTERM...')
                        self.process.terminate()
                        time.sleep(3)

                    # それでもダメならkill
                    if self.process.poll() is None:
                        self.get_logger().error('Force killing target process...')
                        self.process.kill()

                    self.process.wait(timeout=5)
                    self.get_logger().info('Target node terminated.')
                except Exception as e:
                    self.get_logger().error(f'Failed to terminate process: {e}')
                finally:
                    self.process = None
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
