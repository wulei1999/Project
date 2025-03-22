#include "strvec_query_result.h"
using std::cerr;
int main(int argc, char* argv[]) {
    ifstream inf(argv[1]);
    if (!inf) {
        cerr << "open file error" << endl;
    }
    string word;
    const TextQueryEp tq(inf);
    cout << "enter word to look for, or q to quit: " << endl;
    while (true) {
        if (!(cin >> word) || word == "q")
            break;
        QueryResultEp qr = tq.query(word);
        print(cout, qr);
        cout << "enter word to look for, or q to quit: " << endl;
    }
    return 0;
}