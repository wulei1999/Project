
#include <iostream>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
class PrintString {
private:
    /* data */
    ostream &os;
    istream &is;
    string &str;

public:
    PrintString(istream &in = cin, ostream &out = cout, string s = "") : is(in), os(cout), str(s) {}
    ~PrintString() = default;
    string operator()()const{
        //string str;
        if(!getline(is, str)){
            str = "";
        }
        return str;
    }
};

int main(){
    vector<string> vstr;
    PrintString ps(cin);
    while(true){
        string str = ps();
        if(!str.empty()){
            vstr.push_back(str);
        }
        else{
            break;
        }
    }
    return 0;
}