#include <cstring>
#include <iostream>
#include <memory>
#include <new>
#include <string>
#include <vector>

using std::allocator;
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
    allocator<string> alloc;
    auto const p = alloc.allocate(100);
    string s;
    string *q = p;
    while(cin>>s && q != p+100){
        alloc.construct(q, s);
        ++q;
    }
    const size_t size = q - p;
    cout << size << endl;
    for (int i = 0; i < size; i++){
        cout << p[i] << endl;
    }
    while(q != p){
        alloc.destroy(--q);
    }
    alloc.deallocate(p, 100);
    return 0;
}