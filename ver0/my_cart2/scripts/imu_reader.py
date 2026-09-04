#!/usr/bin/env python3
import serial
import struct
import math
import tf_transformations
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped
import time

SERIAL_PORT = "/dev/ttyTHS0"
BAUD_RATE = 115200
GRAVITY = 9.8  # 重力加速度 (m/s²)
IMU_READ_RATE = 0.027  # 36Hz (適宜調整)

class IMUReader(Node):
    def __init__(self):
        super().__init__("imu_reader")
        self.publisher_ = self.create_publisher(Imu, "/imu", 10)
        self.tf_broadcaster = TransformBroadcaster(self)  # tf2 broadcaster
        self.ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        self.get_logger().info(f"Listening on {SERIAL_PORT} at {BAUD_RATE} baud...")
        self.publish_count = 0  # パブリッシュカウント
        # 定期実行タイマー (20Hz)
        self.create_timer(IMU_READ_RATE, self.read_imu_data)
        # 1秒ごとにパブリッシュ回数をリセット
        self.create_timer(1.0, self.reset_publish_counter)

    def broadcast_imu_tf(self, timestamp):
        t = TransformStamped()
        t.header.stamp = timestamp  # IMUメッセージのタイムスタンプと同期
        t.header.frame_id = "base_link"  # IMUの基準フレーム
        t.child_frame_id = "imu_link"    # IMUのフレーム

        # IMUの位置 (適宜修正)
        t.transform.translation.x = 0.0
        t.transform.translation.y = 0.0
        t.transform.translation.z = 0.2# IMUの高さ

        # 回転は不要なら identity に
        t.transform.rotation.x = 0.0
        t.transform.rotation.y = 0.0
        t.transform.rotation.z = 0.0
        t.transform.rotation.w = 1.0

        self.tf_broadcaster.sendTransform(t)

    def parse_imu_data(self, data):
        if len(data) < 11:
            return
        
        if data[0] == 0x55:  # ヘッダ確認
            data_type = data[1]
            values = struct.unpack("<hhh", data[2:8])  # 2バイト × 3 データ
            imu_msg = Imu()
            timestamp = self.get_clock().now().to_msg()  # タイムスタンプを変数に保存
            imu_msg.header.stamp = timestamp  # IMUメッセージのタイムスタンプをセット
            imu_msg.header.frame_id = "imu_link"

            if data_type == 0x51:  # 加速度データ
                self.accel_data = [
                    values[0] / 32768.0 * 16 * GRAVITY,
                    values[1] / 32768.0 * 16 * GRAVITY,
                    values[2] / 32768.0 * 16 * GRAVITY,
                ]

            elif data_type == 0x52:  # 角速度データ
                self.gyro_data = [
                    math.radians(values[0] / 32768.0 * 2000),
                    math.radians(values[1] / 32768.0 * 2000),
                    math.radians(values[2] / 32768.0 * 2000),
                ]

            elif data_type == 0x53:  # 姿勢角データ (Roll, Pitch, Yaw)
                roll = math.radians(values[0] / 32768.0 * 180.0)
                pitch = math.radians(values[1] / 32768.0 * 180.0)
                yaw = math.radians(values[2] / 32768.0 * 180.0)

                q = tf_transformations.quaternion_from_euler(roll, pitch, yaw)
                self.orientation_data = [q[0], q[1], q[2], q[3]]

            # すべてのデータが更新されたらパブリッシュ
            if hasattr(self, 'accel_data') and hasattr(self, 'gyro_data') and hasattr(self, 'orientation_data'):
                imu_msg.linear_acceleration.x = self.accel_data[0]
                imu_msg.linear_acceleration.y = self.accel_data[1]
                imu_msg.linear_acceleration.z = self.accel_data[2]
                imu_msg.angular_velocity.x = self.gyro_data[0]
                imu_msg.angular_velocity.y = self.gyro_data[1]
                imu_msg.angular_velocity.z = self.gyro_data[2]
                imu_msg.orientation.x = self.orientation_data[0]
                imu_msg.orientation.y = self.orientation_data[1]
                imu_msg.orientation.z = self.orientation_data[2]
                imu_msg.orientation.w = self.orientation_data[3]

                self.publisher_.publish(imu_msg)
                self.broadcast_imu_tf(timestamp)  # `/imu` の `stamp` と `/tf` の `stamp` を一致させる
                self.publish_count += 1  # パブリッシュ回数を増加

    def read_imu_data(self):
        """IMUデータを読み取り、パースしてパブリッシュ"""
        try:
            if self.ser.in_waiting >= 11:  # 1フレーム分以上のデータがあるか確認
                data = self.ser.read(11)  # 11バイト分読む
                self.parse_imu_data(data)
        except serial.SerialException as e:
            self.get_logger().error(f"Serial error: {e}")

    def reset_publish_counter(self):
        """1秒ごとにパブリッシュ回数をリセットしてログに出力"""
        self.get_logger().info(f"IMU messages published in the last second: {self.publish_count}")
        self.publish_count = 0  # カウントをリセット

def main(args=None):
    rclpy.init(args=args)
    imu_reader = IMUReader()
    rclpy.spin(imu_reader)  # スレッド処理が適切に機能
    imu_reader.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
