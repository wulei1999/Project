#include <cstring>
#include <iostream>
#include <memory>
#include <new>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::istream;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::vector;

int main() {
#if 0
    const char *c1 = "Hello";
    const char *c2 = ",World";
    char *cstr = new char[strlen(c1) + strlen(c2) + 1];
    strcpy(cstr, c1);
    strcat(cstr, c2);
    cout << cstr << endl;
    delete[] cstr;

    string s1, s2;
    s1 = "Hello";
    s2 = ",World";
    char *str = new char[strlen(c1) + strlen(c2) + 1]();
    strcpy(str, (s1 + s2).c_str());
    cout << str << endl;
    delete[] str;
    return 0;
#endif

#if 0
    string str;
    getline(cin, str);
    char *r = new char[str.size() + 1];
    strcpy(r, str.c_str());
    cout << r << endl;
    delete[] r;
    return 0;
#endif

#if 1
    char c;
    int i = 0;
    char *r = new char[20];
    while(cin.get(c)){
        if(isspace(c))
            break;
        r[i++] = c;
        if(i == 20){
            cout << "数组容量上限" << endl;
            break;
        }
    }
    r[i] = '\0';
    cout << r << endl;
    delete[] r;
    return 0;
#endif
}