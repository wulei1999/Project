#ifndef MY_TEXT_QUERY_EP_H
#define MY_TEXT_QUERY_EP_H

#include "my_query_result_ep.h"

class QueryResultEp;
class TextQueryEp {
    //friend class QueryResultEp;
public:
    using line_no = vector<string>::size_type;
    TextQueryEp(ifstream &inf);
    QueryResultEp query(const string &) const;
    void display_map();

private:
    /* data */
    StrBlob file;
    map<string, shared_ptr<set<line_no>>> m_word;
    static string cleanup_str(const string);
};

#endif /* MY_TEXT_QUERY_EP_H */