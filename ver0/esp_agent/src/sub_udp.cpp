#include "rclcpp/rclcpp.hpp"
#include "custom_msgs/msg/can_packet.hpp"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "unistd.h"
#include <cstring>
#include <netinet/in.h>
#include <rclcpp/logging.hpp>


class sub_to_udp : public rclcpp::Node
{
private:

	rclcpp::Subscription<custom_msgs::msg::CanPacket>::SharedPtr sub;

	int sock;
	sockaddr_in esp_addr;

	void sub_callback(const custom_msgs::msg::CanPacket::SharedPtr rx_packet){

		uint8_t buf[36];

		memcpy(&buf[0], &rx_packet -> id, 4);
		memcpy(&buf[4], rx_packet -> data.data(), 32);
		if(sendto(sock, buf, 36, 0, (struct sockaddr*)(&esp_addr), sizeof(esp_addr)) < 0){
			RCLCPP_ERROR_THROTTLE(this -> get_logger(), *this -> get_clock(), 1000, "udp tx error");
		}

	}

public:
	sub_to_udp() : Node("sub_to_udp"){

		std::string esp_ip = this -> declare_parameter("esp_ip", std::string("192.168.100.100"));
		uint16_t esp_port = this -> declare_parameter("esp_port", 6000);

		if(inet_addr(esp_ip.c_str()) == INADDR_NONE){
			RCLCPP_ERROR(this -> get_logger(), "invalid esp ip address");
			sock = -1;
			return;
		}

		rclcpp::QoS qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
		qos_profile.best_effort();
		qos_profile.durability_volatile();
		sub = this -> create_subscription<custom_msgs::msg::CanPacket>(
			"can_tx_line",
			qos_profile,
			std::bind(&sub_to_udp::sub_callback, this, std::placeholders::_1)
		);

		sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if(sock < 0){
			RCLCPP_ERROR(this -> get_logger(), "socket error");
			return;
		}
		esp_addr.sin_family = AF_INET;
		esp_addr.sin_port = htons(esp_port);
		esp_addr.sin_addr.s_addr = inet_addr(esp_ip.c_str());


		custom_msgs::msg::CanPacket packet;
		packet.id = 0x200;
		memset(packet.data.data(), 0, sizeof(packet.data));
		packet.data[0] = 0x6f;

		uint8_t buf[36];
		memcpy(&buf[0], &packet.id, 4);
		memcpy(&buf[4], packet.data.data(), 32);

		if(sendto(sock, buf, 36, 0, reinterpret_cast<sockaddr*>(&esp_addr), sizeof(esp_addr)) < 0){
			RCLCPP_ERROR(this -> get_logger(), "udp tx error");
		}

	}

	~ sub_to_udp(){
		if(sock < 0){
			return;
		}
		close(sock);
	}

};


int main(int argc, char * argv[])
{
	rclcpp::init(argc, argv);

    auto node = std::make_shared<sub_to_udp>();
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    rclcpp::shutdown();

	return 0;
}