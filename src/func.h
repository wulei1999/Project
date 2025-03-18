#ifndef func_H
#define func_H
#include <algorithm>
#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

using std::accumulate;
using std::back_inserter;
using std::cin;
using std::count;
using std::cout;
using std::deque;
using std::endl;
using std::fill_n;
using std::find_if;
using std::for_each;
using std::forward_list;
using std::ifstream;
using std::initializer_list;
using std::invalid_argument;
using std::list;
using std::partition;
using std::sort;
using std::stable_sort;
using std::stack;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;
using std::bind;
using std::cerr;
using std::ifstream;
using std::inserter;
using std::istream_iterator;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;

int compareInt(int a, int *p);
void changePointer1(int *p1, int *p2);
void changePointer2(int *p1, int *p2);
void changePointer3(int *&p1, int *&p2);
void changeArrayElement(int (&arr)[], const unsigned int index);
int calculateInilsit(initializer_list<int> ini_int);
int printVectorVal(const vector<int> v_int, vector<int>::size_type index);

string(&returnString(string &str));
vector<string>(&returnVectorString(vector<string> &v_str));

// 返回string数组(大小为10)引用的函数常规声明
string (&returnArrayString(vector<string> v_str))[10];

// 使用类型别名声明，返回string数组(大小为10)引用的函数声明
typedef string arr_str1[10];
using arr_str2 = string[10];
arr_str1 &returnArrayString1(vector<string> v_str);
arr_str2 &returnArrayString2(vector<string> v_str);

// 使用尾置返回类型,返回string数组(大小为10)引用的函数声明
auto returnArrayString3(vector<string> v_str) -> string (&)[10];

// 使用decltype,返回string数组(大小为10)引用的函数声明
extern string array_str3[10];  // 直接放入decltype函数中编译不过
decltype(array_str3) &returnArrayString4(vector<string> v_str);

// 默认形参
inline string makePlural(size_t ctr, const string &word, const string &ending = "s") {
    return ctr > 1 ? word + ending : word;
}

inline bool isShorter(const string &s1, const string s2) {
    return s1.size() < s2.size();
}

// 函数指针和数组指针用法类似，无论是在作为形参还是传递实参还是返回类型的使用
int funcIntAdd(int a, int b);
int funcIntSubtract(int a, int b);
int funcIntMultiply(int a, int b);
int funcIntDivision(int a, int b);
extern vector<int (*)(int, int)> v_func;
typedef int func1(int, int);
typedef int (*func1_p)(int, int);
using func2 = int(int, int);
using func2_p = int (*)(int, int);
typedef decltype(funcIntAdd) func3;
typedef decltype(funcIntAdd) *func3_p;

// 顺序容器
void flistSearchString(forward_list<string> &flist_string, const string &str1, string &str2);
void repalceSimpleform(string &s, string &old_val, string &new_val);
void addNameFrontAndSuffix(string &str_name, const string name_front, const string name_suffix);
void findNumberInstr(string &str);
void findLongestSubstr(ifstream &in);
#endif /*func_H*/