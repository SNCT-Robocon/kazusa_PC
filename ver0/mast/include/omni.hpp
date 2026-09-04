#include "custom_msgs/msg/can_packet.hpp"
#include <cstdint>
#include <cstring>
#include <cmath>


namespace omni{

    inline custom_msgs::msg::CanPacket can_packet(float x, float y, float theta){

        float vel[4];
        float root2 = std::sqrt(2.0f);
        vel[0] =   (x / root2) + (y / root2) + theta * 0.3;
        vel[1] = - (x / root2) + (y / root2) + theta * 0.3;
        vel[2] = - (x / root2) - (y / root2) + theta * 0.3;
        vel[3] =   (x / root2) - (y / root2) + theta * 0.3;

        vel[0] =  vel[0] / (0.1f * M_PI) * 19.0f * 60.0f;
        vel[1] =  vel[1] / (0.1f * M_PI) * 19.0f * 60.0f;
        vel[2] =  vel[2] / (0.1f * M_PI) * 19.0f * 60.0f;
        vel[3] =  vel[3] / (0.1f * M_PI) * 19.0f * 60.0f;

		const double vel_limit = 9000.0; // rpm

		double max_wheel_vel = std::max({
			std::abs(vel[0]),
			std::abs(vel[1]),
			std::abs(vel[2]),
            std::abs(vel[3])
		});

        if(max_wheel_vel > vel_limit){
            double scale = vel_limit / max_wheel_vel;
            for(int i = 0; i < 4; i++){
                vel[i] *= scale;
            }
        }

        vel[0] = vel[0] * - 1.0f;
        vel[1] = vel[1] * - 1.0f;
        vel[2] = vel[2] * - 1.0f;
        vel[3] = vel[3] * - 1.0f;

    	custom_msgs::msg::CanPacket packet;
        packet.id = 0x101;
        memcpy(&packet.data[0], &vel[0], 4);
        memcpy(&packet.data[4], &vel[1], 4);
        memcpy(&packet.data[8], &vel[2], 4);
        memcpy(&packet.data[12], &vel[3], 4);
        
        return packet;

    }

    inline custom_msgs::msg::CanPacket stop_packet(){

        custom_msgs::msg::CanPacket packet;
        packet.id = 0x101;
        float zero = 0.0f;
        memcpy(&packet.data[0], &zero, 4);
        memcpy(&packet.data[4], &zero, 4);
        memcpy(&packet.data[8], &zero, 4);
        memcpy(&packet.data[12], &zero, 4);

        return packet;

    }

}



