#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "func.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
    /*
    if (argc >= 3) {
        cout << strcat(argv[1], argv[2]) << endl;
    } else {
        cout << "参数不够" << argc << endl;
    }
    */
    int temp = 0;
    cout << "argc: " << argc << endl;
    do {
        cout << "argv" << temp << " " << argv[temp] << endl;
    } while (++temp < argc);
}