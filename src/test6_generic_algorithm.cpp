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
    vector<int> v_int;
    list<int> l_int(10, 0);
    int a;
    while (cin >> a) {
        auto iter = back_inserter(v_int);
        *iter = a;
    }

    for (auto elem : v_int) {
        cout << elem << " ";
    }
    cout << endl;
    vector<int>::reverse_iterator riter_beg = v_int.rbegin();
     vector<int>::reverse_iterator riter_end = v_int.rend();
    //  int circle_count = 0;
    //  auto iter = find(riter_beg, riter_end, 0);
    //vector<int>::iterator v_beg = v_int.begin();
    //vector<int>::iterator v_end = v_int.end();
    //vector<int>::reverse_iterator re(v_beg + 2);
    //vector<int>::reverse_iterator rb(v_end - 3);
    list<int>::iterator l_beg = l_int.begin();
    copy(riter_beg+3, riter_end -2, l_beg);
    auto iter = l_int.begin();
    while (iter != l_int.end()) {
        cout << *iter++ << " ";
    }
    cout << endl;
    //cout << l_int.end() - l_int.begin()<< endl;
    cout << v_int.end() - v_int.begin()<< endl;
    /*
    int a1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a2[10] = {0};
    copy(begin(a1), end(a1), a2);
    for (auto elem : a2) {
        cout << elem << " ";
    }
    cout << endl;
    */
    return 0;
}