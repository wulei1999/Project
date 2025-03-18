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
    vector<string> v_str;
    string str1, str_temp = "", maxnum_str;
    uint32_t count_maxnum_str = 0, count_temp = 0;
    while (cin >> str1) {
        v_str.push_back(str1);
    }
    auto it = v_str.cbegin();
    while (it != v_str.cend()) {
        if (str_temp == *it) {
            ++count_temp;
        } else {
            if (count_maxnum_str < count_temp) {
                count_maxnum_str = count_temp;
                maxnum_str = str_temp;
            }
            str_temp = *it;
            count_temp = 1;
        }
        // str_temp = *it;
        ++it;
    }
    if (count_maxnum_str > 1) {
        cout << "maxnum_str: " << maxnum_str << " count is" << count_maxnum_str << endl;
    } else {
        cout << "No words run consecutively" << endl;
    }
    return 0;
}