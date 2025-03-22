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
private:
    /* data */
    allocator<string> alloc;  // 静态成员需要类外定义

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
    //using size_type = vector<string>::size_type;
    StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec(const initializer_list<string>&);
    ~StrVec();
    StrVec &operator=(const StrVec &);
    void push_back(const string &);
    size_t size() {
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
