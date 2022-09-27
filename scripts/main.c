
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>
#include "dbg.h"


static void test_add_U384_1(void** state)
{
    uint16_t num1[24] = {0x0c15, 0x5243, 0x9a7d, 0x6a72                                                                                                                                                                                 , 0x92c7, 0x8e62, 0xb56d, 0xb140                                                                                                                                                                                 , 0xb674, 0x7271, 0xb6b8, 0xf253                                                                                                                                                                                 , 0x9fdc, 0x2870, 0x5839, 0x5d4f                                                                                                                                                                                 , 0xd489, 0xd255, 0x76ab, 0x5141                                                                                                                                                                                 , 0xd5d2, 0x0988, 0xf341, 0x8446};
    const uint16_t num2[24] = {0x4568, 0x235e, 0x9704, 0x3f54                                                                                                                                                                                 , 0xdbbb, 0x676c, 0x8840, 0x5d63                                                                                                                                                                                 , 0x10a3, 0xda84, 0xae4e, 0x9fdd                                                                                                                                                                                 , 0xe329, 0x267a, 0x51ed, 0xda45                                                                                                                                                                                 , 0x0f63, 0x931f, 0xacea, 0xab36                                                                                                                                                                                 , 0xa357, 0x7fdd, 0xaecc, 0x7ccc};
    /* correct answer */
    const uint16_t result[24] = {0x1517, 0x175a, 0x7318, 0x2a9c                                                                                                                                                                                 , 0xf6e8, 0xdf5c, 0x43da, 0x80ea                                                                                                                                                                                 , 0x5c71, 0x74cf, 0x1650, 0x6923                                                                                                                                                                                 , 0xb830, 0x64ee, 0x4aa2, 0xd379                                                                                                                                                                                 , 0x4e3e, 0x6657, 0x8239, 0x9fc7                                                                                                                                                                                 , 0x6792, 0xd896, 0x3a20, 0x1011};

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

int main(int argc, char **argv)
{
    const struct CMUnitTest tests[] =
    {
     
      cmocka_unit_test(test_add_U384_1),

    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}


