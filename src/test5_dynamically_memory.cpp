#include "str_blob.h"
#include <fstream>
#include "str_blob_ptr.h"

int main(int argc, char *argv[]) {
    #if 0
    ifstream inf(argv[1]);
    if(!inf){
        cerr << "open file error" << endl;
        return -1;
    }
    StrBlob b;
    string str;
    while (getline(inf, str)) {
        b.push_back(str);
    }
    #endif
    StrBlob b({"111", "222", "333"});
    for (auto it = b.begin(); neq(it, b.end()); it.incr()){
        cout << it.deref() << endl;
    }
    return 0;
}