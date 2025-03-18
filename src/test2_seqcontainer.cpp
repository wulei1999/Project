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
    vector<int> v_int;
    //cout << v_int.at(0) << endl;
    //cout << v_int[0] << endl;
    //cout << v_int.front() << endl;
    cout << *(v_int.begin()) << endl;
    return 0;
}