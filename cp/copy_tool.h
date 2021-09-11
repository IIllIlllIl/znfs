//
// Created by Phoenix Wang on 2021/9/11.
//

#ifndef ZNFS_COPY_TOOL_H
#define ZNFS_COPY_TOOL_H

#include <iostream>
#include <unistd.h>
#include <fcntl.h>

class copy_tool {
private:
    int file_input, file_output;
    const int buffer_size = 4096;  // 4KB
    char buffer[4096];

public:
    copy_tool(const char * open_path, const char * create_path);

    // copy normal file,
    // if the file is not found, return -1
    // if failed to create a new file, return -2
    // if read error, return -3
    // if write error, return -4
    // if close error, return -5
    // if success, return 0
    int copy();
};


#endif //ZNFS_COPY_TOOL_H
