#include <iostream>
#include <string>
#include "pack/tar.h"
#include "compress/compress.h"
#include "compress/decompress.h"
using namespace std;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))


int toTar(const char * filename, const char ** files){
    char verbosity = 0;

    int rc = 0;
    struct tar_t * archive = NULL;
    int fd = -1;

    if ((fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR)) == -1){
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return -1;
    }

    if (tar_write(fd, &archive, 1, files, verbosity) < 0){
        rc = -1;
    }

    return rc;
}

int toExtract(const char * filename, const char ** files, const char * extract_tgt_dir){
    char verbosity = 0;

    int rc = 0;
    struct tar_t * archive = NULL;
    int fd = -1;

    if ((fd = open(filename, O_RDWR)) < 0){
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return -1;
    }

    // read in data
    if (tar_read(fd, &archive, verbosity) < 0){
        tar_free(archive);
        close(fd);
        return -1;
    }

    if (tar_extract(fd, archive, 0, files, verbosity, extract_tgt_dir) < 0)
        rc = -1;

    return rc;
}



int main() {
    const char * src_dir = "src_dir";
    const char * extract_tgt_dir = "../";
    const char * filename = "tgt_pack";
    const char * compressName = "tgt_pack.compress";
    const char ** files = (const char **) &src_dir;

    int rc = 0;
    int flag = 0;

    if (flag == 0){
        rc = toTar(filename, files);
        huffmanEncode hfEncode; // huffman压缩类
        // huffman压缩函数： 参数1-要压缩的文件，参数2-压缩生成的文件
        hfEncode.encode(filename,compressName);
    }else{
        huffmanDecode hfDecode; // huffman解压缩类
        // huffman解压缩函数： 参数1-要解压缩的文件，参数2-解压缩还原的文件
        hfDecode.decode(compressName,filename);
        rc = toExtract(filename, files, extract_tgt_dir);
    }


    return rc;
}
