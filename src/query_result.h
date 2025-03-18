#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include "text_query.h"

using std::cerr;
using std::runtime_error;
using std::weak_ptr;
    static shared_ptr<map<string, set<unsigned long int>>> nodata = nullptr;
class QueryResult {
private:
    /* data */
    weak_ptr<vector<string>> wv_ptr;
    weak_ptr<map<string, set<unsigned long int>>> wm_ptr;
    const string search_word;
    shared_ptr<map<string, set<unsigned long int>>> check(const string &) const;

public:
    QueryResult(/* args */) = default;
    QueryResult(const TextQuery &tq)
        : wv_ptr(tq.vf_ptr), wm_ptr(tq.mf_ptr) {}
    ~QueryResult();
    void print(const string &);
};

QueryResult::~QueryResult() {}
shared_ptr<map<string, set<unsigned long int>>> QueryResult::check(const string &str) const {
    auto ret = wm_ptr.lock();
    if (!ret) {
        throw runtime_error("unbound QueryResult mf_ptr");
    }
    if (ret->find(str) == ret->end()) {
        //throw out_of_range("the word is not in text");
        cerr << "the word is not in text" << endl;
        return nodata;
    }
    return ret;
}
void QueryResult::print(const string &str) {
    auto mp = check(str);
    if(!mp)
        return;
    auto vp = wv_ptr.lock();
    if (!vp) {
        throw runtime_error("unbound QueryResult vf_ptr");
    } else {
        auto ret = mp->find(str);
        auto size = ret->second.size();
        auto set_beg = ret->second.begin();
        auto v_beg = vp->begin();
        cout << search_word << " occurs " << size << "times" << endl;
        while (set_beg != ret->second.end()) {
            cout << "(line " << *set_beg+1 << ") " << *(v_beg+(*set_beg)) << endl;
            ++set_beg;
        }
    }
}
#endif /* QUERY_RESULT_H */