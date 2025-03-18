#include "query_result.h"
#include "text_query.h"
int main(int argc, char* argv[]) {
    ifstream inf(argv[1]);
    if (!inf) {
        cerr << "open file error" << endl;
    }
    string word;
    const TextQuery tq(inf);
    QueryResult qr(tq);
    cout << "enter word to look for, or q to quit: " << endl;
    while (true) {
        if (!(cin >> word) || word == "q")
            break;
        qr.print(word);
        cout << "enter word to look for, or q to quit: " << endl;
    }
    return 0;
}