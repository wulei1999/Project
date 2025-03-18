#include "data.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    string dates;
    try {
        /* code */
        while (getline(cin, dates)) {
            Data d(dates);
            cout << d;
        }
    } catch (invalid_argument e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}