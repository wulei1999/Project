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
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

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
using std::iterator;
using std::map;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::reverse_iterator;
using std::set;
int main() {
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        for(auto &ch : word){
            if(ispunct(ch)){
                auto index = word.find(ch);
                if(index != string::npos)
                    word = word.erase(index);
            }
            else{
                tolower(ch);
            }
        }
        ++word_count[word];
    }
    for(auto elem : word_count){
        cout << "word: " << elem.first << "occurs: " << elem.second << endl;
    }
    return 0;
}
