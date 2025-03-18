#include <cctype>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <forward_list>

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
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v_int;
    list<int> list_int;
    forward_list<int> flist_int;
    v_int.assign(ia, ia + 10);
    list_int.assign(ia, ia + 10);
    flist_int.assign(ia, ia + 10);
    auto prev = flist_int.before_begin();
    for (auto iter = flist_int.begin(); iter != flist_int.end();) {
        if (*iter & 1) {
            iter = flist_int.erase_after(prev);
        } else {
            prev = iter;
            ++iter;
        }
    }

    for (auto iter = flist_int.begin(); iter != flist_int.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}