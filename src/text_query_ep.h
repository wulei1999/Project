#ifndef TEXT_QUERY_EP_H
#define TEXT_QUERY_EP_H
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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
class QueryResultEp;
class TextQueryEp {
    friend class QueryResultEp;
public:
    using line_number = vector<string>::size_type;
    TextQueryEp(/* args */) = default;
    TextQueryEp(ifstream &inf);
    ~TextQueryEp();
    QueryResultEp query(const string &) const;

private:
    /* data */
    shared_ptr<vector<string>> v_file;
    map<string, shared_ptr<set<line_number>>> m_word;
};

inline TextQueryEp::TextQueryEp(ifstream &inf) : v_file(new vector<string>) {
    string text;
    while (getline(inf, text)) {
     v_file->push_back(text);
        unsigned long int n = v_file->size() - 1;
        istringstream in_text(text);
        string word;
        while (in_text >> word) {
            auto &line_ptr = m_word[word];
            if (!line_ptr) {
                line_ptr.reset(new set<line_number>);
            }
            line_ptr->insert(n);
        }
    }
}

TextQueryEp::~TextQueryEp() {}

#endif /*  TEXT_QUERY_EP_H */