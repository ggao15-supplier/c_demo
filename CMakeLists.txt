# cmake_minimum_required(VERSION <specify CMake version here>)
project(start)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(start
        global.h
        main.cpp)
