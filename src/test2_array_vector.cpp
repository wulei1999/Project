#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<int> v_int1(10, 0);
    vector<int> v_int2(10, 0);
    auto it1 = v_int1.begin();
    auto it2 = v_int2.begin();
    for (vector<int>::size_type x = 0; x < v_int1.size(); ++x) {
        *(it1 + x) = x;
        *(it2 + x) = x;
    }
    for (auto i : v_int1) {
        cout << i << ' ';
    }
    cout << endl;
    for (auto &x : v_int2) {
        x = 1;
    }
    for (vector<int>::size_type x = 0; x < v_int1.size(); ++x) {
        if (v_int1[x] != v_int2[x]) {
            cout << "v_int1 != v_int2 at" << x << endl;
            break;
        }
    }
    return 0;
}