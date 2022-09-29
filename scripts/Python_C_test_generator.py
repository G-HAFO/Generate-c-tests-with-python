"""

Usage:
  Python_C_test_generator.py (-B|--build) <type>
  Python_C_test_generator.py (-h | --help)

Options:
  -h --help     Show this screen.
  -B --build    Builds in desired format ( PC or stevec )
"""
from docopt import docopt
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
        if j < (size // 16) and j < len(num_array):
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
    for i in range(1, size // 16):
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


def create_random_functions(n=20, build_type="PC", size=384, value_min=0, value_max=-1 + 2 ** 384):
    """
    generates random functions, includes both edge cases
    default values already set
    :param value_max: maximal possible value
    :param value_min: minimal value
    :param size: desired size
    :type n: how many fuctions you want to create
    """
    size = size
    func_PC = func_stevec = ""
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
        func_PC += (f"\n"
        f"static void test_add_U{size}_{i}(void** state)\n"
        f"{{\n"
        f"\n"
        f"            uint16_t num1[{size // 4 ** 2}] = {{{create_printable(num_1, size)}}};\n"
        f"      const uint16_t num2[{size // 4 ** 2}] = {{{create_printable(num_2, size)}}};\n"
        f"    /* correct answer */\n"
        f"    const uint16_t result[{size // 4 ** 2}] = {{{create_printable(result, size)}}};\n"
        f"\n"
        f"    add_U{size}(num1, num2);\n"
        f"\n"
        f"    /* check result */\n"
        f"    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)\n"
        f"    {{\n"
        f"        assert_int_equal(num1[i], result[i]);\n"
        f"    }}\n"
        f"}}\n")
        func_stevec += (f"\n"
        f"int16_t test_add_U{size}_{i}()\n"
        f"{{\n"
        f"\n"
        f"            uint16_t num1[{size // 4 ** 2}] = {{{create_printable(num_1, size)}}};\n"
        f"      const uint16_t num2[{size // 4 ** 2}] = {{{create_printable(num_2, size)}}};\n"
        f"    /* correct answer */\n"
        f"    const uint16_t result[{size // 4 ** 2}] = {{{create_printable(result, size)}}};\n"
        f"\n"
        f"    add_U{size}(num1, num2);\n"
        f"\n"
        f"    /* check result */\n"
        f"    for (int i = 0; i < sizeof(num1) / sizeof(uint16_t); i++)\n"
        f"        if(num1[i] != result[i]){{\n"
        f"            return RESULT_ERROR;\n"
        f"    }}\n"
        f"   return RESULT_ERROR;\n"
        f"}}\n")
        i += 1
    if build_type == "PC":
        return func_PC
    else:
        return func_stevec


def create_call_function(build_type="PC", size=384, n=20):
    """
     call functions in main
     default values already set
    :param n: how many we want to create, must be same as in create_random_functions
    :param size: desired size
    :return:
    """
    unit_tests = ""
    if build_type == "PC":
        for i in range(n):
            unit_tests += (f"\n"
            f"       cmocka_unit_test(test_add_U{size}_{i}),\n"
            f"        ")
    else:
        for i in range(n):
            unit_tests += (f"\n"
            f"        if(test_add_U{size}_{i}() == RESULT_ERROR)\n"
            f"    {{\n"
            f"	 assert(0);\n"
            f"	return RESULT_ERROR;\n"
            f"    }}\n"
            f"         ")
    return unit_tests


def create_text(build_ver):
    c_text_PC = (f"\n"
    f"#include <stdio.h>\n"
    f"#include <stdlib.h>\n"
    f"#include <setjmp.h>\n"
    f"#include <stdarg.h>\n"
    f"#include <stddef.h>\n"
    f"#include <stdint.h>\n"
    f"#include <cmocka.h>\n"
    f"#include \"dbg.h\"\n"
    f"\n"
    f"{create_random_functions(build_type=build_ver)}\n"
    f"\n"
    f"int main(int argc, char **argv)\n"
    f"{{\n"
    f"    const struct CMUnitTest tests[] =\n"
    f"    {{\n"
    f"    {create_call_function(build_type=build_ver)}\n"
    f"    }};\n"
    f"\n"
    f"    return cmocka_run_group_tests(tests, NULL, NULL);\n"
    f"}}\n"
    f"\n")
    c_text_stevec = (f"\n"
    f"#include <assert.h>\n"
    f"#include <string.h>\n"
    f"\n"
    f"#include \"platform.h\"\n"
    f"#include \"math_256.h\"\n"
    f"#include \"math_384.h\"\n"
    f"\n"
    f"{create_random_functions(build_type=build_ver)}\n"
    f"\n"
    f"int16_t tests_add_U384(void)\n"
    f"{{\n"
    f"\n"
    f"    {create_call_function(build_type=build_ver)}\n"
    f"   \n"
    f"    return RESULT_OK;\n"
    f"}}\n"
    f"\n"
    f"    ")
    if build_ver == "PC":
        return c_text_PC
    else:
        return c_text_stevec


def main(build_type):
    write_in_file('../test/test.c', create_text(build_type))


if __name__ == "__main__":
    arguments = docopt(__doc__)
    if arguments['--build'] or arguments['-B']:
        main(arguments['<type>'])
