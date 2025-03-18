#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include "func.h"

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::forward_list;
using std::ifstream;
using std::list;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
    ifstream in;
    in.open("./input_word.txt");
    if (!in) {
        cout << "open file error" << endl;
        return -1;
    }
    findLongestSubstr(in);
    return 0;
}