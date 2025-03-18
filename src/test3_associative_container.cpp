#include <algorithm>
#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <numeric>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

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
using std::make_pair;
using std::pair;
using std::sort;
using std::stack;
using std::string;
using std::unique;
using std::vector;

int main() {
    vector<pair<string, int>> v_pair;
    string str;
    int value;
    while (cin >> str >> value) {
        //v_pair.push_back(pair<string, int>(str, value));
        //v_pair.push_back(pair(str, value));
        //v_pair.push_back(make_pair(str, value));
        //pair<string, int> p = {str, value};
        //v_pair.push_back(pair<string, int>{str, value});
        //v_pair.push_back(pair{str, value});
        //v_pair.push_back({str, value});
        //v_pair.push_back(p)
    }
    for(auto &elem : v_pair){
        cout << "pair.first: " << elem.first << " pair.second: " << elem.second << endl;
    }
    return 0;
}
