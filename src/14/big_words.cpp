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
using std::find_if;
using std::for_each;
using std::ifstream;
using std::istream;
using std::ostream;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;

void eliminate_duplicate_words(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string &word, const string ending) {
    return (ctr > 1) ? word + ending : word;
}

class IsShorter {
public:
    bool operator()(const string &str1, const string str2) {
        return str1.length() < str2.length();
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

class PrintString {
public:
    void operator()(const string &str) {
        cout << str << " ";
    }
};

void biggies(vector<string> &words, vector<string>::size_type sz) {
    eliminate_duplicate_words(words);
    CheckStrLenOverRange ckslor(sz);
    IsShorter is;
    stable_sort(words.begin(), words.end(), is);
    auto word_condition = find_if(words.begin(), words.end(), ckslor);
    auto count = words.end() - word_condition;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer"
         << endl;
    PrintString ps;
    for_each(word_condition, words.end(), ps);
    cout << endl;
}

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
    biggies(file, 10);

    return 0;
}
