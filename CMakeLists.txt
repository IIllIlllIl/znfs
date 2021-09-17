cmake_minimum_required(VERSION 3.20)
project(znfs)

set(CMAKE_CXX_STANDARD 14)

add_executable(znfs main.cpp tar.cpp tar.h compress.h decompress.h huffmanTree.h)
