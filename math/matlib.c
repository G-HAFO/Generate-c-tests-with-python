#include "matlib.h"

int8_t add_U384(uint16_t *num1, const uint16_t *num2) {
    
    int i;
    uint32_t sum;
    uint8_t carry_bit = 0;
    for (i = 0; i < 24; i++) {
        sum = num1[i] + num2[i] + carry_bit;
        num1[i] = sum & 0xFFFF;
        carry_bit = sum >> 16;
    }
    return carry_bit;
}