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
    while (cin >> number) {
        list_int.push_back(number);
    }
    for (auto list_begin = list_int.cbegin(); list_begin != list_int.cend(); ++list_begin) {
        if(*list_begin & 1){ //查看最低位
        //if (*list_begin % 2) {
            d_inteven.push_back(*list_begin);
        } else {
            d_intodd.push_back(*list_begin);
        }
    }
    for (auto ele : d_inteven) {
        cout << ele << " ";
    }
    cout << endl;
    for (auto ele : d_intodd) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}