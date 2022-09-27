from random import randint

# Using readlines()
file1 = open('../src/main.c','r')
lines_with_n = file1.readlines()


#excludes unnecessary 0x0000 in array:
def exclude_zeroes(array,size):
    for i in range(size//4**2):
      tmp_array=array
      tmp=i
      if(array[i]=="0000"):
          check_0=0
          for j in range(i,len(array)):
             if(array[j]=="0000"):
                 check_0+=1 
          if(len(array)-i==check_0 and check_0!=0):
                tmp_array=array[:i]
                break
                 
    return tmp_array






#creates hex array from number and transforms it into string
def create_printable(num,size):
    num=str(num)
    j=i=0
    num_array=[0]*(size//4**2)
    num_str=""
    while(i<size//4):
        num_array[i//4]=num[i:i+4]
        i+=4
    num_array=num_array[::-1]
    num_array=exclude_zeroes(num_array,384)
    while(j<len(num_array)):
        num_str+="0x"+str(num_array[j])
        j+=1
        if(j<(size//4**2)):
           num_str+=", "
    return (num_str)


# corrects number if its too short
def correct_number(num, size):
    num= str(num)
    num = '0' * ((size // 4) - len(num[2:])) + num[2:]
    return num


# generates random function(first is min edge, second is max edge case) n-time with values from desired minimum and maximum, choose bit size with size
def create_random_functions(n=20, size=384,value_min=0, value_max=-1+2**384):
    size=size
    func_1 = ""
    i = 0
    while (i< n):
        _result_ = num_1 = num_2 = 0
        if(i == 0):
            num_1 = num_2 =value_min
        elif(i == 1):
            num_1 = num_2 =value_max
        else:
            num_1 = randint(value_min, value_max)
            num_2 = randint(value_min, value_max - num_1)
        _result_ = num_1 + num_2
        num_1 = hex(num_1)
        num_2 = hex(num_2)
        _result_ = hex(_result_)
        num_1 = correct_number(num_1,size)
        num_2 = correct_number(num_2,size)
        _result_ = correct_number(_result_,size)
        func_1 += """
static void test_add_U{name}_{ver}(void** state)
{{
           /*  check_num1={check1}
               check_num2={check2}
             check_result={check3}*/
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
}}""".format(name=size,ver=i,num1=create_printable(num_1,size),
num2=create_printable(num_2,size),result=create_printable(_result_,size),check1=num_1,check2=num_2,check3=_result_,array_size=size//4**2)
        i+=1
    return func_1


# writes in main, same n as in create_random_functions_1
def create_call_function(n=20,size=384):
    unit_tests = ""
    for i in range(n):
        unit_tests += """
      cmocka_unit_test(test_add_U{name}_{ver}),
""".format(name=size,ver=i)
    return unit_tests


text ="""
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

""".format(append=create_random_functions(),append_2=create_call_function())

with open('../src/main.c', 'w') as out:
    out.write(text + '\n')

print(text)