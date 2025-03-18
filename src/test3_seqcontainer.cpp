#include <cctype>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "func.h"

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
    deque<string> d_str;
    list<string> list_str;
    deque<int> d_inteven, d_intodd;
    list<int> list_int;
    string word;
    int number;
    vector<int> v_int{1, 2, 3};
    vector<int>::iterator vint_it1 = v_int.begin() + 1;
    vector<int>::iterator vint_it2 = v_int.begin() + 1;
    vector<int>::iterator vint_it3 = v_int.end();
    vector<int>::iterator vint_it4 = v_int.end();
    vector<int>::iterator it1, it2;
    it1 = v_int.erase(vint_it1, vint_it2);
    (it1 == vint_it1) ? (cout << "it1: " << *it1) : (cout << "vint_it1: " << *vint_it1) << endl;
    cout << endl;
    it2 = v_int.erase(vint_it3, vint_it3);
    (it2 == vint_it3) ? (cout << "it2: " << *it2) : (cout << "vint_it3: " << *vint_it3) << endl;
    cout << endl;
    cout << v_int.size() << endl;
    // cout << *(v_int.begin()) << endl;
    return 0;
}