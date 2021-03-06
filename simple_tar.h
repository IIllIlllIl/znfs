// simple tar
//
// Created by Phoenix Wang on 2021/9/25.
//
// Using codes of Li Xinhao, a program to package some files
//

#ifndef ZNFS_SIMPLE_TAR_H
#define ZNFS_SIMPLE_TAR_H

#include <iostream>
#include <string>
#include <vector>
#include "./cp/copy_tool.h"
#include "./cp/dir_node.h"
#include "./cp/diff.h"
#include "tar/tar.h"
#include "compress/compress.h"
#include "compress/decompress.h"

class simple_tar {
public:
    int package(std::string file_path, std::string package_path);
    int unpackage(std::string package_path, std::string target_path);

    int tar(std::string file_path, std::string package_name);
    int untar(std::string file_path, std::string package_name);

private:
    int toTar(const char * filename, const char ** files, int move);
    int toExtract(const char * filename, const char * extract_tgt_dir);
};


#endif //ZNFS_SIMPLE_TAR_H
