#include "string.h"

#include <cstring>
using std::strlen;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <utility>
using std::swap;

#include <memory>
using std::allocator;
using std::uninitialized_copy;

#include <vector>
using std::vector;

allocator<char> String::alloc;

String &String::operator=(const String &rhs) {
    // TODO: 在此处插入 return 语句
    cout << "拷贝赋值运算" << endl;
    char *newp = alloc.allocate(rhs.sz);
    uninitialized_copy(rhs.begin(), rhs.end(), newp);

    if (p)
        alloc.deallocate(p, sz);
    p = newp;
    sz = rhs.sz;
    return *this;
}

String &String::operator=(String &&rhs) noexcept {
    // TODO: 在此处插入 return 语句
    if (this != &rhs) {  // 防止自赋值
        cout << "移动赋值运算" << endl;
        if (p)
            alloc.deallocate(p, sz);
        p = rhs.p;
        sz = rhs.sz;
        rhs.p = nullptr;
        rhs.sz = 0;
    }
    return *this;
}

String &String::operator=(const char *cp) {
    // TODO: 在此处插入 return 语句
    if (p)
        alloc.deallocate(p, sz);
    sz = strlen(cp);
    p = alloc.allocate(sz);
    uninitialized_copy(cp, cp + sz, p);
    return *this;
}

String &String::operator=(char c) {
    // TODO: 在此处插入 return 语句
    if (p)
        alloc.deallocate(p, sz);
    sz = 1;
    p = alloc.allocate(sz);
    *p = c;
    return *this;
}

String add(const String &lhs, const String &rhs) {
    String ret;
    ret.sz = lhs.sz + rhs.sz;
    ret.p = String::alloc.allocate(ret.sz);
    uninitialized_copy(lhs.begin(), lhs.end(), ret.p);
    uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.sz);
    return ret;
}

std::ostream &print(std::ostream &os, const String &str) {
    // TODO: 在此处插入 return 语句
    const char *p = str.begin();
    while (p != str.end()) {
        os << *p++;
    }
    return os;
}
String make_pluarl(size_t ctr, const String &word, const String &ending) {
    return (ctr != 1) ? add(word, ending) : word;
}
std::ostream &operator<<(std::ostream &os, const String &str) {
    // TODO: 在此处插入 return 语句
    return print(os, str);
}

String operator+(const String &lhs, const String &rhs) {
    return add(lhs, rhs);
}

int main() {
    const char *ch = "wulei";

    String s1(ch);
    String s2("wuli");
    String s3("good");
    String s4(s1);
    String s5 = s2;
    String s6;
    s6 = s3;
    cout << endl;
    vector<String> vS(20);
    cout << endl;
    for (auto i = 0; i < 6; ++i) {
        vS.push_back(s3);
        // vS.push_back(std::move(s3));
        // vS.push_back(String("good"));
        // vS.push_back("bad");
    }
    // cout << s1 + "," + s3 << endl;
    return 0;
}