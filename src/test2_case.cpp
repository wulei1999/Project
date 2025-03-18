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
    char c, c_temp = '\0';
    const string c_ff = "ff", c_fl = "fl", c_fi = "fi";
    int count_ff = 0, count_fl = 0, count_fi = 0, count_linefeed = 0;
    bool flag;
    while (cin.get(c)) {
        flag = true;
        if (c_temp == 'f') {
            switch (c) {
                case 'f':
                    ++count_ff;
                    flag = false;
                    break;
                case 'i':
                    ++count_fi;
                    break;
                case 'l':
                    ++count_fl;
                    break;
                default:
                    break;
            }
        }
        if (flag) {
            c_temp = c;
        } else {
            c_temp = '\0';
        }
    }
    cout << "count_ff: " << count_ff << endl;
    cout << "count_fl: " << count_fl << endl;
    cout << "count_fi: " << count_fi << endl;
    return 0;
}