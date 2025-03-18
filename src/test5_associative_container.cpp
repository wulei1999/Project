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
using std::iterator;
using std::map;
using std::multimap;
using std::multiset;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::pair;
using std::reverse_iterator;
using std::set;
int main() {
    multimap<string, string> multi_author{{"wulei", "aaa"}, {"wulei", "eee"}, {"wulei", "aaa"},
                                          {"wulei", "ddd"}, {"wuli", "aaa"},  {"wufan", "ddd"},
                                          {"wutian", "xxx"}};
    string name, book_name;
    decltype(multi_author)::key_type search_book;
    cin >> search_book;
    auto iter = multi_author.find(search_book);
    if (iter != multi_author.end()) {
        multi_author.erase(search_book);
    }
    for (auto &x : multi_author) {
        cout << "author: " << x.first << " book: " << x.second;
    }
    cout << endl;
    return 0;
}
