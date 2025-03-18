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
    char c;
    string str1;
    const char a_vowel = 'a', e_vowel = 'e', i_vowel = 'i', o_vowel = 'o', u_vowel = 'u',
               c_space = ' ', c_table = '\t', c_linefeed = '\n';
    int count_vowel = 0, count_space = 0, count_table = 0, count_linefeed = 0;
    // getline(cin, str1);
    // cout << str1 << endl;
    // auto it = str1.cbegin();

    while (cin.get(c)) {
        tolower(c);
        switch (c) {
            case a_vowel:
            case e_vowel:
            case i_vowel:
            case o_vowel:
            case u_vowel:
                /* code */
                ++count_vowel;
                break;
            case c_space:
                ++count_space;
                break;
            case c_table:
                ++count_table;
                break;
            case c_linefeed:
                ++count_linefeed;
                break;
            default:
                break;
        }
        //++it;
    }
    cout << "count_vowel: " << count_vowel << endl;
    cout << "count_space: " << count_space << endl;
    cout << "count_table: " << count_table << endl;
    cout << "count_linefeed: " << count_linefeed << endl;
    /*
    while (cin >> c) {
        switch (c) {
            case 'a':
                ++count;
            case 'b':
                ++count;
            case 'c':
                ++count;
            case 'd':
                ++count;
        }
        cout << count << endl;
    }
    */
    /*
     bool flag = false;
     switch (flag) {
         case true:
             // string str1;
             // int a = 0;
             int b;
             break;
         case false:
             int a = 0;
             string str2 = "11";
             break;
     }
     */
    return 0;
}