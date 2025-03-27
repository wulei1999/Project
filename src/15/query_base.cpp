#include "query_base.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <string>
using std::array;

inline Query::Query(const string &s) : q(new WordQuery(s)) {
    // cout << "Qurey(string)" << endl;
}

inline ostream &operator<<(ostream &os, const Query &query) {
    os << query.rep();
    return os;
}

inline Query operator~(const Query &operand) {
    return shared_ptr<Query_base>(new NotQuery(operand));
}

Query operator&(const Query &lhs, const Query &rhs) {
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

Query operator|(const Query &lhs, const Query &rhs) {
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
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
    Query p = Query("love") & Query("of");
    print(cout, p.eval(tq));
    return 0;
}

TextQueryEp get_file(int argc, char **argv) {
    // get a file to read from which user will query words
    ifstream infile;
    if (argc == 2)
        infile.open(argv[1]);
    if (!infile) {
        throw runtime_error("No input file!");
    }

    return TextQueryEp(infile);  // builds query map
}

bool get_word(string &s1) {
    cout << "enter a word to search for, or q to quit: ";
    cin >> s1;
    if (!cin || s1 == "q")
        return false;
    else
        return true;
}

bool get_words(string &s1, string &s2) {
    // iterate with the user: prompt for a word to find and print results
    cout << "enter two words to search for, or q to quit: ";
    cin >> s1;

    // stop if hit eof on input or a "q" is entered
    if (!cin || s1 == "q")
        return false;
    cin >> s2;
    return true;
}

// 可读取历史查询记录
int main(int argc, char *argv[]) {
    TextQueryEp file = get_file(argc, argv);
    vector<array<string, 3>> h;
    while (true) {
        string sought1, sought2, sought3;
        if (!get_word(sought1))
            break;
        if (sought1 != "h") {
            cout << "\nenter second and thrid words to search: ";
            cin >> sought2 >> sought3;
            Query q = Query(sought1) & Query(sought2) | Query(sought3);
            h.push_back({sought1, sought2, sought3});
            cout << "\nExecuting Query for: " << q << endl;
            const auto results = q.eval(file);
            print(cout, results);
        } else {
            cout << "\nenter Query no.: ";
            int i;
            cin >> i;
            if (i < 1 || i > h.size()) {
                cout << "\nBad Query no." << endl;
            } else {
                Query q = Query(h[i - 1][0]) & Query(h[i - 1][1]) | Query(h[i - 1][2]);
                cout << "\nExecuting Query for: " << q << endl;
                const auto results = q.eval(file);
                print(cout, results, 1, 16);
            }
        }
    }
    return 0;
}