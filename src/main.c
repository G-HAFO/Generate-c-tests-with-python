#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>
#include "dbg.h"

static void test_add_U384(void **state)
{

        uint16_t num1[24] = {0x0001, 0x0000, 0x0000};
        const uint16_t num2[24] = {0x0001, 0x0000, 0x0000};

        /* correct answer */
        const uint16_t result[24] = {0x0002, 0x0000, 0x0000};

        add_U384(num1, num2);

        /* check result */
        for(int i = 0; i < sizeof(num1)/sizeof(uint16_t); i++)
        {
            assert_int_equal(num1[i], result[i]);
        }
}

int main(int argc, char **argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(test_add_U384),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
