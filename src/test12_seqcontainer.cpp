#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::forward_list;
using std::ifstream;
using std::invalid_argument;
using std::list;
using std::stack;
using std::string;
using std::vector;

enum obj_type { LP, RP, ADD, SUB, VAL };
struct obj {
    /* data */
    obj(obj_type type, double val = 0) {
        t = type;
        v = val;
    }
    obj_type t;
    double v;
};

inline void skipws(string &exp, size_t &p) {
    p = exp.find_first_not_of(" ", p);
}

inline void new_val(stack<obj> &so, double v) {
    // 空栈或者左括号
    if (so.empty() || so.top().t == LP) {
        so.push(obj(VAL, v));
    } else if (so.top().t == ADD || so.top().t == SUB) {
        // 压入之前也是运算符
        obj_type type = so.top().t;
        so.pop();
        if (type == ADD) {
            v += so.top().v;
        } else {
            v = so.top().v - v;
        }
        so.pop();
        so.push(obj(VAL, v));
    } else {
        throw invalid_argument("缺少运算符");
    }
}

int main() {
    stack<obj> so;
    string exp;
    string::size_type p = 0, q;
    double v;
    cout << "请输入表达式" << endl;
    getline(cin, exp);

    while (p < exp.size()) {
        skipws(exp, p);
        if (exp[p] == '(') {
            so.push(obj(LP));
            p++;
        } else if (exp[p] == '+' || exp[p] == '-') {
            if (so.empty() || so.top().t != VAL) {
                throw invalid_argument("缺少运算数");
            }

            if (exp[p] == '+') {
                so.push(obj(ADD));
            } else {
                so.push(obj(SUB));
            }
            p++;
        } else if (exp[p] == ')') {
            p++;
            if (so.empty()) {
                throw invalid_argument("未匹配的右括号");
            }

            if (so.top().t == LP) {
                throw invalid_argument("一对空括号");
            }
            if (so.top().t == VAL) {
                v = so.top().v;
                so.pop();
                if (so.empty() || so.top().t != LP) {
                    throw invalid_argument("未匹配的右括号");
                }
                so.pop();
                new_val(so, v);
            } else {
                throw invalid_argument("缺少运算数");
            }
        } else {
            v = stod(exp.substr(p), &q);
            p += q;
            new_val(so, v);
        }
    }
    if(so.size() != 1 || so.top().t != VAL){
        throw invalid_argument("非法表达式");
    }
    cout << so.top().v << endl;
    return 0;
}
