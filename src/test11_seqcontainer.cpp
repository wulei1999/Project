#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include "func.h"

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::forward_list;
using std::ifstream;
using std::list;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
    vector<string> v_str;
    string str_int;
    double sum = 0;
    while (cin >> str_int) {
        v_str.push_back(str_int);
    }
    for(auto &elem : v_str){
        sum += stod(elem);
    }
    cout << sum << endl;
    return 0;
}