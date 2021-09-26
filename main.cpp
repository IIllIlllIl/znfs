//
// test
//

#include "simple_tar.h"
#include "net/client.h"
using namespace std;

int main() {

    //上传
    char pass[]="456";
    char opera[]="update";
    char src[] = "../test/dir";
    char dest[] = "";

    //下载
//    char pass[]="456";
//    char opera[]="download";
//    char src[] = "dir.pkg";
//    char dest[] = "../test/dir7";

    //展示服务器端的文件
//    char pass[]="456";
//    char opera[]="show";
//    char src[] = "";
//    char dest[] = "";

    int success=client(pass,opera,src,dest);


    return 0;
}
