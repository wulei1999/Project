#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <new>
#include <memory>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::istream;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

shared_ptr<vector<int>> dynamicVector(){
    return  make_shared<vector<int>>();
}

void saveCinToDynamicV(istream &in, shared_ptr<vector<int>> pv){
    int a;
    while(in >> a){
        pv->push_back(a);
    }
}

void printDynamicVector(shared_ptr<vector<int>> pv){
    for (auto x: *pv){
        cout << x << " ";
    }
    cout << endl;
}
int main(){
    shared_ptr<vector<int>> p_v = dynamicVector();
    saveCinToDynamicV(cin, p_v);
    printDynamicVector(p_v);
    return 0;
}