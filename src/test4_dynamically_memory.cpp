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
using std::unique_ptr;
using std::vector;

struct destination
{
    /* data */
};
struct connection
{
    /* data */
};
connection connect(destination *pd){
    cout << "打开连接" << endl;
    return connection();
}

void disconnect(connection c){
    cout << "关闭连接" << endl;
}

//未使用shared_ptr管理connect版本
void f(destination &d){
    cout << "direct manage connect" << endl;
    connection c = connect(&d);
    cout << endl;
}

void endConnection(connection *p){
    disconnect(*p);
}

void f_sp(destination &d){
    cout << "use shared_ptr manage connect" << endl;
    connection c = connect(&d);
    unique_ptr<connection, decltype(endConnection)*> p(&c, [](connection *p) { disconnect(*p); });
    shared_ptr<int> p1;
    cout << endl;
}

int main(){
    destination d;
    f(d);
    f_sp(d);
    return 0;
}