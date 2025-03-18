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
using std::inserter;

int main() {
    vector<int> v_int;
    int a;
    while (cin >> a) {
        auto it = back_inserter(v_int);
        *it = a;
    }
    vector<int> v_int_copy;
    list<int> list_int_copy;
    sort(v_int.begin(), v_int.end());
    //unique_copy(v_int.begin(), v_int.end(), back_inserter(v_int_copy));
    //unique_copy(v_int.begin(), v_int.end(), front_inserter(list_int_copy));
    unique_copy(v_int.begin(), v_int.end(), inserter(v_int_copy, v_int_copy.begin()));
    for(auto elem : v_int_copy){
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
