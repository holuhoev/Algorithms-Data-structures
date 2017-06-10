cmake_minimum_required(VERSION 3.7)
project(2_15)


add_subdirectory(lib/gtest)

include_directories(lib/gtest/googlemock/include)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main/main.cpp
        main/btree.h
        main/btree.cpp
        main/btree_adapters.h
        main/utils.h)
add_executable(2_15 ${SOURCE_FILES})


target_link_libraries(2_15 gtest gtest_main)
