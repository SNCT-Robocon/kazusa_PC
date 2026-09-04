#include "custom_msgs/msg/can_packet.hpp"
#include <cstdint>
#include <cstring>



namespace shoot{


    inline custom_msgs::msg::CanPacket can_packet(uint32_t machine_index, float vel){

        custom_msgs::msg::CanPacket txpacket;

        txpacket.id = 0x201 + machine_index;
        memcpy(&txpacket.data[0], &vel, 4);

        return txpacket;

    }

}

