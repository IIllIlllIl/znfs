cmake_minimum_required(VERSION 3.20)
project(znfs)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        znfs main.cpp
        cp/copy_tool.cc cp/copy_tool.h cp/dir_node.cc cp/dir_node.h cp/diff.cc cp/diff.h
        tar/tar.h tar/tar.cpp simple_tar.cc
        compress/compress.h compress/decompress.h compress/huffmanTree.h
        simple_tar.h)
