#include <algorithm>
#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

#include "sale_data.h"

using std::accumulate;
using std::back_inserter;
using std::bind;
using std::cin;
using std::count;
using std::cout;
using std::deque;
using std::endl;
using std::fill_n;
using std::forward_list;
using std::ifstream;
using std::invalid_argument;
using std::list;
using std::partition;
using std::sort;
using std::stable_sort;
using std::stack;
using std::string;
using std::unique;
using std::vector;
using namespace ::placeholders;

bool isShorter(const string &str1, const string &str2) {
    return str1.size() < str2.size();
}

bool overSize(const string &str, size_t sz) {
    return (str.size() < sz) ? true : false;
}

int main() {
    // int sum = 0;
    // int a = 2;
    // auto sum = [a](const int b) -> int { return a + b; };
    // cout << sum(1) << endl;
    /*
    vector<string> v_str;
    string str;
    while (cin >> str) {
        auto it = back_inserter(v_str);
        *it = str;
    }
    auto iter = partition(v_str.begin(), v_str.end(), sizeOver5);
    for (auto iter_b = v_str.begin(); iter_b != iter; ++iter_b) {
        cout << *iter_b << endl;
    }
    */
    vector<int> v_int;
    int a;
    string str("eqeqeq");
    while (cin >> a) {
        v_int.push_back(a);
    }
    auto iter = find_if(v_int.begin(), v_int.end(), bind(overSize, str, _1));
    cout << *iter << endl;
    return 0;
}
