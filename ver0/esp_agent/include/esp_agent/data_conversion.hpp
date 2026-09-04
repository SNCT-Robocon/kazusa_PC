#ifndef DATA_CONVERSION_HPP_
#define DATA_CONVERSION_HPP_

#include "stdint.h"
#include <string.h>
#include "custom_msgs/msg/can_packet.hpp"


constexpr uint8_t INVALID_HAX = 0xfe;
constexpr uint8_t INVALID_ASCII = 'x';
constexpr uint8_t END_MARKER = 0xff;

uint8_t ascii_to_hax(uint8_t input){
    if(input == '\0') return END_MARKER;
    if('0' <= input && input <= '9') return input - '0';
    if('a' <= input && input <= 'f') return input - 'a' + 10;
    return INVALID_HAX;
}

uint8_t hax_to_ascii(uint8_t input){
    if(input == END_MARKER) return '\0';
    // if(0<= input && input <= 9) return '0' + input;
    if(input <= 9) return '0' + input;
    if(0x0a <= input && input <= 0x0f) return 'a' + (input - 10);
    return INVALID_ASCII;
}

void decode_serial_to_can(uint8_t* input_data, custom_msgs::msg::CanPacket &output_data){

    output_data.id = (ascii_to_hax(input_data[0]) << 8) | (ascii_to_hax(input_data[1]) << 4) | ascii_to_hax(input_data[2]);

    for(int i = 0; i < 32; i++){
        output_data.data[i] = (ascii_to_hax(input_data[2 * i + 3]) << 4) | ascii_to_hax(input_data[2 * i + 4]);
    }
    
}

void encode_can_to_serial(custom_msgs::msg::CanPacket &input_data, uint8_t* output_data){

    output_data[0] = hax_to_ascii((input_data.id >> 8) & 0x0f); 
    output_data[1] = hax_to_ascii((input_data.id >> 4) & 0x0f);
    output_data[2] = hax_to_ascii(input_data.id & 0x0f);

    for(int i = 0; i < 32; i++){
        output_data[2 * i + 3] = hax_to_ascii(input_data.data[i] >> 4);
        output_data[2 * i + 4] = hax_to_ascii(input_data.data[i] & 0x0f);
    }

    output_data[67] = '\0';
}



#endif /* DATA_CONVERSION_HPP*/