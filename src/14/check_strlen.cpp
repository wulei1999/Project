#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <array>

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

public:
    CheckStrLen(/* args */) = default;
    bool operator()(int ts_num , string &str){
        return str.size() == ts_num;
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
    CheckStrLen cks;
    std::array<int, 10> arr{0};
    while (inf >> word) {
        for (int i = 1; i < 10; i++)
            if(cks(i, word)){
                ++arr[i];
                break;
            }
    }
    for (int j = 1; j < arr.size(); j++) {
        cout << "文本文件中长度为" << j << "的字符串有： "<<arr[j] << "个"<< endl;
    }
    return 0;
}
