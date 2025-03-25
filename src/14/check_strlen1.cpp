#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <array>
#include <algorithm>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::ifstream;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

class CheckStrLen
{
private:
    /* data */
    int len;
    
public:
    CheckStrLen(int l): len(l){}
    bool operator()(const string &str){
        return str.length() == len;
    }
};

int main(int argc, char *argv[]){
    if(argc < 2)
        throw std::invalid_argument("缺少文件参数");
    ifstream inf(argv[1]);
    if(!inf){
        throw std::runtime_error("打开文件失败");
    }
    string word;
    vector<string> file;
    while (inf >> word) {
        file.push_back(word);
    }
    for (int j = 1; j < 10; j++) {
        CheckStrLen cks(j);
        cout << "len: " << j << "number is: " << std::count_if(file.begin(), file.end(), cks) << endl;
    }
    return 0;
}
