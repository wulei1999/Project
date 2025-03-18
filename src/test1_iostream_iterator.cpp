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

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    vector<string> v_str;
    if (!infile) {
        cout << "open file error!" << endl;
    }
    //istream_iterator<string> inflie_iter(cin), eof;
    //ostream_iterator<string> out_iter(cout, " ");
    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> v_int;
    vector<int> v_int_copy;
    while (in_iter != eof) {
        v_int.push_back(*in_iter++);
    }
    sort(v_int.begin(), v_int.end());
    unique_copy(v_int.begin(), v_int.end(), out_iter);
    //copy(v_int.begin(), v_int.end(), out_iter);
    //copy(v_int.begin(), v_int.end(), back_inserter(v_int_copy));
    /*
    for (auto elem : v_int_copy) {
        *out_iter++ = elem;
    }
    */
    cout << "\n";
    return 0;
}
