#ifndef STRVEC_QUERY_RESULT_H
#define STRVEC_QUERY_RESULT_H

#include "strvec_text_query.h"
using std::ostream;
class QueryResultEp {
    friend ostream &print(ostream &, const QueryResultEp &);

public:
    QueryResultEp(/* args */) = default;
    QueryResultEp(const string &str, shared_ptr<set<TextQueryEp::line_number>> sp,
                  shared_ptr<StrVec> vp)
        : search_word(str), s_sptr(sp), v_sptr(vp) {}
    ~QueryResultEp();

private:
    /* data */
    string search_word;
    shared_ptr<set<TextQueryEp::line_number>> s_sptr;
    shared_ptr<StrVec> v_sptr;
};
QueryResultEp::~QueryResultEp() {}

QueryResultEp TextQueryEp::query(const string &word) const {
    static shared_ptr<set<line_number>> nodata(new set<line_number>);
    auto loc = m_word.find(word);
    if (loc == m_word.end()) {
        return QueryResultEp(word, nodata, v_file);
    } else {
        return QueryResultEp(word, loc->second, v_file);
    }
}

string make_plural(size_t ctr, const string &word, const string ending) {
    return (ctr > 1) ? word + ending : word;
}
ostream &print(ostream &os, const QueryResultEp &qr) {
    cout << qr.search_word << " occurs " << qr.s_sptr->size() << " "
         << make_plural(qr.s_sptr->size(), "time", "s") << endl;
         for(auto num : *(qr.s_sptr)){
             os << "\t(line " << num + 1 << ") " << *(qr.v_sptr->begin() + num) << endl;
         }
         return os;
}

#endif /* STRVEC_QUERY_RESULT_H */