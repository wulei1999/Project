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
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v_int;
    list<int> list_int;
    v_int.assign(ia, ia + 10);
    list_int.assign(ia, ia + 10);

    for (auto iter = list_int.begin(); iter != list_int.end();) {
        if (*iter & 1) {
            iter = list_int.erase(iter);
        } else {
            ++iter;
        }
    }

    auto iter_v_beg = v_int.begin();
    for (; iter_v_beg != v_int.end();) {
        if (*iter_v_beg % 2) {
            ++iter_v_beg;
        } else {
            iter_v_beg = v_int.erase(iter_v_beg);
        }
    }

    for (auto iter = list_int.begin(); iter != list_int.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    for (auto iter = v_int.begin(); iter != v_int.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}