#include <cctype>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

#include "func.h"

using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
    initializer_list<int> ini_int = {1, 2, 3, 4, 5};
    initializer_list<string> ini_string = {"3131", "313"};
    cout << calculateInilsit(ini_int) << endl;
    cout << calculateInilsit({2, 3, 5}) << endl;
    for (const auto &elem : ini_string) {
        cout << elem << endl;
    }
    return;
}