#include "my_text_query_ep.h"
#include "make_pluarl.h"
//按行查询单词
/*
TextQueryEp::TextQueryEp(ifstream &inf) : file(new vector<string>) {
    string text;
    while (getline(inf, text)) {
        file.push_back(text);
        unsigned long int n = file.size() - 1;
        istringstream in_text(text);
        string word;
        while (in_text >> word) {
            auto &line_ptr = m_word[word];
            if (!line_ptr) {
                line_ptr.reset(new set<line_no>);
            }
            line_ptr->insert(n);
        }
    }
}
*/
//按句子查询单词,将每个句子的所在文件中的位置记录在set中，当查询单词时，打印查询单词所在句子
TextQueryEp::TextQueryEp(ifstream &inf) : file(new vector<string>) {
    char ws[] = {'\t', '\r', '\v', '\f', '\n'};
    char eos[] = {'?', '.', '!'};
    set<char> white_space(ws, ws + 5);
    set<char> end_of_sentence(eos, eos + 3);
    string sentence;
    char ch;
    while (inf.get(ch)) {
        if(!white_space.count(ch)) //非空白符
            sentence += ch;
        //读完了一个句子
        if(end_of_sentence.count(ch)){
            file.push_back(sentence);
            int n = file.size() - 1;
            istringstream is(sentence);
            string word;
            while(is >> word){
                auto &lines = m_word[word];
                if (!lines) {//值为空
                    lines.reset(new set<line_no>);
                }
                lines->insert(n);                
            }
            sentence.assign("");  // 将sentence清空读下一个句子;
        }
    }
}


string TextQueryEp::cleanup_str(const string word) {
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it) {
        if (!ispunct(*it))
            ret += tolower(*it);
    }
    return ret;
}

QueryResultEp TextQueryEp::query(const string &word) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = m_word.find(word);
    if (loc == m_word.end()) {
        return QueryResultEp(word, nodata, file);
    } else {
        return QueryResultEp(word, loc->second, file);
    }
}

string make_plural(size_t ctr, const string &word, const string ending) {
    return (ctr > 1) ? word + ending : word;
}

ostream &print(ostream &os, const QueryResultEp &qr) {
    cout << qr.search_word << " occurs " << qr.lines->size() << " "
         << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *(qr.lines)) {
        //os << "\t(line " << num + 1 << ") " << qr.file.begin().deref(num) << endl;
        os << "\t(sentence " << num + 1 << ") " << qr.file.begin().deref(num) << endl;
    }
    return os;
}


//允许用户给定范围行来输出结果
ostream &print(ostream &os, const QueryResultEp &qr, int beg, int end) {
    cout << qr.search_word << " occurs " << qr.lines->size() << " "
         << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *(qr.lines)) {
        //os << "\t(line " << num + 1 << ") " << qr.file.begin().deref(num) << endl;
        if(num + 1 >= beg && num + 1 <= end)
            os << "\t(sentence " << num + 1 << ") " << qr.file.begin().deref(num) << endl;
    }
    return os;
}


void TextQueryEp::display_map() {
    auto iter = m_word.begin(), iter_end = m_word.end();
    for (; iter != iter_end; ++iter) {
        cout << "word: " << iter->first << " {";

        auto text_locs = iter->second;
        auto loc_iter = text_locs->begin(), loc_iter_end = text_locs->end();
        while (loc_iter != loc_iter_end) {
            cout << *loc_iter;
            if (++loc_iter != loc_iter_end)
                cout << ", ";
        }
        cout << "}\n";
    }
    cout << endl;
}