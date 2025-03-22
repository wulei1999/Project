#ifndef STR_BLOB_H
#define STR_BLOB_H
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <initializer_list>

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

class StrBlobPtr;
class StrBlob {
public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    StrBlob(const StrBlob &sb) : data(make_shared<vector<string>>(*sb.data)){}
    ~StrBlob();
    StrBlob &operator=(const StrBlob &rhs){
        data = make_shared<vector<string>>(*rhs.data);
        return *this;
    }
    size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    void push_back(const string &t) {
        data->push_back(t);
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
     //StrBlobPtr begin();
     //StrBlobPtr end();
    StrBlobPtr begin() const;
    StrBlobPtr end() const;

private:
    /* data */
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
inline StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
inline StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
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

#endif /* STR_BLOB_H */