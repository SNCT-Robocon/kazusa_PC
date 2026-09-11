#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from std_msgs.msg import Float64MultiArray

import smbus
import time
import struct
import math
import sys
import importlib.util
from std_msgs.msg import Bool
import os
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
GYRO_CONFIG0 = 0x4F
ACCEL_CONFIG0 = 0x50
POWER_REG    = 0x4E
ICM42688_ADDR = 0x68
DATA_START = 0x1F

ACCEL_SENS = 16384.0
GYRO_SENS = 131.0

# ===== オフセットファイル読み込み =====
offset_path = "/home/suzuka/imu_offsets.py"
spec = importlib.util.spec_from_file_location("imu_offset", offset_path)
imu_offset = importlib.util.module_from_spec(spec)
spec.loader.exec_module(imu_offset)

# =====================================

class IMUPublisher(Node):
    def __init__(self):
        super().__init__('imu_publisher')
        self.publisher_ = self.create_publisher(Imu, '/imu', 10)
        self.offset_pub = self.create_publisher(Float64MultiArray, '/imu_offset', 10)

        self.bus = smbus.SMBus(1)
        self.init_sensor()
        self.ACCEL_OFFSET = imu_offset.ACCEL_OFFSET
        self.GYRO_OFFSET = imu_offset.GYRO_OFFSET
        
        self.offset_mtime = os.path.getmtime(offset_path)
    def publish_offsets(self):
        msg = Float64MultiArray()
        # 順序: ax, ay, az, gx, gy, gz
        msg.data = [
            self.ACCEL_OFFSET["x"],
            self.ACCEL_OFFSET["y"],
            self.ACCEL_OFFSET["z"],
            self.GYRO_OFFSET["x"],
            self.GYRO_OFFSET["y"],
            self.GYRO_OFFSET["z"]
        ]
        self.offset_pub.publish(msg)

    def init_sensor(self):
        who_am_i = self.bus.read_byte_data(ICM42688_ADDR, 0x75)
        self.get_logger().info(f"WHO_AM_I = 0x{who_am_i:02X}")

        self.bus.write_byte_data(ICM42688_ADDR, POWER_REG, 0x0F)
        self.bus.write_byte_data(ICM42688_ADDR, GYRO_CONFIG0, 0x61)
        time.sleep(0.01)
        self.bus.write_byte_data(ICM42688_ADDR, ACCEL_CONFIG0, 0x61)
        time.sleep(0.01)
        
        qos_profile = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE
        )
        
        # /cartrigger トピック購読
        self.sub = self.create_subscription(
            Bool,
            '/cartrigger',
            self.callback,
            qos_profile
        )

        self.launched = False
    def load_offsets(self):
        spec = importlib.util.spec_from_file_location("imu_offset", offset_path)
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        self.offset_mtime = os.path.getmtime(offset_path)
        return module.ACCEL_OFFSET, module.GYRO_OFFSET


    def wait_for_offset_update(self, timeout=20.0):
        start_time = time.time()
        while time.time() - start_time < timeout:
            try:
                mtime = os.path.getmtime(offset_path)
                if mtime != self.offset_mtime:
                    self.get_logger().info('imu_offsets.py updated. Reloading offsets.')
                    self.ACCEL_OFFSET, self.GYRO_OFFSET = self.load_offsets()
                    self.publish_offsets()
                    self.offset_mtime = mtime
                    return True
            except FileNotFoundError:
                self.get_logger().warn(f"{offset_path} not found. Using previous offsets.")
            time.sleep(0.1)  # 100msごとにチェック
        self.get_logger().warn('Timeout reached. Offset file not updated.')
        return True

    def callback(self, msg):
        if msg.data and not self.launched:
            self.get_logger().info('Received "True". Launch sequence start.')

            # ===== imu_offsets.py 再読み込み =====
            self.wait_for_offset_update(timeout=30.0)
            self.launched = True

        elif not msg.data and self.launched:
            self.get_logger().info('Received "False". Stopping all processes.')
            self.launched = False
            


    def read_sensor_data(self):
        try:
            raw_data = self.bus.read_i2c_block_data(ICM42688_ADDR, DATA_START, 12)

            accel_x = struct.unpack('>h', bytes(raw_data[0:2]))[0]*-1 - self.ACCEL_OFFSET["x"]
            accel_y = struct.unpack('>h', bytes(raw_data[2:4]))[0]*-1 - self.ACCEL_OFFSET["y"]
            accel_z = struct.unpack('>h', bytes(raw_data[4:6]))[0] - self.ACCEL_OFFSET["z"]+16384
            gyro_x  = 0
            gyro_y  = 0
            gyro_z  = struct.unpack('>h', bytes(raw_data[10:12]))[0] - self.GYRO_OFFSET["z"]
            #self.get_logger().info(f"ax{accel_x:.2f},ay{accel_y:.2f},az{accel_z:.2f},gx{gyro_x:.2f},gy{gyro_y:.2f},gz{gyro_z:.2f}")
            #self.get_logger().info(f"ax_off{self.ACCEL_OFFSET['x']:.2f},ay_off{self.ACCEL_OFFSET['y']:.2f},az_off{self.ACCEL_OFFSET['z']:.2f},gx_off{self.GYRO_OFFSET['x']:.2f},gy_off{self.GYRO_OFFSET['y']:.2f},gz_off{self.GYRO_OFFSET['z']:.2f}")
            
            return {
                "accel": {"x": accel_x, "y": accel_y, "z": accel_z},
                "gyro":  {"x": gyro_x,  "y": gyro_y,  "z": gyro_z}
            }
        except OSError as e:
            self.get_logger().error(f"I2C read error: {e}")
            return {"accel": {"x":0, "y":0, "z":0}, "gyro": {"x":0, "y":0, "z":0}}

    def convert_to_physical_units(self, data):
        accel_g = {k: v / ACCEL_SENS for k, v in data["accel"].items()}
        accel_ms2 = {k: v * 9.80665 for k, v in accel_g.items()}

        gyro_dps = {k: v / GYRO_SENS for k, v in data["gyro"].items()}
        gyro_rads = {k: math.radians(v) for k, v in gyro_dps.items()}

        return {
            "accel_ms2": accel_ms2,
            "gyro_rads": gyro_rads
        }

    def publish_imu(self):
        raw = self.read_sensor_data()
        phys = self.convert_to_physical_units(raw)

        imu_msg = Imu()
        imu_msg.header.stamp = self.get_clock().now().to_msg()
        imu_msg.header.frame_id = "imu_link"

        imu_msg.linear_acceleration.x = phys["accel_ms2"]["x"]
        imu_msg.linear_acceleration.y = phys["accel_ms2"]["y"]
        imu_msg.linear_acceleration.z = phys["accel_ms2"]["z"]

        imu_msg.angular_velocity.x = phys["gyro_rads"]["x"]
        imu_msg.angular_velocity.y = phys["gyro_rads"]["y"]
        imu_msg.angular_velocity.z = phys["gyro_rads"]["z"]

        imu_msg.orientation.x = 0.0
        imu_msg.orientation.y = 0.0
        imu_msg.orientation.z = 0.0
        imu_msg.orientation.w = 1.0

        imu_msg.orientation_covariance[0] = -1
        imu_msg.angular_velocity_covariance=[ 0.00592 ,-0.00031 ,-0.00027,
                                                -0.00031 , 0.0037 ,  0.00021,                    
                                                -0.00027,  0.00021 , 0.00464]
        imu_msg.linear_acceleration_covariance = [0.00043 ,-0.00002 ,-0.00001,
                                                     -0.00002 , 0.00044 , 0.00001,
                                                     -0.00001 ,0.00001 , 0.00046]

        self.publisher_.publish(imu_msg)

def main(args=None):
    rclpy.init(args=args)
    imu_pub = IMUPublisher()
    try:
        while rclpy.ok():
            imu_pub.publish_imu()
            rclpy.spin_once(imu_pub, timeout_sec=0)
    except KeyboardInterrupt:
        pass
    imu_pub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
