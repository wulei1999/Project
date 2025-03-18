#ifndef STR_BLOB_PTR_H
#define STR_BLOB_PTR_H

#include "str_blob.h"

using std::runtime_error;
using std::weak_ptr;

class StrBlobPtr {
public:
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
    StrBlobPtr() : curr(0) {}
    //StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    ~StrBlobPtr();
    string &deref() const;
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
inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return !eq(lhs, rhs);
}
inline StrBlobPtr StrBlob::begin() const{
    return StrBlobPtr(*this);
}
inline StrBlobPtr StrBlob::end() const{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
#endif /* __STR_BLOB_PTR_H__ */