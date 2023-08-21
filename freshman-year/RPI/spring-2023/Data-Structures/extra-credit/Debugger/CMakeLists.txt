cmake_minimum_required(VERSION 3.24)
project(Debugger)

set(CMAKE_CXX_STANDARD 14)

add_executable(Debugger
        operations.cpp operations_original.cpp)
