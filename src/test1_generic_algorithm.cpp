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
using std::forward_list;
using std::ifstream;
using std::invalid_argument;
using std::list;
using std::stack;
using std::string;
using std::vector;

int main() {
    vector<int> v_int;
    list<string> list_str;
    string str;
    int a;
    while (cin >> a){
        v_int.push_back(a);
    }
    cout << accumulate(v_int.cbegin(), v_int.cend(), 0) << endl;
    return 0;
}
