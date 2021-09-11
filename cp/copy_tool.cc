//
// Created by Phoenix Wang on 2021/9/11.
//

#include "copy_tool.h"

copy_tool::copy_tool(const char * open_path, const char * create_path){
    file_input = open(open_path, O_RDONLY);
    file_output = creat(create_path, 0644);
}

int copy_tool::copy() {
    if (file_input == -1) {
        return -1;
    }

    if (file_output == -1) {
        return -2;
    }

    ssize_t read_size;
    while((read_size = read(file_input, buffer, buffer_size)) > 0) {
        if (write(file_output, buffer, read_size) != read_size) {
            return -4;
        }
    }

    if (read_size == -1) {
        return -3;
    }

    if (close(file_input) == -1 || close(file_output) == -1) {
        return -5;
    }

    return 0;
}