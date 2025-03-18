#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "func.h"

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::forward_list;
using std::list;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
    string str, str_old, str_val;
    while(cin >> str >> str_old >> str_val){
        cout << "str: " << str << " str_old: " << str_old << " str_val: " << str_val << endl;
        repalceSimpleform(str, str_old, str_val);
        cout << "str: " << str << " str_old: " << str_old << " str_val: " << str_val << endl;
    }
    return 0;
}