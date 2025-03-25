#ifndef STRING_H
#define STRING_H
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
#include <memory>

class String {
    friend String operator+(const String &, const String &);
    friend String add(const String &, const String &);
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::ostream &print(std::ostream &, const String &);
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator>=(const String &, const String &);
private:
    /* data */
    size_t sz;
    char *p;
    static std::allocator<char> alloc;

public:
    String() : sz(0), p(nullptr) {}
    String(const char *char_arr) : sz(std::strlen(char_arr)), p(alloc.allocate(sz)) {
        std::uninitialized_copy(char_arr, char_arr + sz, p);
    }
    String(const String &str) : sz(str.sz), p(alloc.allocate(str.sz)) {
        cout << "拷贝构造" << endl;
        std::uninitialized_copy(str.p, str.p + str.sz, p);
    }
    String(String &&str) noexcept : sz(str.sz), p(alloc.allocate(str.sz)) {
        cout << "移动构造" << endl;
        std::uninitialized_copy(str.p, str.p + str.sz, p);
        str.p = nullptr;
        str.sz = 0;
    }
    String(size_t n, char c) : sz(n), p(alloc.allocate(n)) {
        std::uninitialized_fill_n(p, sz, c);
    }
    String &operator=(const String &);
    String &operator=(String &&) noexcept;
    ~String() {
        if (p)
            alloc.deallocate(p, sz);
    }

public:
    String &operator=(const char *);
    String &operator=(char);
    char &operator[](size_t n) {
        return p[n];
    }
    const char &operator[](size_t n) const {
        return (char)p[n];
    }
    const char *begin() {
        return p;
    }
    const char *begin() const {
        return p;
    }
    const char *end() {
        return p + sz;
    }
    const char *end() const {
        return p + sz;
    }

    size_t size() const {
        return sz;
    }
    void swap(String &s) {
        char *temp = p;
        p = s.p;
        s.p = temp;
        size_t temp_sz = sz;
        sz = s.sz;
        s.sz = temp_sz;
    }
};
String make_pluarl(size_t ctr, const String &, const String &);
inline void swap(String &s1, String &s2) {
    s1.swap(s2);
}

#endif /* STRING_H */