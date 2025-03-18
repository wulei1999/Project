#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
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


class QueryResult;
class TextQuery {
public:
    friend class QueryResult;
    TextQuery(/* args */) = default;
    TextQuery(ifstream &inf);
    void saveFile();
    ~TextQuery();

private:
    /* data */
    std::ifstream &in;
    vector<string> v_file;
    map<string, set<unsigned long int>> m_file;
    shared_ptr<vector<string>> vf_ptr;
    shared_ptr<map<string, set<unsigned long int>>> mf_ptr;
    void check(const string str, const string &msg) const;
};

TextQuery::~TextQuery() {}
inline TextQuery::TextQuery(ifstream &inf) : in(inf){
    saveFile();
    vf_ptr = make_shared<vector<string>>(v_file);
    mf_ptr = make_shared<map<string, set<unsigned long int>>>(m_file);
}
void TextQuery::check(const string str, const string &msg) const{
    if(mf_ptr->find(str) == mf_ptr->end()){
        throw out_of_range(msg);
    }
}
inline void TextQuery::saveFile() {
    string str;
    char ch = '\0';
    unsigned long int line = 0;
    while (getline(in, str)) {
        v_file.push_back(str);
        string word;
        istringstream in_str(str);
        set<unsigned long int> sl;
        sl.insert(line);
        while (in_str >> word) {
            auto ret =  m_file.insert(make_pair(word, sl));
            if (!ret.second) {
                m_file[word].insert(line);                
            }
        }
        ++line;
    }
}

#endif /* TEXT_QUERY_H */