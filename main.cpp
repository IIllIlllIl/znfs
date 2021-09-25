//
// test
//

#include "simple_tar.h"
using namespace std;

int main() {
    string root = "../test/dir/dir2/";
    string dest = "../test/dir/dir2/cp_";
    string file = "fifo";
    string name = "dir3.star";

    dir_node dn((root + file).c_str(), (dest + file).c_str());
    simple_tar st;

    //cout<<dn.copy()<<endl;
    //st.tar("../test/dir/", name);
    st.untar("../test/cp_dir/",name);

    return 0;
}
