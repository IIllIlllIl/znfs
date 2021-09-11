#include <iostream>
#include "./cp/copy_tool.h"
using namespace std;

int main() {
    copy_tool cp("../test/text","../test/cp_text");
    cout<<cp.copy();
    return 0;
}
