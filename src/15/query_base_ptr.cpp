#include "query_base_ptr.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
Query::Query(const string &s) : q(new WordQuery(s)), uc(new int(1)) {
    //cout << "Qurey(string)" << endl;
}

Query::~Query(){
    if(--*uc == 0){
        delete q;
        delete uc;
    }
}

inline ostream &operator<<(ostream &os, const Query &query) {
    os << query.rep();
    return os;
}

inline Query &Query::operator=(const Query &query){
    ++*(query.uc);
    if(--*uc == 0){
        delete q;
        delete uc;
    }
    q = query.q;
    uc = query.uc;
    return *this;
}

inline Query operator~(const Query &operand) {
    return new NotQuery(operand);
}

inline Query operator&(const Query &lhs, const Query &rhs) {
    return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query &lhs, const Query &rhs) {
    return new OrQuery(lhs, rhs);
}

QueryResultEp AndQuery::eval(const TextQueryEp &t) const {
    auto left = lhs.eval(t), right = rhs.eval(t);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                     inserter(*ret_lines, ret_lines->begin()));
    return QueryResultEp(rep(), ret_lines, left.get_file());
}

QueryResultEp OrQuery::eval(const TextQueryEp &t) const {
    auto left = lhs.eval(t), right = rhs.eval(t);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResultEp(rep(), ret_lines, left.get_file());
}

QueryResultEp NotQuery::eval(const TextQueryEp &t) const {
    auto result = query.eval(t);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file().size();
    for (size_t n = 0; n != sz; ++n) {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResultEp(rep(), ret_lines, result.get_file());
}

int main(int argc, char *argv[]) {
    ifstream inf(argv[1]);
    if (!inf) {
        std::cerr << "open file error" << endl;
    }
    string word;
    const TextQueryEp tq(inf);
    Query p = Query("love");
    print(cout, p.eval(tq));
    return 0;
}
