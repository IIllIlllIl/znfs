//
// Created by Phoenix Wang on 2021/9/20.
//

#ifndef ZNFS_DIFF_H
#define ZNFS_DIFF_H

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>
#include <ctime>
#include <string>
#include <cstring>

class diff {
// private:
    int file_1, file_2;
    std::string path_1, path_2;
    const int buffer_size = 4096;  // 4KB
    char buffer1[4096], buffer2[4096];

public:
    diff(const char * path1, const char * path2);

    int dif();
};


#endif //ZNFS_DIFF_H
