#include <algorithm>
#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "sales_item.h"

using std::accumulate;
using std::back_inserter;
using std::cin;
using std::count;
using std::cout;
using std::deque;
using std::endl;
using std::fill_n;
using std::find_if;
using std::for_each;
using std::forward_list;
using std::ifstream;
using std::initializer_list;
using std::invalid_argument;
using std::list;
using std::partition;
using std::sort;
using std::stable_sort;
using std::stack;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;
using std::begin;
using std::bind;
using std::cerr;
using std::copy;
using std::end;
using std::find;
using std::ifstream;
using std::inserter;
using std::istream_iterator;
using std::istringstream;
using std::iterator;
using std::map;
using std::multimap;
using std::multiset;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::pair;
using std::reverse_iterator;
using std::runtime_error;
using std::set;

map<string, string> trans_map(ifstream &inf) {
    string word;
    string value;
    map<string, string> tansform_map;
    while (inf >> word && getline(inf, value)) {
        if (value.size() > 1) {
            tansform_map[word] = value.substr(1);
        } else {
            throw runtime_error("no rule for " + word);
        }
    }
    return tansform_map;
}

const string &transformWord(const string &str, const map<string, string> &m) {
    auto iter = m.find(str);
    if (iter != m.end())
        return iter->second;
    else
        return str;
}

void transform_file(ifstream &rule_file, ifstream &input_file) {
    map<string, string> t_map = trans_map(rule_file);
    string text;
    while (getline(input_file, text)) {
        string word;
        bool first_word = true;
        istringstream in_s(text);
        while (in_s >> word) {
            if (first_word) {
                first_word = false;
            } else {
                cout << " ";
            }
            cout << transformWord(word, t_map);
        }
        cout << endl;
    }
}

int main(int agrc, char *agrv[]) {
    ifstream inf1(agrv[1]), inf2(agrv[2]);
    try {
        /* code */
        if (!inf1 && !inf2) {
            throw invalid_argument("open file error");
        }
        transform_file(inf1, inf2);
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << '\n';
    }
    catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
