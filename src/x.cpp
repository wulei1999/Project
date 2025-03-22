#include <cstring>
#include <iostream>
#include <memory>
#include <new>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::istream;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::vector;

struct X {
    /* data */
    X() {
        cout << "X()" << endl;
    }
    X(const X &) {
        cout << "X(const X&)" << endl;
    }
    X &operator=(const X &){
    cout << "拷贝赋值运算符" << endl;
    return *this;
    }
    ~X(){cout << "析构函数" << endl;}
};

void f1(X x) {}

void f2(X &x) {}

int main() {
    cout << "局部变量" << endl;
    X x;
    cout << endl;

    cout << "非引用参数传递" << endl;
    f1(x);
    cout << endl;
    cout << "引用参数传递" << endl;
    f2(x);
    cout << endl;
    cout << "动态分配对象" << endl;
    X *px = new X;
    cout << endl;
    cout << "添加到容器" << endl;
    vector<X> vx;
    vx.push_back(x);
    cout << endl;
    cout << "释放动态分配对象" << endl;
    delete px;
    cout<< endl;
    cout << "拷贝初始化和赋值" << endl;
    X y = x;
    y = x;
    cout<< endl;
    cout<<"程序结束"<<endl;
    return 0;
}