cmake_minimum_required(VERSION 3.16)

# name project
project(math_lib)

# download cmocka git GIT_REPOSITORY for cmocka.h 
include(cmake/FetchCMocka.cmake)

# add static library asm into project
# add_subdirectory(lib)

#include .h files
include_directories(lib,
        inc)

# main executable
add_executable(gg src/main.c)

#[===[
# UNIT TESTS
# minimal unit ctest
if(FALSE)
enable_testing()
add_executable(tests test/test.c)

# The order is VERY importnet (else Lineker will not work)
target_link_libraries(tests
        ASMlib
        cmocka-static
        )



# invoke command tests
add_test(NAME tests COMMAND tests)
endif()
]===]
#