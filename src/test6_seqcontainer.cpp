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
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v_int;
    cout << "v_int.size():" << v_int.size() << endl;
    cout << "v_int.capacity():" << v_int.capacity() << endl;
    list<int> list_int;
    forward_list<int> flist_int;
    v_int.assign(ia, ia + 10);
    list_int.assign(ia, ia + 10);
    flist_int.assign(ia, ia + 10);
    cout << "v_int.size():" << v_int.size() << endl;
    cout << "v_int.capacity():" << v_int.capacity() << endl;
    v_int.push_back(2);
    cout << "v_int.capacity():" << v_int.capacity() << endl;
    v_int.reserve(40);
    cout << "v_int.capacity():" << v_int.capacity() << endl;
    v_int.shrink_to_fit();
    cout << "v_int.capacity():" << v_int.capacity() << endl;
    return 0;
}