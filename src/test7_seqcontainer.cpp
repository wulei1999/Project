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
    char ch[] = {'1', '2', '3', '4'};
    char ch1[] = "1234";
    if (ch[4] == '\0')
        cout << "添加空字符" << endl;
    vector<char> v_char;
    v_char.assign(ch, ch+3);
    string str0;
    str0.assign(ch, 5);
    str0.assign(v_char.data());
    cout << str0 << endl;
    cout << "v_char.size():" << v_char.size() << endl;
    string str(v_char.data());
    string str2(ch);
    string str3(ch, 2);
    cout << str << endl;
    cout << str2 << endl;
    return 0;
}