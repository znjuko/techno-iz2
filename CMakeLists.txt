CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

option(test "Build all tests." ON)

option(parallel "Build parallel version" OFF)

project(techno_iz2)

set(CMAKE_CXX_FLAGS         "-Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

set(CMAKE_C_FLAGS "--coverage")

add_subdirectory(src)
add_subdirectory(cmd)



if(test)
    enable_testing()

    add_subdirectory(vendor/googletest)

    add_subdirectory(tests)
endif(test)


unset(test CACHE)
unset(parallel CACHE)