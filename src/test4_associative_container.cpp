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
    multimap<string, vector<pair<string, string>>> family_name;
    string surname;
    string name, birthday;
    vector<pair<string, string>> v_pair;
    while (cin >> surname) {
        while (cin >> name >> birthday) {
            v_pair.push_back({name, birthday});
            if (getchar() == '\n')
                break;
        }
        family_name.insert({surname, v_pair});
    }
    for (auto &elem : family_name) {
        cout << "family surname: " << elem.first << endl;
        for (auto &x : elem.second) {
            cout << "member name: " << x.first << " member birthday: " << x.second;
        }
        cout << endl;
    }
    return 0;
}
