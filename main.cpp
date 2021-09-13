#include <iostream>
#include <string>
#include "./cp/copy_tool.h"
using namespace std;

int main() {
    string root = "../test/";
    string dest = "../test/cp_";
    string file = "lns";
    copy_tool cp((root + file).c_str(), (dest + file).c_str());
    cout<<cp.copy();
    return 0;
}
