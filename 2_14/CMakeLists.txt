cmake_minimum_required(VERSION 3.7)
project(2_14)


add_subdirectory(lib/gtest)

include_directories(lib/gtest/googlemock/include)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main/main.cpp main/rbtree.hpp )
add_executable(2_14 ${SOURCE_FILES})


target_link_libraries(2_14 gtest gtest_main)