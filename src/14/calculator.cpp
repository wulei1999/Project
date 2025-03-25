#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::divides;
using std::end;
using std::endl;
using std::find_if;
using std::for_each;
using std::function;
using std::ifstream;
using std::istream;
using std::map;
using std::ostream;
using std::sort;
using std::stable_sort;
using std::string;
using std::stringstream;
using std::unique;
using std::vector;
class Add {
private:
    /* data */

public:
    int operator()(const int lhs, const int& rhs) {
        return lhs + rhs;
    }
};

class Minus {
private:
    /* data */
public:
    int operator()(int lhs, int rhs) {
        return lhs - rhs;
    }
};

unsigned int mod(int value1, int value2) {
    return value1 % value2;
}

int main() {
    cout << "简易计算器，支持+，-，*，/，% " << endl;
    int a = 0, b = a;
    map<string, function<int(int, int)>> calcu;//function，可以存储所有的可调用对象，只要是返回值类型和形参类型对应即可
    Add add;
    calcu.insert({"+", add});//一个默认合成构造函数生成的类对象，只要定义了重载函数调用符，就可以在需要使用函数的地方使用函数对象，与下面的形式等价
    //calcu.insert({"+", Add()});//相当于生成了一个未命名的Add对象，并且在给map的值function<int(int, int)>传入实参时捕获实参并传入Add未命名对象的函数调用运算符的形参中
    calcu.insert({"-", Minus()});
    calcu.insert({"*", [](int a, int b) { return a + b; }});
    calcu.insert({"/", divides<int>()});
    calcu.insert({"%", mod});
    string formula;
    cout << "请输入你的算数公式" << endl;
    while (getline(cin, formula)) {
        int lhs = 0, rhs = lhs, sum = rhs;
        size_t index = 0;
        string word;
        string opt;
        stringstream line(formula);
        /*
        // 错误写法：由于运算符优先级，实际执行的是 index = (formula.find("+") != string::npos)
        // 这会导致index被赋值为bool结果(true=1/false=0)，而不是找到的位置
        if ((index = formula.find("+") != string::npos)) {
        }
        // 正确写法1：分开写更清晰
        index = formula.find("+");
        if (index != string::npos) {
            // 处理找到的+号
        }
        */
        // 正确写法2：使用括号明确优先级
        try {
            if ((index = formula.find_first_of("+-*/%")) != string::npos) {
                // 处理找到的运算符号
                opt = formula[index];
                lhs = stoi(formula);
                rhs = stoi(formula.substr(index + 1));
                sum = calcu[opt](lhs, rhs);
                cout << "计算公式 " << formula << "答案是 " << sum << endl;
            } else {
                throw std::invalid_argument("输入的运算公式不正确，请重新输入");
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
        cout << "请输入你的算数公式" << endl;
    }
}
