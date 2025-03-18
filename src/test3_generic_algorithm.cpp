#include <algorithm>
#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <functional>

#include "sale_data.h"

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

bool isShorter(const string &str1, const string &str2) {
    return str1.size() < str2.size();
}

bool sizeOver6(const string &str, size_t sz) {
    return (str.size() <= sz) ? true : false;
}

int main() {
    /*
    vector<string> v_str;
    string str;
    while (cin >> str) {
        auto it = back_inserter(v_str);
        *it = str;
    }
    sort(v_str.begin(), v_str.end());
    auto unique_end = unique(v_str.begin(), v_str.end());
    v_str.erase(unique_end, v_str.end());
    stable_sort(v_str.begin(), v_str.end(), isShorter);
    for (string elem : v_str) {
        cout << elem << endl;
    }
    */
    /*
     vector<SaleData> v_saledata;
     SaleData sd;
     while(cin >> sd){
         v_saledata.push_back(sd);
     }
     sort(v_saledata.begin(), v_saledata.end(),
          [](SaleData &sd1, SaleData &sd2) { return stoi(sd1.isbn()) > stoi(sd2.isbn()); });
     for (auto elem : v_saledata) {
         cout << elem << endl;
     }
     */

    vector<string> v_str;
    string str;
    while (cin >> str) {
        auto it = back_inserter(v_str);
        *it = str;
    }
    sort(v_str.begin(), v_str.end());
    auto unique_end = unique(v_str.begin(), v_str.end());
    v_str.erase(unique_end, v_str.end());
    stable_sort(v_str.begin(), v_str.end(), isShorter);
    // auto iter = stable_partition(v_str.begin(), v_str.end(), sizeOver6);
    // v_str.erase(iter, v_str.end());
    // size_t sz = 6;
    // auto satisfy_iter = find_if(v_str.begin(), v_str.end(), [sz](const string &str) { return
    // str.size() > sz; }); 
    //auto satisfy_count = v_str.end() - satisfy_iter; 
    //auto satisfy_count = v_str.end() - iter;
    int sz = 6;
    auto f = bind(sizeOver6, _1, sz);
    /*
     auto satisfy_count =
        count_if(v_str.begin(), v_str.end(), [](const string &str) { return str.size() > 6; });
    cout << "word size > 6 num: " << satisfy_count << endl;
    */
    auto satisfy_count =
        count_if(v_str.begin(), v_str.end(), bind(sizeOver6, _1, sz));
    cout << "word size <= 6 num: " << satisfy_count << endl;
    // for_each(iter, v_str.end(), [](const string &str) { cout << str <<" "; });
    // cout << endl;
    /*
    int i = 10;
    bool flag = true;
    auto f = [i]() mutable -> bool {
        if (--i) {
            return true;
        } else
            return false;
    };
    while (f()) {
    }
    cout << i << endl;
    */
    return 0;
}
