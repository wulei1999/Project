#include <cctype>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;
int main() {
    int array1[10] = {0};
    int array2[10] = {0};
    for (size_t i = 0; i < 10; i++) {
        array1[i] = i;
    }
    for (auto j : array1) {
        array2[j] = j;
        cout << j << ' ';
    }
    cout << endl;
    int *p1 = array1;
    auto arr_b = begin(array1);
    auto arr_e = end(array1);
    /*
    for (; arr_b != arr_e; ++arr_b) {
        *p++ = 0;
    }
    for (auto j : array1) {
        cout << j << ' ';
    }
    cout << endl;
    */
    for (size_t i = 10 / 2, j = 0; i < 10; i++) {
        array2[i] = j;
        j++;
    }
    int *p2 = array2;
    for (ptrdiff_t i = 0; i < (arr_e - arr_b); ++i) {
        if (*p1 != *p2) {
            cout << "array1's " << i << "element != array2's element" << endl;
            break;
        }
        p1++;
        p2++;
    }
    return 0;
}