cmake_minimum_required(VERSION 3.6)
project(2_9)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/gtest)

include_directories(lib/gtest/googlemock/include)

set(SOURCE_FILES src/main.cpp src/RailSystem.cpp src/RailSystem.cpp src/services.txt)
add_executable(2_9 ${SOURCE_FILES})

target_link_libraries(2_9 gtest gtest_main)
