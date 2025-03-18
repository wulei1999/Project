#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using std::accumulate;
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
using std::sort;
using std::stack;
using std::string;
using std::unique;
using std::vector;

int main() {
    vector<int> v_int;
    int a;
    while (cin >> a) {
        v_int.push_back(a);
    }
    sort(v_int.begin(), v_int.end());
    auto unique_end = unique(v_int.begin(), v_int.end());
    v_int.erase(unique_end, v_int.end());
    for (int elem : v_int) {
        cout << elem << endl;
    }
    return 0;
}
