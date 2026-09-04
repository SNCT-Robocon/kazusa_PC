#include "rclcpp/rclcpp.hpp"
#include "custom_msgs/msg/can_packet.hpp"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "unistd.h"
#include <atomic>
#include <cstdint>
#include <cstring>
#include <netinet/in.h>
#include <rclcpp/logging.hpp>

class udp_to_pub : public rclcpp::Node
{
private:

    rclcpp::Publisher<custom_msgs::msg::CanPacket>::SharedPtr pub;

    int sock;
    sockaddr_in recv_addr;
    std::thread udp_recv_thread;
    std::atomic<bool> running{true};

    void udp_recv_fn(){

        uint8_t buf[64];

        while(running){

            ssize_t len = recv(sock, buf, sizeof(buf), 0);

            if(len < 0){
                RCLCPP_ERROR(this -> get_logger(), "receive failed");
            }
            else if(len == 36){
                custom_msgs::msg::CanPacket packet;
                memcpy(&packet.id, &buf[0], 4);
                memcpy(packet.data.data(), &buf[4], 32);
                pub -> publish(packet);
            }
            else{
                RCLCPP_ERROR(this -> get_logger(), "udp receive packet len is: %ld", len);
            }
        }

        RCLCPP_INFO(this -> get_logger(), "udp receive thread stopped");
    }



public:
    udp_to_pub() : Node("udp_to_pub"){

        this -> declare_parameter("pc_port", 5000);
        uint16_t pc_port = static_cast<uint16_t>(this -> get_parameter("pc_port").as_int());

        RCLCPP_INFO(this -> get_logger(), "started as port %d", pc_port);
        
        rclcpp::QoS qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        qos_profile.best_effort();
        qos_profile.durability_volatile();

        pub = this -> create_publisher<custom_msgs::msg::CanPacket>("can_rx_line", qos_profile);

        sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if(sock < 0){
            RCLCPP_ERROR(this -> get_logger(), "socket init error");
            return;
        }

        recv_addr.sin_family = AF_INET;
        recv_addr.sin_port = htons(pc_port);
        recv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        
        if(bind(sock, (struct sockaddr*)&recv_addr, sizeof(recv_addr)) < 0){
            RCLCPP_ERROR(this -> get_logger(), "socket bind error");
            close(sock);
            return;
        }

        udp_recv_thread = std::thread(&udp_to_pub::udp_recv_fn, this);
    
    }

    ~ udp_to_pub(){
        if(sock < 0){
            return;
        }
        running = false;
        shutdown(sock, SHUT_RDWR);
        if(udp_recv_thread.joinable()){
            udp_recv_thread.join();
        }
        close(sock);
    }

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<udp_to_pub>();
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    rclcpp::shutdown();

    return 0;
}