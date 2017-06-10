cmake_minimum_required(VERSION 3.6)
project(2_7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES event.h
        event.cpp
        job.h
        job.cpp
        main.cpp
        simulator.h
        simulator.cpp
        fifo.h
        fifo.cpp)
add_executable(2_7 ${SOURCE_FILES})
