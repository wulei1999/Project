#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <new>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::istream;
using std::string;
using std::vector;

vector<int> *dynamicVector(){
    return new vector<int>();
}

void saveCinToDynamicV(istream &in, vector<int> *pv){
    int a;
    while(in >> a){
        pv->push_back(a);
    }
}

void printDynamicVector(vector<int> *pv){
    for (auto x: *pv){
        cout << x << " ";
    }
    cout << endl;
}
int main(){
    vector<int> *p_v = dynamicVector();
    saveCinToDynamicV(cin, p_v);
    printDynamicVector(p_v);
    delete p_v;
    p_v = nullptr;
    return 0;
}