from random import randint


def write_in_file(path_to_file, text):  # '../src/main.c'
    """
    writes desired text to selected file
    :param path_to_file: path to desired file
    :param text: text we want to write to file
    """
    with open(path_to_file, 'w') as out:
        out.write(text + '\n')


def correct_number(num, size):
    """
    corrects number, adds 0 if the number is too short
    :param num:  integer value
    :param size: a bit size, declared in create_random_functions
    :return:  correct length int
    """
    num = str(num)
    num = '0' * ((size // 4) - len(num[2:])) + num[2:]
    return num


def create_printable(num, size):
    """
    splits number in hex values and transforms it into string
    :param num: number we want to print
    :param size: a bit size, declared in create_random_functions
    :return: string
    """
    num = str(num)
    j = i = 0
    num_array = [0] * (size // 16)
    num_str = ""
    while i < size // 4:
        num_array[i // 4] = num[i:i + 4]
        i += 4
    num_array = num_array[::-1]
    num_array = exclude_zeroes(num_array, 384)
    while j < len(num_array):
        num_str += "0x" + str(num_array[j])
        j += 1
        if j < (size // 16) and j<len(num_array):
            num_str += ", "
        if j % 6 == 0 and j != 0:
            num_str += '\n' + ' ' * 33
    return num_str


def exclude_zeroes(array, size):
    """
    excludes unnecessary 0x0000 in array:

    :param array: array we want to modify
    :param size: a bit size, declared in create_random_functions
    :return: num array without 0x000
    """
    global tmp_array
    for i in range(1,size // 16):
        tmp_array = array
        if array[i] == "0000":
            check_0 = 0
            for j in range(i, len(array)):
                if array[j] == "0000":
                    check_0 += 1
            if len(array) - i == check_0 and check_0 != 0:
                tmp_array = array[:i]
                break

    return tmp_array


def create_random_functions(n=20, size=384, value_min=0, value_max=-1 + 2 ** 384):
    """
    generates random functions, includes both edge cases
    default values already set
    :param value_max: maximal possible value
    :param value_min: minimal value
    :param size: desired size
    :type n: how many fuctions you want to create
    """
    size = size
    func_1 = ""
    i = 0
    while i < n:
        if i == 0:
            num_1 = num_2 = value_min
        elif i == 1:
            num_1 = num_2 = value_max
        else:
            num_1 = randint(value_min, value_max)
            num_2 = randint(value_min, value_max - num_1)
        result = num_1 + num_2
        num_1 = hex(num_1)
        num_2 = hex(num_2)
        result = hex(result)
        num_1 = correct_number(num_1, size)
        num_2 = correct_number(num_2, size)
        result = correct_number(result, size)
        func_1 += """
static void test_add_U{name}_{ver}(void** state)
{{

            uint16_t num1[{array_size}] = {{{num1}}};
      const uint16_t num2[{array_size}] = {{{num2}}};
    /* correct answer */
    const uint16_t result[{array_size}] = {{{result}}};

    add_U{name}(num1, num2);

    /* check result */
    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)
    {{
        assert_int_equal(num1[i], result[i]);
    }}
}}
""".format(name=size, ver=i, num1=create_printable(num_1, size),
           num2=create_printable(num_2, size), result=create_printable(result, size), array_size=size // 16)
        i += 1
    return func_1


def create_call_function(n=20, size=384):
    """
     call functions in main
     default values already set
    :param n: how many we want to create, must be same as in create_random_functions
    :param size: desired size
    :return:
    """
    unit_tests = ""
    for i in range(n):
        unit_tests += """
       cmocka_unit_test(test_add_U{name}_{ver}),
        """.format(name=size, ver=i)
    return unit_tests


def create_text():
    c_text = """
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>
#include "dbg.h"

{append}

int main(int argc, char **argv)
{{
    const struct CMUnitTest tests[] =
    {{
    {append_2}
    }};

    return cmocka_run_group_tests(tests, NULL, NULL);
}}

""".format(append=create_random_functions(), append_2=create_call_function())
    return c_text


def main():
    write_in_file('text.txt', create_text())


if __name__ == "__main__":
    main()

