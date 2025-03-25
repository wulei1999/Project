#ifndef STRVEC_H
#define STRVEC_H
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <new>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

using std::allocator;
using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::for_each;
using std::initializer_list;
using std::istream;
using std::make_shared;
using std::out_of_range;
using std::pair;
using std::set;
using std::shared_ptr;
using std::string;
using std::uninitialized_copy;
using std::vector;
class StrVec {
    friend bool operator==(const StrVec &, const StrVec &);
    friend bool operator!=(const StrVec &, const StrVec &);
    friend bool operator<(const StrVec &, const StrVec &);
    friend bool operator<=(const StrVec &, const StrVec &);
    friend bool operator>(const StrVec &, const StrVec &);
    friend bool operator>=(const StrVec &, const StrVec &);

private:
    /* data */
    static allocator<string> alloc;  // 静态成员需要类外定义

    string *element;
    string *first_free;
    string *cap;
    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }
    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void free();
    void reallocate();
    void reallocate(size_t size);

public:
    // using size_type = vector<string>::size_type;
    StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec(const initializer_list<string> &);
    StrVec(StrVec &&s) noexcept : element(s.element), first_free(s.first_free), cap(s.cap) {
        s.element = s.first_free = s.cap = nullptr;  // 移动构造函数令右值析构时安全
    }
    ~StrVec();
    StrVec &operator=(const StrVec &);
    StrVec &operator=(StrVec &&) noexcept;
    StrVec &operator=(const initializer_list<string> &li);
    string &operator[](size_t n) {
        return *(element + n);
    }
    const string &operator[](size_t n) const {
        return *(element + n);
    }
    void push_back(const string &);
    size_t size() const {
        return first_free - element;
    }
    size_t capacity() {
        return cap - first_free;
    }
    size_t whole_cap() {
        return cap - element;
    }
    void reserve(size_t sz);
    void resize(size_t sz);
    void resize(size_t sz, const string &s);
    string *begin() const {
        return element;
    }
    string *end() const {
        return first_free;
    }
};

#endif /* STRVEC_H */
