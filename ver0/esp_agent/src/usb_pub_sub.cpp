#include "rclcpp/rclcpp.hpp"
#include "custom_msgs/msg/can_packet.hpp"
#include "esp_agent/data_conversion.hpp"
#include <boost/asio.hpp>
#include <memory>
#include <string>
#include <atomic>



class usb_pub_sub : public rclcpp::Node
{
private:

    rclcpp::Publisher<custom_msgs::msg::CanPacket>::SharedPtr pub;
	rclcpp::Subscription<custom_msgs::msg::CanPacket>::SharedPtr sub;
    boost::asio::io_context io_;
    boost::asio::serial_port serial_;
    std::string port_name_;
    std::thread io_thread_;


    boost::asio::steady_timer reconnect_timer_;
    std::atomic<bool> is_connected_{false};

    std::array<uint8_t, 256> read_buf_;
    std::array<uint8_t, 256> udp_preserved_data_;
    size_t packet_tail_ = 0;


	void sub_callback(const custom_msgs::msg::CanPacket::SharedPtr rx_packet){

        // if(rx_packet -> id == 0x102 || rx_packet -> id == 0x101){
            
            uint8_t tx_data[68];

            encode_can_to_serial(*rx_packet, tx_data);

            boost::asio::async_write(serial_, boost::asio::buffer(tx_data),
                [this](const boost::system::error_code &ec, std::size_t length) {
                    if (ec) {

                        RCLCPP_ERROR(this->get_logger(), "Serial read error: %s", ec.message().c_str());
                        if(serial_.is_open()){
                            serial_.close();
                        }
                        is_connected_ = false;
                        return;

                    }
                }
            );

        // }


		// RCLCPP_INFO(this -> get_logger(), "usb send id : %x", rx_packet -> id);

	}

    void start_read() {
        serial_.async_read_some(boost::asio::buffer(read_buf_),
            std::bind(&usb_pub_sub::handle_read, this, std::placeholders::_1, std::placeholders::_2));
    }

    void handle_read(const boost::system::error_code &ec, std::size_t bytes_transferred) {
        if (ec) {
            RCLCPP_ERROR(this->get_logger(), "Serial read error: %s", ec.message().c_str());
            if(serial_.is_open()){
                serial_.close();
            }
            is_connected_ = false;
            return;
        }

        for (size_t i = 0; i < bytes_transferred; ++i) {
            uint8_t byte = read_buf_[i];

            if (byte == '\0') {
                udp_preserved_data_[packet_tail_++] = '\0';

                if (packet_tail_ == 68) {
                    custom_msgs::msg::CanPacket tx_packet;
                    decode_serial_to_can(udp_preserved_data_.data(), tx_packet);
                    pub->publish(tx_packet);

                    // RCLCPP_INFO(this->get_logger(), "can to pub id is %x", tx_packet.id);
                } else {
                    RCLCPP_WARN(this->get_logger(), "packet error (length %zu)", packet_tail_);
                }

                packet_tail_ = 0;
                udp_preserved_data_.fill(0);
            } else {
                if (packet_tail_ < udp_preserved_data_.size()) {
                    udp_preserved_data_[packet_tail_++] = byte;
                } else {
                    // バッファあふれ
                    RCLCPP_ERROR(this->get_logger(), "Buffer overflow");
                    packet_tail_ = 0;
                    udp_preserved_data_.fill(0);
                }
            }
        }

        // 次の非同期受信を開始
        start_read();
    }

    void start_reconnect_timer() {
        reconnect_timer_.async_wait([this](const boost::system::error_code &ec) {
            if (!ec) {
                if (!is_connected_) {
                    RCLCPP_WARN(this->get_logger(), "Trying to reconnect to serial port...");

                    try {
                        if (!serial_.is_open()) {
                            serial_.open(port_name_);
                            serial_.set_option(boost::asio::serial_port_base::baud_rate(115200));
                            RCLCPP_INFO(this->get_logger(), "Reconnected to serial port.");
                            is_connected_ = true;
                            start_read();  // 再接続成功時にread再開
                        }
                    } catch (const std::exception &e) {
                        RCLCPP_ERROR(this->get_logger(), "Reconnect failed: %s", e.what());
                    }
                }

                reconnect_timer_.expires_after(std::chrono::seconds(1));
                start_reconnect_timer();
            }
        });
    }




public:

	usb_pub_sub() : 
        Node("usb_pub_sub"), io_(), serial_(io_), port_name_(this->declare_parameter<std::string>("port_name", "/dev/ttyACM0")), reconnect_timer_(io_, std::chrono::seconds(1))
    {

        try{
            serial_.open(port_name_);
            is_connected_ = true;
            serial_.set_option(boost::asio::serial_port_base::baud_rate(115200));
            RCLCPP_INFO(this->get_logger(), "Serial port opened %s.", port_name_.c_str());
        }
        catch(const std::exception& e){
            RCLCPP_ERROR(this->get_logger(), "Error: %s", e.what());
        }

		rclcpp::QoS qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
		qos_profile.best_effort();
		qos_profile.durability_volatile();

		sub = this -> create_subscription<custom_msgs::msg::CanPacket>(
			"can_tx_line",
			qos_profile,
			std::bind(&usb_pub_sub::sub_callback, this, std::placeholders::_1)
		);

        pub = this->create_publisher<custom_msgs::msg::CanPacket>("can_rx_line", qos_profile);

        if(is_connected_){
            start_read();  // 最初の非同期受信を始める
        }


        io_thread_ = std::thread([this](){ io_.run(); });

        start_reconnect_timer();

        RCLCPP_INFO(this->get_logger(), "init finished");


        // uint8_t tx_data[68];
        // can_packet::msg::CanPacket rxpacket;

        // rxpacket.id = 0x105;
        // rxpacket.data.fill(0);

		// encode_can_to_serial(rxpacket, tx_data);

        // boost::asio::async_write(serial_, boost::asio::buffer(tx_data),
        //     [](const boost::system::error_code &ec, std::size_t length) {
        //         if (ec) {
        //             std::cerr << "Write error: " << ec.message() << std::endl;
        //         }
        //     }
        // );

		// RCLCPP_INFO(this -> get_logger(), "usb send id : %x", rxpacket.id);


	}

    ~usb_pub_sub() {
        io_.stop();
        if (io_thread_.joinable()) {
            io_thread_.join();
        }
        if (serial_.is_open()) {
            serial_.close();
        }
    }

};




int main(int argc, char * argv[])
{
	rclcpp::init(argc, argv);

    auto node = std::make_shared<usb_pub_sub>();
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();

	return 0;
}