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
    int grade = 0;
    string lettergrade;
    const vector<string> scores = {"E", "D", "C", "B", "A", "A++"};
    /*
    while (cin >> grade) {
        if (grade >= 60) {
            lettergrade = scores[(grade - 50) / 10];
 else {
            lettergrade = scores[0];
        }
        if (grade >= 60 && grade < 100) {
            if (grade % 10 > 7) {
                lettergrade += '+';
            } else if (grade % 10 < 3) {
                lettergrade += '-';
            }
        }
        cout << lettergrade << endl;
    }
    */
    while (cin >> grade) {
        (grade >= 60) ? lettergrade = scores[(grade - 50) / 10] : lettergrade = scores[0];

        if (grade >= 60 && grade < 100) {
            (grade % 10 > 7)   ? lettergrade += '+'
            : (grade % 10 < 3) ? lettergrade += '-'
                               : lettergrade;
        }
        cout << lettergrade << endl;
    }
    return 0;
}