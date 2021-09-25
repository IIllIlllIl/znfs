//
// Created by Phoenix Wang on 2021/9/25.
//

#include "simple_tar.h"


#define MAX(x, y) (((x) > (y)) ? (x) : (y))

std::vector<std::string> split(const std::string &str, const std::string &delim) {
    std::vector<std::string> result;
    if (str == "") {
        return result;
    }
    char* strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());

    char* d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char* p = strtok(strs, d);
    while(p) {
        std::string s = p;
        result.push_back(s);
        p = strtok(NULL, d);
    }

    return result;
}

int simple_tar::toTar(const char * filename, const char ** files, int move) {
    char verbosity = 0;

    int rc = 0;
    struct tar_t * archive = NULL;
    int fd = -1;

    if ((fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR)) == -1){
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return -1;
    }

    if (tar_write(fd, &archive, 1, files, verbosity, move) < 0){
        rc = -1;
    }

    return rc;
}

int simple_tar::toExtract(const char * filename, const char * extract_tgt_dir) {
    char verbosity = 0;

    int rc = 0;
    struct tar_t * archive = NULL;
    int fd = -1;

    if ((fd = open(filename, O_RDWR)) < 0){
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return -1;
    }

    // read in data from fd(tgt_pack) -> archive struct list
    if (tar_read(fd, &archive, verbosity) < 0){
        tar_free(archive);
        close(fd);
        return -1;
    }

    // write data from archive strut list -> extrat_tgt_dir
    if (tar_extract(fd, archive, verbosity, extract_tgt_dir) < 0)
        rc = -1;

    return rc;
}



int simple_tar::tar(std::string file_path, std::string package_name) {
    const char * src_dir = file_path.c_str();
    const char * filename = package_name.c_str();
    const char ** files = (const char **) &src_dir;

    int rc = 0;

    int move = 0;
    size_t len = strlen(src_dir);
    size_t len_redundant = len;
    char * path = (char*) calloc(len + 1, sizeof(char));
    strncpy(path, src_dir, len);

    while (--len_redundant && (path[len_redundant] != '/'));
    move = len_redundant + 1;

    rc = toTar(filename, files, move);

    return rc;
}

int simple_tar::untar(std::string file_path, std::string package_name) {
    const char * extract_tgt_dir = file_path.c_str();  // need to add '/' at last
    const char * filename = package_name.c_str();

    int rc = 0;

    rc = toExtract(filename, extract_tgt_dir);

    return rc;
}

int simple_tar::package(std::string file_path, std::string package_path) {
    if (file_path.at(file_path.length() - 1) == '/') {
        file_path = file_path.substr(0, file_path.length() - 1);
    }
    if (package_path.at(package_path.length() - 1) != '/') {
        package_path += '/';
    }
    std::vector<std::string> paths = split(file_path, "/");
    std::string full_name = paths[paths.size() - 1];
    std::string name = split(full_name, ".")[0];

    // ?/xxx.xx -> ./xxx.tt
    int tar_flag = tar(file_path, "./" + name + ".tt");
    if (tar_flag < 0) {
        return -tar_flag;
    }

    huffmanEncode hfEncode; // huffman压缩类
    // huffman压缩函数： 参数1-要压缩的文件，参数2-压缩生成的文件
    // ./xxx.tt -> ./xxx.cps
    bool encode_flag = hfEncode.encode(("./" + name + ".tt").c_str(),
                                       ("./" + name + ".cps").c_str());
    if (encode_flag == false) {
        return 101;
    }

    // ./xxx.cps -> ?/xxx.pkg
    copy_tool cp(("./" + name + ".cps").c_str(),
                 (package_path + name + ".pkg").c_str());
    int cp_flag = cp.copy();
    if (cp_flag < 0) {
        return 200 + cp_flag;
    }

    return 0;
}

int simple_tar::unpackage(std::string package_path, std::string target_path) {
    if (package_path.at(package_path.length() - 1) == '/') {
        package_path = package_path.substr(0, package_path.length() - 1);
    }
    if (target_path.at(target_path.length() - 1) != '/') {
        target_path += '/';
    }

    std::vector<std::string> paths = split(package_path, "/");
    std::string full_name = paths[paths.size() - 1];
    std::vector<std::string> name_vec = split(full_name, ".");
    if (name_vec.size() < 0){
        return 102;
    }
    std::string name = name_vec[0];
    std::string type = name_vec[name_vec.size() - 1];

    // ?/xxx.pkg -> ./xxx.cps
    if (type == "pkg") {
        copy_tool cp(package_path.c_str(), ("./" + name + ".cps").c_str());
    }

    huffmanDecode hfDecode; // huffman解压缩类
    // huffman解压缩函数： 参数1-要解压缩的文件，参数2-解压缩还原的文件
    // ./xxx.cps -> ./xxx.tt
    bool decode_flag = hfDecode.decode(("./" + name + ".cps").c_str(),
                                       ("./" + name + ".tt").c_str());
    if (decode_flag == false) {
        return 101;
    }

    // ./xxx.tt -> ?/xxx.xx
    int untar_flag = untar(target_path, "./" + name + ".tt");
    if (untar_flag < 0) {
        return - untar_flag;
    }

    return 0;
}