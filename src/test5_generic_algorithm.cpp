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
using std::bind;
using std::cerr;
using std::ifstream;
using std::inserter;
using std::istream_iterator;
using std::iterator;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::reverse_iterator;
int main() {
    vector<int> v_int;
    int a;
    while (cin >> a) {
        auto iter = back_inserter(v_int);
        *iter = a;
    }
    reverse_iterator riter_beg = v_int.rbegin();
    reverse_iterator riter_end = v_int.rend();
    while (riter_beg != riter_end) {
        cout << *riter_beg++ << " ";
    }
    cout << endl;
    vector<int>::iterator v_beg = v_int.begin();
    vector<int>::iterator v_end = v_int.end();
    while (v_beg != v_end) {
        cout << *(--v_end) << " ";
    }
    cout << endl;
    return 0;
}