#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

class CheckStrLenRange {
private:
    /* data */
    int min_len;
    int max_len;

public:
    CheckStrLenRange(int minl = 1, int maxl = 10) : min_len(minl), max_len(maxl) {}
    bool operator()(const string &str) {
        return str.length() >= min_len && str.length() <= max_len;
    }
};

class CheckStrLenOverRange {
private:
    /* data */
    int min_len = 0;

public:
    CheckStrLenOverRange() : min_len(0) {}
    CheckStrLenOverRange(int minl) : min_len(minl) {}
    bool operator()(const string &str) {
        return str.length() > min_len;
    }
};

int main(int argc, char *argv[]) {
    if (argc < 2)
        throw std::invalid_argument("缺少文件参数");
    ifstream inf(argv[1]);
    if (!inf) {
        throw std::runtime_error("打开文件失败");
    }
    string word;
    vector<string> file;
    while (inf >> word) {
        file.push_back(word);
    }
    CheckStrLenRange cksl(1, 10);
    CheckStrLenOverRange cksl_overrange(10);
    cout << "len in 1~10 word is: " << std::count_if(file.begin(), file.end(), cksl) << endl;
    cout << "len in > 10 word is: " << std::count_if(file.begin(), file.end(), cksl_overrange) << endl;
    return 0;
}
