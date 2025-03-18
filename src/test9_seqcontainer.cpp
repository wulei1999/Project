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
    string s_name, s_namef, s_names;
    while(cin >> s_name >> s_namef >> s_names){
        cout << "s_name: " << s_name << " s_namef: " << s_namef << " s_names: " << s_names << endl;
        addNameFrontAndSuffix(s_name, s_namef, s_names);
        cout << "s_name: " << s_name << endl;
    }
    return 0;
}