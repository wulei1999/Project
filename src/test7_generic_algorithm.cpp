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
#include <numeric>
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
using std::ifstream;
using std::inserter;
using std::istream_iterator;
using std::iterator;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::reverse_iterator;


int main() {
    list<string> list_str;
    istream_iterator<string> in_iter(cin), eof;
    ostream_iterator<string> out_iter(cout, " ");
    while (in_iter != eof)
    {
        auto iter = back_inserter(list_str);
        *iter = *in_iter++;
    }
    list_str.sort();
    list_str.unique();
    for(auto elem : list_str){
        *out_iter++ = elem;
    }
    cout << endl;
    return 0;
}