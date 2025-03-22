#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Foo
{
private:
    /* data */
    vector<int> data;

public:
    Foo(/* args */) = default;
    Foo sorted() &&;
    Foo sorted() const &;
};

Foo Foo::sorted() && {
    cout << "右值版本sorted" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const & {
    cout << "左值版本sorted" << endl;
    Foo ret(*this);
    //return ret.sorted();
    return Foo(*this).sorted();
}

int main(){
    Foo f;
    f.sorted();
    return 0;
}
