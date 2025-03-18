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
    vector<unsigned> socres(11, 0);
    unsigned grade;
    auto it = socres.begin();
    while (cin >> grade) {
        /* code */
        if (grade <= 100) {
            ++(*(it + grade / 10));
        }
    }
    for (auto x : socres) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}