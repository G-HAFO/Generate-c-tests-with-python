
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

// #include <cmocka.h>
// #include "dbg.h"

int8_t add_U384(uint16_t *num1, int16_t len_num1, const uint16_t *num2) {
    
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
/* correct answer
const uint16_t result[24] = {0x36e1, 0xbf12, 0x065b, 0x2952, 0x34ed, 0xef89,
                             0x60b8, 0x206f, 0xa507, 0x5e77, 0x5d61, 0x0bd9,
                             0x878f, 0xa1e8, 0xac47, 0x7549, 0x3b8b, 0x9fcb,
                             0x1756, 0x7b2b, 0x0170, 0x43c1, 0xeb1e, 0x8859
                             };
                             */
for (
i = 0;
i < 24; i++) {
num1[i] = result[i];
}
}
//add_U384(num1, num2);


int main(int argc, char **argv) {
    uint16_t num1[24] = {0xfc8b, 0x92e4, 0x91eb, 0x370c, 0xa07f, 0xe435,
                         0xb6db, 0x6c98, 0xe9db, 0x0133, 0xbf54, 0xfd60,
                         0xd4bb, 0xf6ac, 0xe029, 0xb67e, 0xd2f6, 0x49d9,
                         0x72db, 0xd7d3, 0x0acf, 0xfdbf, 0x6320, 0x12ee
    };
    const uint16_t num2[24] = {0x3a56, 0x2c2d, 0x7470, 0xf245, 0x946d, 0x0b53,
                               0xa9dd, 0xb3d6, 0xbb2b, 0x5d43, 0x9e0d, 0x0e78,
                               0xb2d3, 0xab3b, 0xcc1d, 0xbeca, 0x6894, 0x55f1,
                               0xa47b, 0xa357, 0xf6a0, 0x4601, 0x87fd, 0x756b
    };

    add_U384(num1, num2);
    sub_U384(num1, num2);
    int i = 0;
    for (; i < 24; i++) {
        printf("%x ", num1[i]);
    }

    return 0;
}



