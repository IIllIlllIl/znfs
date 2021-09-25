//
// test
//

#include "simple_tar.h"
using namespace std;

int main() {
    string root = "../test/dir2";
    string dest = "../test/dir3";

    simple_tar st;

    st.package(root, "../test");
    st.unpackage("../test/dir.pkg", dest);

    return 0;
}
