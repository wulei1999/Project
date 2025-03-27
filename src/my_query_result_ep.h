#ifndef MY_QUERY_RESULT_EP_H
#define MY_QUERY_RESULT_EP_H
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include "my_strblob.h"

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istringstream;
using std::make_pair;
using std::make_shared;
using std::map;
using std::out_of_range;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;
using std::ostream;
class QueryResultEp {
    friend ostream &print(ostream &, const QueryResultEp &);
    friend ostream &print(ostream &, const QueryResultEp &, int, int);

public:
    typedef vector<string>::size_type line_no;
    typedef set<line_no>::const_iterator line_it;
    QueryResultEp(const string &str, shared_ptr<set<line_no>> sp,
                  StrBlob f)
        : search_word(str), lines(sp), file(f) {}
    set<line_no>::size_type size() const {
        return lines->size();
    }
    line_it begin() const {
        return lines->cbegin();
    }
    line_it end() const {
        return lines->cend();
    }
    StrBlob get_file() {
        return file;
    }

private:
    /* data */
    string search_word;
    shared_ptr<set<line_no>> lines;
    StrBlob file;
};
ostream &print(ostream &os, const QueryResultEp &qr);

#endif /* MY_QUERY_RESULT_EP_H */