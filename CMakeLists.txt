cmake_minimum_required(VERSION 3.19)
project(znfs)

set(CMAKE_CXX_STANDARD 14)

add_executable(znfs main.cpp cp/copy_tool.cc cp/copy_tool.h)
