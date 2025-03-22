#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::initializer_list;
using std::istream;
using std::make_shared;
using std::out_of_range;
using std::runtime_error;
using std::shared_ptr;
using std::string;
using std::vector;
using std::weak_ptr;

class StrBlobPtr;
class StrBlob {
public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    StrBlob(vector<string> *p);
    ~StrBlob();
    size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    void push_back(const string &t) {
        data->push_back(t);
    }
    void push_back(string &&t) {
        data->push_back(std::move(t));
    }
    void pop_back();
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;
    /*
    只有在StrBlobPtr被定义之后才能定义这两个函数，不然会报错
    StrBlobPtr begin() {
        return StrBlobPtr(*this);
    }
    StrBlobPtr end(){
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
    */
    StrBlobPtr begin();
    StrBlobPtr end();
    StrBlobPtr begin() const;
    StrBlobPtr end() const;

private:
    /* data */
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
inline StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
inline StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
inline StrBlob::StrBlob(vector<string> *p) : data(p) {}
inline StrBlob::~StrBlob() {}
inline void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

inline string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
inline const string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}
inline string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
inline const string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr {
public:
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
    StrBlobPtr() : curr(0) {}
    // StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    ~StrBlobPtr();
    string &deref() const;
    string &deref(int off) const;
    StrBlobPtr &incr();

private:
    /* data */
    size_t curr;
    weak_ptr<vector<string>> wptr;
    shared_ptr<vector<string>> check(size_t, const string &) const;
};

inline StrBlobPtr::~StrBlobPtr() {}
inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw out_of_range(msg);
    }
    return ret;
}
inline string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline string &StrBlobPtr::deref(int off) const {
    auto p = check(curr + off, "dereference past end");
    return (*p)[curr + off];
}

inline StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r) {
        return (!r || lhs.curr == rhs.curr);
    } else {
        return false;
    }
}
inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !eq(lhs, rhs);
}
inline StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
inline StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
inline StrBlobPtr StrBlob::begin() const {
    return StrBlobPtr(*this);
}
inline StrBlobPtr StrBlob::end() const {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
#endif /* MY_STRBLOB_H */