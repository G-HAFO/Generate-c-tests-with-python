
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>
#include "dbg.h"


static void test_add_U384_0(void** state)
{

            uint16_t num1[24] = {};
      const uint16_t num2[24] = {};
    /* correct answer */
    const uint16_t result[24] = {};

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_1(void** state)
{

            uint16_t num1[24] = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
                                 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
                                 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
                                 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff
                                 };
      const uint16_t num2[24] = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
                                 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
                                 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
                                 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff
                                 };
    /* correct answer */
    const uint16_t result[24] = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
                                 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
                                 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
                                 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x1fff
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_2(void** state)
{

            uint16_t num1[24] = {0xb5b1, 0x6369, 0x7794, 0x8bee, 0xdee8, 0x7138, 
                                 0x4fb9, 0xe615, 0xad61, 0x40aa, 0x7e2b, 0xf5ad, 
                                 0x6a22, 0x7318, 0xd04f, 0x2995, 0xbd18, 0xd929, 
                                 0x902c, 0xeecf, 0xfcc5, 0x3c3d, 0x69a5, 0xf019
                                 };
      const uint16_t num2[24] = {0x6079, 0xa4e8, 0xdb8d, 0xdab5, 0xe178, 0x7e31, 
                                 0x2dd6, 0x026b, 0xd835, 0x40de, 0xa6f4, 0x6d20, 
                                 0x4017, 0x4373, 0x767a, 0x9515, 0xd473, 0xb64a, 
                                 0xd4eb, 0x6cb5, 0xc9d8, 0x4368, 0xa02c, 0x08f8
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x162a, 0x0852, 0x5322, 0x66a4, 0xc061, 0xef6a, 
                                 0x7d8f, 0xe880, 0x8596, 0x8189, 0x251f, 0x62ce, 
                                 0xaa3a, 0xb68b, 0x46c9, 0xbeab, 0x918b, 0x8f74, 
                                 0x6518, 0x5b85, 0xc69e, 0x7fa6, 0x09d1, 0xf912
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_3(void** state)
{

            uint16_t num1[24] = {0x7054, 0xdf50, 0xbc34, 0xe149, 0xb09c, 0xc160, 
                                 0x034f, 0x1ddd, 0x6cb9, 0xe6e2, 0xab88, 0xff48, 
                                 0xfb3b, 0xb633, 0xd862, 0x7cee, 0xcd0d, 0xf94b, 
                                 0x921d, 0x505b, 0x637a, 0x8a7c, 0xf876, 0x3955
                                 };
      const uint16_t num2[24] = {0xa1c1, 0x0721, 0x3089, 0x6250, 0x8351, 0x528e, 
                                 0xa868, 0x3cef, 0x5c83, 0x3bda, 0xd72c, 0x9e5e, 
                                 0x9e7c, 0x978d, 0xf3d0, 0x16d8, 0x15bf, 0x0a51, 
                                 0xc0d9, 0x267b, 0x9933, 0xe0a7, 0x4c78, 0x343c
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x1215, 0xe672, 0xecbd, 0x4399, 0x33ee, 0x13ef, 
                                 0xabb8, 0x5acc, 0xc93c, 0x22bc, 0x82b5, 0x9da7, 
                                 0x99b8, 0x4dc1, 0xcc33, 0x93c7, 0xe2cc, 0x039c, 
                                 0x52f7, 0x76d7, 0xfcad, 0x6b23, 0x44ef, 0x6d92
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_4(void** state)
{

            uint16_t num1[24] = {0xd97c, 0x6d40, 0x7ca4, 0x6458, 0x436c, 0x32c2, 
                                 0x37bf, 0xd1f0, 0xb1a1, 0x78e4, 0xdf2b, 0xd76a, 
                                 0x7ace, 0x076d, 0xcff9, 0x827b, 0xfbf1, 0xf42c, 
                                 0x5cd1, 0x8a74, 0xafbd, 0x5f32, 0xff16, 0x5280
                                 };
      const uint16_t num2[24] = {0xa7ee, 0x94ff, 0xb40b, 0xfced, 0x3a80, 0x2d70, 
                                 0xa1c6, 0x3031, 0x7d29, 0x4c7d, 0xc431, 0xab90, 
                                 0xbebc, 0x9258, 0x8a9a, 0x2838, 0xdbd5, 0x5003, 
                                 0x40ee, 0xb6dd, 0x7a50, 0x9ad6, 0x5590, 0x9fb0
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x816a, 0x0240, 0x30b0, 0x6146, 0x7ded, 0x6032, 
                                 0xd985, 0x0221, 0x2ecb, 0xc562, 0xa35c, 0x82fb, 
                                 0x398b, 0x99c6, 0x5a93, 0xaab4, 0xd7c6, 0x4430, 
                                 0x9dc0, 0x4151, 0x2a0e, 0xfa09, 0x54a6, 0xf231
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_5(void** state)
{

            uint16_t num1[24] = {0xf806, 0x5f8c, 0x9c75, 0xebe4, 0x4a72, 0x2de3, 
                                 0xcdfe, 0x5fbe, 0xa36b, 0x75fc, 0x8c0c, 0x41ea, 
                                 0xa203, 0x9c60, 0xbb15, 0xfa17, 0x22b5, 0xed3d, 
                                 0x6950, 0x9744, 0xf9d8, 0xf3b2, 0x68a9, 0x05c0
                                 };
      const uint16_t num2[24] = {0x33bb, 0xa72f, 0x8be1, 0xcf71, 0x0006, 0xa788, 
                                 0x9d3c, 0xe638, 0x2afb, 0xf6f5, 0x3327, 0x95ef, 
                                 0x2909, 0xaf29, 0x9910, 0x921a, 0x2b7a, 0x1f61, 
                                 0x92c5, 0x4627, 0x6cf0, 0xd6ce, 0xb5b3, 0x8ce3
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x2bc1, 0x06bc, 0x2857, 0xbb56, 0x4a79, 0xd56b, 
                                 0x6b3a, 0x45f7, 0xce67, 0x6cf1, 0xbf34, 0xd7d9, 
                                 0xcb0c, 0x4b89, 0x5426, 0x8c32, 0x4e30, 0x0c9e, 
                                 0xfc16, 0xdd6b, 0x66c8, 0xca81, 0x1e5d, 0x92a4
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_6(void** state)
{

            uint16_t num1[24] = {0xbfba, 0x7389, 0x0dfe, 0x7812, 0xcebd, 0xbb1c, 
                                 0xfa37, 0x3012, 0xab57, 0xbc6b, 0x857a, 0x7fd9, 
                                 0x625c, 0x7392, 0x53a4, 0x45e0, 0x1bc4, 0x3b06, 
                                 0x1f67, 0xf2cb, 0xd708, 0x1371, 0x5a2c, 0xb006
                                 };
      const uint16_t num2[24] = {0xd733, 0x1eac, 0xf82b, 0xc460, 0xfbfa, 0x2137, 
                                 0x01c8, 0xe0fa, 0xabfc, 0x1da5, 0x4b82, 0xf9f9, 
                                 0x7212, 0x14a7, 0xfcc2, 0xd03a, 0x6bb1, 0x487a, 
                                 0x696e, 0x9c1f, 0x4b80, 0x7434, 0x125a, 0x244d
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x96ed, 0x9236, 0x0629, 0x3c73, 0xcab8, 0xdc54, 
                                 0xfbff, 0x110c, 0x5754, 0xda11, 0xd0fc, 0x79d2, 
                                 0xd46f, 0x8839, 0x5066, 0x161b, 0x8776, 0x8380, 
                                 0x88d5, 0x8eea, 0x2289, 0x87a6, 0x6c86, 0xd453
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_7(void** state)
{

            uint16_t num1[24] = {0xd7fb, 0x5517, 0x2545, 0x36b8, 0x7d20, 0x83f6, 
                                 0x7fcb, 0x63ee, 0xe499, 0x21fd, 0xcea2, 0x1adc, 
                                 0xe782, 0x3c7d, 0xd8e6, 0xe931, 0xc33b, 0xbaad, 
                                 0xd8c3, 0x7ecc, 0x7297, 0x2ae6, 0x0a25, 0xafcb
                                 };
      const uint16_t num2[24] = {0x889b, 0xcb2f, 0xc3e2, 0xb981, 0xa2c0, 0xda10, 
                                 0x957c, 0x3138, 0x019b, 0xc037, 0x913c, 0x6089, 
                                 0x9e4d, 0x7c78, 0x4a05, 0x597f, 0xaf4b, 0xcfd1, 
                                 0x7b8b, 0xc4b8, 0x6f6a, 0xda98, 0x1d90, 0x121c
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x6096, 0x2047, 0xe928, 0xf039, 0x1fe0, 0x5e07, 
                                 0x1548, 0x9527, 0xe634, 0xe234, 0x5fde, 0x7b66, 
                                 0x85cf, 0xb8f6, 0x22eb, 0x42b1, 0x7287, 0x8a7f, 
                                 0x544f, 0x4385, 0xe202, 0x057e, 0x27b6, 0xc1e7
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_8(void** state)
{

            uint16_t num1[24] = {0xd3b7, 0x8220, 0x660c, 0xcfa6, 0xb805, 0xefad, 
                                 0xe8c5, 0xbe33, 0x7369, 0x7219, 0x4c54, 0xc72a, 
                                 0xa385, 0xda48, 0x713c, 0x5260, 0xef95, 0x97d0, 
                                 0x6a25, 0xe5a3, 0x3ba0, 0xccdb, 0xb5f0, 0x1e01
                                 };
      const uint16_t num2[24] = {0x7386, 0x2b64, 0x64b6, 0x8b3f, 0x90d9, 0xf10c, 
                                 0x8a6f, 0x6ea3, 0xa440, 0x3f03, 0x0c7d, 0xdacf, 
                                 0x3c5a, 0xb8ab, 0x1e74, 0xb774, 0xb28f, 0xacbc, 
                                 0x7b49, 0xfb18, 0x33af, 0x4fa1, 0x0c22, 0x7cd2
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x473d, 0xad85, 0xcac2, 0x5ae5, 0x48df, 0xe0ba, 
                                 0x7335, 0x2cd7, 0x17aa, 0xb11d, 0x58d1, 0xa1f9, 
                                 0xdfe0, 0x92f3, 0x8fb1, 0x09d4, 0xa225, 0x448d, 
                                 0xe56f, 0xe0bb, 0x6f50, 0x1c7c, 0xc213, 0x9ad3
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_9(void** state)
{

            uint16_t num1[24] = {0xd62a, 0xc9b1, 0xb8f7, 0xf024, 0x75d5, 0xc621, 
                                 0x30ef, 0xbc7b, 0x64bf, 0xcd17, 0x535d, 0x8c32, 
                                 0x2cef, 0xa8cd, 0xa1e4, 0xb6ab, 0x7cb3, 0x29ae, 
                                 0x033b, 0xeca1, 0xc883, 0x2db3, 0xeffd, 0x666a
                                 };
      const uint16_t num2[24] = {0x5faa, 0x2c65, 0x6d84, 0x33ec, 0xc897, 0xf2f4, 
                                 0xe00b, 0x1642, 0x8b56, 0xe050, 0xe661, 0x011e, 
                                 0x4acb, 0x86eb, 0x7609, 0x71ac, 0x54f3, 0x8111, 
                                 0x0346, 0xc401, 0xf488, 0xd403, 0x1193, 0x41cf
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x35d4, 0xf617, 0x267b, 0x2411, 0x3e6d, 0xb916, 
                                 0x10fb, 0xd2be, 0xf015, 0xad67, 0x39bf, 0x8d51, 
                                 0x77ba, 0x2fb8, 0x17ee, 0x2858, 0xd1a7, 0xaabf, 
                                 0x0681, 0xb0a2, 0xbd0c, 0x01b7, 0x0191, 0xa83a
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_10(void** state)
{

            uint16_t num1[24] = {0xf787, 0xaf8d, 0x7605, 0xbac6, 0x68e9, 0xc434, 
                                 0xa9a1, 0x6176, 0x4f7a, 0x02df, 0x7940, 0x593a, 
                                 0x5074, 0x6722, 0xb829, 0x10a4, 0x90e2, 0x16e9, 
                                 0x10e7, 0x5c0f, 0x7128, 0x851e, 0xa600, 0xd35f
                                 };
      const uint16_t num2[24] = {0x6439, 0x2ee6, 0x23ad, 0x84ad, 0xa398, 0x4d61, 
                                 0x4dc9, 0x2f87, 0x7b65, 0x67cf, 0x6f95, 0x63ca, 
                                 0xf731, 0x1110, 0xa4ad, 0x3501, 0xfdc2, 0x824f, 
                                 0x1bd8, 0xb548, 0x4c69, 0x5fde, 0x4d89, 0x1833
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x5bc0, 0xde74, 0x99b2, 0x3f73, 0x0c82, 0x1196, 
                                 0xf76b, 0x90fd, 0xcadf, 0x6aae, 0xe8d5, 0xbd04, 
                                 0x47a5, 0x7833, 0x5cd6, 0x45a6, 0x8ea4, 0x9939, 
                                 0x2cbf, 0x1157, 0xbd92, 0xe4fc, 0xf389, 0xeb92
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_11(void** state)
{

            uint16_t num1[24] = {0x59d4, 0xd934, 0x4edb, 0x1e0b, 0xe661, 0x767e, 
                                 0xc558, 0x6d89, 0xb83f, 0x6c16, 0x32eb, 0xd814, 
                                 0x6f38, 0x44bb, 0xe2c6, 0x1220, 0x6f11, 0x85ac, 
                                 0x0b5d, 0x6a7b, 0xc936, 0x71b4, 0xc1d5, 0x3ac8
                                 };
      const uint16_t num2[24] = {0x12b1, 0x1802, 0x4d89, 0x2c03, 0x866a, 0x07f3, 
                                 0xff0e, 0xf298, 0x9019, 0xa067, 0x56ff, 0xcc55, 
                                 0x4d21, 0x37a4, 0x922c, 0xb446, 0x6f0d, 0x6ea5, 
                                 0x922a, 0xf85a, 0x76f3, 0x2ad8, 0x0089, 0x2808
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x6c85, 0xf136, 0x9c64, 0x4a0e, 0x6ccb, 0x7e72, 
                                 0xc466, 0x6022, 0x4859, 0x0c7e, 0x89eb, 0xa469, 
                                 0xbc5a, 0x7c5f, 0x74f2, 0xc667, 0xde1e, 0xf451, 
                                 0x9d87, 0x62d5, 0x402a, 0x9c8d, 0xc25e, 0x62d0
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_12(void** state)
{

            uint16_t num1[24] = {0x8aa9, 0x04a7, 0xf1e9, 0x970c, 0x814c, 0x6049, 
                                 0xdd54, 0x673b, 0xfa08, 0x661f, 0xc1bc, 0x8df3, 
                                 0x78ff, 0x3e6e, 0xfaf5, 0xf47c, 0xc061, 0x7d34, 
                                 0xc516, 0x84f0, 0x1ad1, 0x89e7, 0x4e57, 0x9c38
                                 };
      const uint16_t num2[24] = {0xd26d, 0x13fb, 0x73ed, 0x107d, 0xabb2, 0x64dc, 
                                 0x9fb0, 0xc35b, 0xc3ef, 0xbb59, 0x1b9a, 0x5267, 
                                 0x65f5, 0x10ad, 0xfc55, 0x0de2, 0x2b30, 0xcafd, 
                                 0x4419, 0x9c3d, 0xc61c, 0x6b59, 0xac12, 0x5dc4
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x5d16, 0x18a3, 0x65d6, 0xa78a, 0x2cfe, 0xc526, 
                                 0x7d04, 0x2a97, 0xbdf8, 0x2179, 0xdd57, 0xe05a, 
                                 0xdef4, 0x4f1b, 0xf74a, 0x025f, 0xeb92, 0x4831, 
                                 0x0930, 0x212e, 0xe0ee, 0xf540, 0xfa69, 0xf9fc
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_13(void** state)
{

            uint16_t num1[24] = {0x4ba7, 0xc6e0, 0x7c71, 0x6b1c, 0x9b4d, 0xc869, 
                                 0x633a, 0x8f42, 0x6875, 0x5c11, 0x64fc, 0x82ea, 
                                 0x8545, 0x97b1, 0xd680, 0x92fc, 0x1a3f, 0x1026, 
                                 0x7cc7, 0x7d98, 0x71d7, 0x3c46, 0x2186, 0xce19
                                 };
      const uint16_t num2[24] = {0x882a, 0x8991, 0xbcf1, 0x107b, 0x70d0, 0xf1ad, 
                                 0x559e, 0xe51b, 0x509b, 0x627d, 0x025f, 0xaff3, 
                                 0xa1e9, 0x0548, 0x7ffb, 0x0628, 0x19d0, 0x8d0f, 
                                 0xd9b2, 0xa7da, 0x63b7, 0xa386, 0x52ab, 0x0c35
                                 };
    /* correct answer */
    const uint16_t result[24] = {0xd3d1, 0x5071, 0x3963, 0x7b98, 0x0c1d, 0xba17, 
                                 0xb8d9, 0x745d, 0xb911, 0xbe8e, 0x675b, 0x32dd, 
                                 0x272f, 0x9cfa, 0x567b, 0x9925, 0x340f, 0x9d35, 
                                 0x5679, 0x2573, 0xd58f, 0xdfcc, 0x7431, 0xda4e
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_14(void** state)
{

            uint16_t num1[24] = {0x2fca, 0x3ebd, 0x50bb, 0x92b7, 0x33cb, 0xbb85, 
                                 0x6b35, 0xce83, 0x3ed5, 0x3700, 0x0f1c, 0x5d0f, 
                                 0xb4c6, 0xed12, 0x3853, 0x9f82, 0x00b3, 0x9509, 
                                 0x5071, 0xb6ff, 0x0a7a, 0xf97f, 0x4aee, 0x19be
                                 };
      const uint16_t num2[24] = {0x74c7, 0xa171, 0x16b4, 0xe852, 0x18a1, 0xcd3c, 
                                 0x07f2, 0xd881, 0x009d, 0x6a68, 0x2cd0, 0xa0e1, 
                                 0x953e, 0x423d, 0x94f6, 0xd710, 0xd3de, 0x3f68, 
                                 0x5ce9, 0xeb2d, 0x92e2, 0x21f8, 0xe9fa, 0x60d2
                                 };
    /* correct answer */
    const uint16_t result[24] = {0xa491, 0xe02e, 0x676f, 0x7b09, 0x4c6d, 0x88c1, 
                                 0x7328, 0xa704, 0x3f73, 0xa168, 0x3bec, 0xfdf0, 
                                 0x4a04, 0x2f50, 0xcd4a, 0x7692, 0xd492, 0xd471, 
                                 0xad5a, 0xa22c, 0x9d5d, 0x1b77, 0x34e9, 0x7a91
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_15(void** state)
{

            uint16_t num1[24] = {0xb522, 0x68cf, 0x3de3, 0x397a, 0x32d7, 0xbd6a, 
                                 0x20c1, 0xad24, 0x7a6e, 0x6e0b, 0x5e7d, 0x10ab, 
                                 0xd025, 0x0060, 0x4507, 0xfafd, 0xc8c5, 0x48a0, 
                                 0x2be4, 0x6622, 0x5ce8, 0xb132, 0x1f02, 0x6b40
                                 };
      const uint16_t num2[24] = {0x1124, 0x7a47, 0x3b7a, 0xc054, 0xf52f, 0xaf69, 
                                 0xf859, 0xc3d4, 0x9163, 0xc218, 0x643b, 0xc5b2, 
                                 0xa4fd, 0x5137, 0xf059, 0x7696, 0x93f3, 0x431e, 
                                 0x93ee, 0xe504, 0x6f7a, 0x57bd, 0xf653, 0x7068
                                 };
    /* correct answer */
    const uint16_t result[24] = {0xc646, 0xe316, 0x795d, 0xf9ce, 0x2806, 0x6cd4, 
                                 0x191b, 0x70f9, 0x0bd2, 0x3024, 0xc2b9, 0xd65d, 
                                 0x7522, 0x5198, 0x3560, 0x7194, 0x5cb9, 0x8bbf, 
                                 0xbfd2, 0x4b26, 0xcc63, 0x08ef, 0x1556, 0xdba9
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_16(void** state)
{

            uint16_t num1[24] = {0xef44, 0x3d33, 0x7c24, 0xec4b, 0xba46, 0x8de6, 
                                 0xb72e, 0xf3e5, 0x679c, 0xf57d, 0x1fc7, 0xf596, 
                                 0xd5b2, 0x4322, 0x422c, 0xa10e, 0xcaa5, 0x2978, 
                                 0x6c64, 0x260b, 0x6003, 0x8436, 0x387d, 0x1778
                                 };
      const uint16_t num2[24] = {0x42d6, 0x9531, 0x66d9, 0x2a34, 0x360c, 0xa7d6, 
                                 0x2ceb, 0x4385, 0x05b6, 0x0795, 0x13c9, 0x0d74, 
                                 0xf5b5, 0xa9df, 0x8d05, 0x9836, 0xd509, 0xb226, 
                                 0xf416, 0x1a03, 0x898c, 0x73f5, 0x7377, 0xa077
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x321a, 0xd265, 0xe2fd, 0x167f, 0xf053, 0x35bc, 
                                 0xe41a, 0x376a, 0x6d53, 0xfd12, 0x3390, 0x030a, 
                                 0xcb68, 0xed02, 0xcf31, 0x3944, 0x9faf, 0xdb9f, 
                                 0x607a, 0x400f, 0xe98f, 0xf82b, 0xabf4, 0xb7ef
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_17(void** state)
{

            uint16_t num1[24] = {0x98ec, 0x2829, 0xc4a1, 0x1669, 0x9e5b, 0xee64, 
                                 0x28ff, 0x4b9c, 0x9e96, 0x21f4, 0x3cae, 0xbe9e, 
                                 0x3fde, 0x9ab9, 0x29b4, 0x2e80, 0xc331, 0x7153, 
                                 0xd97c, 0xd743, 0xe4c3, 0x8315, 0x3c44, 0xb87c
                                 };
      const uint16_t num2[24] = {0x56ba, 0x2738, 0xa285, 0x9080, 0xfe65, 0x94c9, 
                                 0xbad4, 0xb5f9, 0xc208, 0xf626, 0x12b1, 0x2edf, 
                                 0x5d6b, 0x2b1e, 0xb3ae, 0x2d88, 0xd41e, 0xc9e1, 
                                 0x13f0, 0xf092, 0x9416, 0xa564, 0xb5b1, 0x21cb
                                 };
    /* correct answer */
    const uint16_t result[24] = {0xefa6, 0x4f61, 0x6726, 0xa6ea, 0x9cc0, 0x832e, 
                                 0xe3d4, 0x0195, 0x609f, 0x181b, 0x4f60, 0xed7d, 
                                 0x9d49, 0xc5d7, 0xdd62, 0x5c08, 0x974f, 0x3b35, 
                                 0xed6d, 0xc7d5, 0x78da, 0x287a, 0xf1f6, 0xda47
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_18(void** state)
{

            uint16_t num1[24] = {0xdcd2, 0x8630, 0x1029, 0x1685, 0xe3dc, 0x60d9, 
                                 0x25d3, 0xc76f, 0x0f71, 0x470a, 0xd984, 0x8548, 
                                 0xcf17, 0x3ce5, 0x69be, 0xbe4a, 0xa1b0, 0xeadf, 
                                 0x3277, 0x8708, 0x006f, 0xe3d1, 0xf8d0, 0x328b
                                 };
      const uint16_t num2[24] = {0x00c2, 0x8279, 0xa4eb, 0x84fd, 0xd168, 0x24ad, 
                                 0xb6ae, 0x4bec, 0x388c, 0x4095, 0x444a, 0xa165, 
                                 0x6710, 0x8d04, 0x2e8c, 0x969f, 0x6e38, 0x7c8c, 
                                 0x590e, 0xa3ea, 0x7b6e, 0x6a2e, 0x554a, 0x955c
                                 };
    /* correct answer */
    const uint16_t result[24] = {0xdd94, 0x08a9, 0xb515, 0x9b82, 0xb544, 0x8587, 
                                 0xdc81, 0x135b, 0x47fe, 0x879f, 0x1dce, 0x26ae, 
                                 0x3628, 0xc9ea, 0x984a, 0x54e9, 0x0fe9, 0x676c, 
                                 0x8b86, 0x2af2, 0x7bde, 0x4dff, 0x4e1b, 0xc7e8
                                 };

    add_U384(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {
        assert_int_equal(num1[i], result[i]);
    }
}

static void test_add_U384_19(void** state)
{

            uint16_t num1[24] = {0xd0cd, 0x1e23, 0xe540, 0x94c4, 0xcf2c, 0x924f, 
                                 0x1f92, 0xfe60, 0x8206, 0xab44, 0xe2ff, 0x97a1, 
                                 0x971a, 0x9fa7, 0x0bc9, 0xe928, 0xa827, 0x3d5a, 
                                 0x1756, 0x32b1, 0x7d7d, 0x652d, 0xdf23, 0x4366
                                 };
      const uint16_t num2[24] = {0x4d7b, 0x6bc0, 0x940b, 0xa50b, 0x41ed, 0xf8cd, 
                                 0x8487, 0x5742, 0x75cd, 0xf131, 0x5f13, 0x5274, 
                                 0xab4f, 0xf80d, 0x9acf, 0xfac8, 0x90a0, 0x67f1, 
                                 0x18f3, 0x2557, 0x339d, 0x0f18, 0xecc9, 0x7851
                                 };
    /* correct answer */
    const uint16_t result[24] = {0x1e48, 0x89e4, 0x794b, 0x39d0, 0x111a, 0x8b1d, 
                                 0xa41a, 0x55a2, 0xf7d4, 0x9c75, 0x4213, 0xea16, 
                                 0x4269, 0x97b5, 0xa699, 0xe3f0, 0x38c8, 0xa54c, 
                                 0x3049, 0x5808, 0xb11a, 0x7445, 0xcbec, 0xbbb8
                                 };

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
    
       cmocka_unit_test(test_add_U384_0),
        
       cmocka_unit_test(test_add_U384_1),
        
       cmocka_unit_test(test_add_U384_2),
        
       cmocka_unit_test(test_add_U384_3),
        
       cmocka_unit_test(test_add_U384_4),
        
       cmocka_unit_test(test_add_U384_5),
        
       cmocka_unit_test(test_add_U384_6),
        
       cmocka_unit_test(test_add_U384_7),
        
       cmocka_unit_test(test_add_U384_8),
        
       cmocka_unit_test(test_add_U384_9),
        
       cmocka_unit_test(test_add_U384_10),
        
       cmocka_unit_test(test_add_U384_11),
        
       cmocka_unit_test(test_add_U384_12),
        
       cmocka_unit_test(test_add_U384_13),
        
       cmocka_unit_test(test_add_U384_14),
        
       cmocka_unit_test(test_add_U384_15),
        
       cmocka_unit_test(test_add_U384_16),
        
       cmocka_unit_test(test_add_U384_17),
        
       cmocka_unit_test(test_add_U384_18),
        
       cmocka_unit_test(test_add_U384_19),
        
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}


