//
// test
//

#include <iostream>
#include <string>
#include "./cp/copy_tool.h"
#include "./cp/dir_node.h"
using namespace std;

int main() {
    string root = "../test/dir/dir2/";
    string dest = root + "cp_";
    string file = "fifo";
    dir_node dn((root + file).c_str(), (dest + file).c_str());
    copy_tool cp((root + file).c_str(), (dest + file).c_str());
    cout<<cp.copy()<<endl;
    return 0;
}
