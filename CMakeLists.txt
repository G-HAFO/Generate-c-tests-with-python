cmake_minimum_required(VERSION 3.16)

# name project
project(tests)

# download cmocka git GIT_REPOSITORY for cmocka.h 
include(cmake/FetchCMocka.cmake)

# add static library asm into project
add_subdirectory(lib)

#include .h files
include_directories(lib, 
                    inc)
# minimal unit ctest
enable_testing()

# make 
add_executable(tests src/main.c)

# show warrings
target_compile_options(tests PRIVATE -Wall -Wextra )

# The order is VERY importnet (else Lineker will not work)
target_link_libraries(tests 
                    ASMlib
                    cmocka-static
                    )

# using 99 standard
target_compile_features(tests PRIVATE c_std_99)

# invoke command tests
add_test(NAME tests COMMAND tests)
