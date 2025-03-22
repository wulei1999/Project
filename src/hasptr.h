#ifndef HASPTR_H
#define HASPTR_H
#include <string>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <algorithm>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::initializer_list;
using std::istream;
using std::make_shared;
using std::out_of_range;
using std::shared_ptr;
using std::string;
using std::vector;
class HasPtr {
    friend void swap(HasPtr &lhs, HasPtr &rhs);
private:
    /* data */
    string *ps;
    int i;
    size_t *use;

public:
    HasPtr(const string &str = string()) : ps(new string(str)), i(0){}
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i){}//类值拷贝构造函数
    //引用计数版本的HasPtr
    /*
    HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) {
        ++*use;
    }
    */
    HasPtr &operator=(const string &str);
    HasPtr &operator=(const HasPtr &);
    //HasPtr &operator=(HasPtr);//使用swap版本的拷贝赋值运算符函数，类值传递
    string &operator*();
    bool operator<(const HasPtr &rhs) const;
    ~HasPtr();
};

#endif /* HASPTR_H */