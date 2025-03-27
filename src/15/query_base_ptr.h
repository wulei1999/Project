#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include "../my_text_query_ep.h"

class Query_base {
    friend class Query;

private:
    virtual QueryResultEp eval(const TextQueryEp&) const = 0;
    virtual string rep() const = 0;

protected:
    /* data */
    using line_no = TextQueryEp::line_no;
    ~Query_base() = default;
};

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
    friend inline ostream &operator<<(ostream &os, const Query &query);

private:
    /* data */
    Query(Query_base *query) : q(query), uc(new int(1)){
        //cout << "Qurey(shared_ptr<Query_base>)" << endl;
    }
    Query_base *q;
    int *uc;

public:
    Query(const string &);
    Query(const Query &query) : q(query.q), uc(query.uc) {
        ++*uc;
    }
    ~Query();
    Query &operator=(const Query &query);
    QueryResultEp eval(const TextQueryEp &t) const {
        return q->eval(t);
    }
    string rep() const{
        //cout << "Qurey(rep)" << endl;
        return q->rep();
    }
};

class WordQuery : public Query_base
{
    friend class Query;
    string query_word;
    WordQuery(const string &s) : query_word(s) {
        //cout << "WordQuery(string)" << endl;
    }
    QueryResultEp eval(const TextQueryEp &t) const{
        return t.query(query_word);
    }
    string rep() const {
        //cout << "WordQuery(rep)" << endl;
        return query_word;
    }
};

class NotQuery : public Query_base
{
    friend Query operator~(const Query &);
    Query query;
    NotQuery(const Query &q) : query(q) {
        //cout << "NotQuery(Query)" << endl;
    }
    QueryResultEp eval(const TextQueryEp &t) const;
    string rep() const {
        //cout << "NotQuery(rep)" << endl;
        return "~(" + query.rep() + ")";
    }
};

class BinaryQuery : public Query_base
{
protected:
    Query lhs, rhs;
    string opsym;
    BinaryQuery(const Query &l, const Query &r, string s) : lhs(l), rhs(r), opsym(s){
        //cout << "BinaryQuery()" << endl;
    }
    string rep() const{
        //cout << "BinaryQuery(rep)" << endl;
        return "(" + lhs.rep() + " " + opsym + " " + rhs.rep() + ")";
    }
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);  
    AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&"){
        //cout << "AndQuery()" << endl;
    }
    QueryResultEp eval(const TextQueryEp &) const;
};

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);  
    OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|"){
        //cout << "OrQuery()" << endl;
    }
    QueryResultEp eval(const TextQueryEp &) const;
};



#endif /* QUERY_BASE_H */
