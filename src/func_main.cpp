#include "func.h"

int main(int argc, char *argv[]) {
    vector<int> v_int;
    ifstream inf(argv[1]);
    ofstream outf1(argv[2]), outf2(argv[3]);
    if (!inf) {
        cerr << "openfile error" << endl;
    }
    if (!outf1 || !outf2) {
        cerr << "open out file error" << endl;
    }
    istream_iterator<int> in_iter(inf), eof;
    ostream_iterator<int> out_iter1(outf1, " "), out_iter2(outf2, "\n");
    while(in_iter != eof){
        if(*in_iter & 1){
            *out_iter1++ = *in_iter++;
        }
        else{
            *out_iter2++ = *in_iter++;
        }
    }
    return 0;
}