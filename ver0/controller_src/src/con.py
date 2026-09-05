#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import socket
import json
import time

from geometry_msgs.msg import Pose2D
from rcl_interfaces.msg import Log
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from controller.msg import Controller
from std_msgs.msg import String


class UDPToCmdVel(Node):

    def __init__(self):
        super().__init__('udp_to_controller')

        qos_profile = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE
        )

        # Publisher / Subscriber
        self.pub = self.create_publisher(
            Controller, '/controller_val', qos_profile
        )

        self.sub = self.create_subscription(
            Pose2D, 'pose1', self.pose_callback, qos_profile
        )

        self.sub_str = self.create_subscription(
            String, '/log', self.str_callback, qos_profile
        )

        # /logへ通知するためのPublisher
        self.log_publisher = self.create_publisher(
            String, '/log', 10
        )

        # EMCL2 /rosout監視
        self.rosout_sub = self.create_subscription(
            Log,
            '/rosout',
            self.rosout_callback,
            1000
        )

        # EMCL2 RESET連続回数
        self.reset_streak = 0
        self.last_reset_time = 0.0
        # UDP設定
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind(("0.0.0.0", 5005))
        self.sock.setblocking(False)

        self.log_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

        # 状態保持
        self.last_recv = time.time()
        self.remote_addr = None

        self.current_pose = {
            "x": 0.0,
            "y": 0.0,
            "theta": 0.0
        }

        self.timer = self.create_timer(0.009, self.loop)

        self.get_logger().info(
            "UDP node started - Waiting for packets..."
        )

    def pose_callback(self, msg):
        """pose1を受信したときに呼ばれる"""
        self.current_pose["x"] = msg.x
        self.current_pose["y"] = msg.y
        self.current_pose["theta"] = msg.theta

    def str_callback(self, msg):
        """/logを受信したら、その瞬間にUDP送信"""

        if self.remote_addr is None:
            return

        log_data = msg.data

        if not log_data or log_data == "none":
            return

        response_json = json.dumps({
            "log": log_data
        })

        try:
            self.log_sock.sendto(
                response_json.encode(),
                (self.remote_addr[0], 5006)
            )

        except Exception as e:
            self.get_logger().warn(
                f"log send error: {e}"
            )

    def rosout_callback(self, msg):

        is_emcl_reset = (
            msg.name == 'emcl2_node'
            and msg.msg.strip() == 'RESET'
            and 'ExpResetMcl2.cpp' in msg.file
        )

        if not is_emcl_reset:
            return

        now = time.time()

        # 前回のRESETから1秒以上空いていたら連続回数をリセット
        if now - self.last_reset_time > 1.0:
            self.reset_streak = 0

        self.reset_streak += 1
        self.last_reset_time = now

        self.get_logger().info(
            f'EMCL RESET streak: {self.reset_streak}'
        )

        if self.reset_streak % 10 == 0:
            warning_msg = String()
            warning_msg.data = "マッチング率低下"
            self.log_publisher.publish(warning_msg)

            self.get_logger().warn(
                f'EMCL RESETが{self.reset_streak}回連続しました: '
                'マッチング率低下'
            )
    def loop(self):
        now = time.time()

        try:
            data, addr = self.sock.recvfrom(1024)
            self.remote_addr = addr

            msg_dict = json.loads(data.decode())

            ctrl = Controller()

            ctrl.x = msg_dict.get("vx", 0.0)
            ctrl.y = msg_dict.get("vy", 0.0)
            ctrl.theta = msg_dict.get("w", 0.0)

            ctrl.dengen = msg_dict.get("t0", False)
            ctrl.firehata = msg_dict.get("firehata", False)
            ctrl.firebaketu = msg_dict.get("firebaketu", False)
            ctrl.refill = msg_dict.get("refill", False)
            ctrl.execute = msg_dict.get("execute", False)
            ctrl.mode = msg_dict.get("mode", "none")

            ctrl.column1 = msg_dict.get("column1", "none")
            ctrl.column2 = msg_dict.get("column2", "none")
            ctrl.column3 = msg_dict.get("column3", "none")

            ctrl.reload1 = msg_dict.get("reload1", False)
            ctrl.reload2 = msg_dict.get("reload2", False)
            ctrl.reload3 = msg_dict.get("reload3", False)

            ctrl.left = msg_dict.get("left", False)
            ctrl.right = msg_dict.get("right", False)
            ctrl.up = msg_dict.get("up", False)
            ctrl.down = msg_dict.get("down", False)

            ctrl.circle = msg_dict.get("circle", False)
            ctrl.triangle = msg_dict.get("triangle", False)
            ctrl.square = msg_dict.get("square", False)
            ctrl.cross = msg_dict.get("cross", False)

            ctrl.l1 = msg_dict.get("l1", False)
            ctrl.l2 = msg_dict.get("l2", False)
            ctrl.r1 = msg_dict.get("r1", False)
            ctrl.r2 = msg_dict.get("r2", False)

            ctrl.baketu_turn_x = msg_dict.get(
                "baketu_turnx", 0.0
            )
            ctrl.baketu_turn_y = msg_dict.get(
                "baketu_turny", 0.0
            )
            ctrl.baketu_turn_theta = msg_dict.get(
                "baketu_turntheta", 0.0
            )

            ctrl.hata_turn_x = msg_dict.get(
                "hata_turnx", 0.0
            )
            ctrl.hata_turn_y = msg_dict.get(
                "hata_turny", 0.0
            )
            ctrl.hata_turn_theta = msg_dict.get(
                "hata_turntheta", 0.0
            )

            ctrl.hoju_turn_x = msg_dict.get(
                "hoju_turnx", 0.0
            )
            ctrl.hoju_turn_y = msg_dict.get(
                "hoju_turny", 0.0
            )
            ctrl.hoju_turn_theta = msg_dict.get(
                "hoju_turntheta", 0.0
            )

            ctrl.hata_speed = msg_dict.get(
                "hata_speed", 0.0
            )
            ctrl.baketu_speed = msg_dict.get(
                "baketu_speed", 0.0
            )

            ctrl.hojuposition = msg_dict.get(
                "HojuPosition", False
            )

            ctrl.fieldcolor = msg_dict.get(
                "map_id", "none"
            )

            self.pub.publish(ctrl)

            # pose1をUDPで送り返す
            response_json = json.dumps(
                self.current_pose
            )

            self.sock.sendto(
                response_json.encode(),
                addr
            )

            self.last_recv = now

        except BlockingIOError:
            pass

        except Exception as e:
            self.get_logger().warn(
                f"parse error: {e}"
            )

        # 通信途絶時停止
        if now - self.last_recv > 0.5:
            stop_ctrl = Controller()
            self.pub.publish(stop_ctrl)


def main():
    rclpy.init()

    node = UDPToCmdVel()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
