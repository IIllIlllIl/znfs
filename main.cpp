//
// test
//

#include <iostream>
#include <string>
#include "./cp/copy_tool.h"
#include "./cp/dir_node.h"
#include "./cp/diff.h"
using namespace std;

int main() {
    string root = "../test/dir/";
    string dest = root + "dir2/";
    string file = "txt";

    dir_node dn((root + file).c_str(), (dest + file).c_str());
    //copy_tool cp((root + file).c_str(), (dest + file).c_str());
    //diff df((root + file).c_str(), (dest + file).c_str());

    cout<<dn.diff_tree()<<endl;

    return 0;
}
