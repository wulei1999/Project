#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "sale_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main(int argc, char *argv[]) {
    SaleData s0("book", 1, 2);
    SaleData s1;                   // 调用默认构造函数
    SaleData s2("book");           // 调用单参数构造函数
    SaleData s3(cin);              // 调用istream构造函数
    return 0;
    return 0;
}