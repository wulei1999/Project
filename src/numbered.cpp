#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::initializer_list;
using std::istream;
using std::make_shared;
using std::out_of_range;
using std::shared_ptr;
using std::string;
using std::vector;

class Numbered {
private:
    /* data */
    size_t *mysn;

public:
    Numbered() : mysn(new size_t(1)) {}
    Numbered(const Numbered& nb):mysn(new size_t(++(*nb.mysn))){}
    ~Numbered();
    friend void f(const Numbered&);
};

Numbered::~Numbered() {
    delete mysn;
}
void f(const Numbered &s) {
    cout << *s.mysn << endl;
}
int main() {
    Numbered a, b = a, c = b;
    f(a);f(b);f(c);
    return 0;
}
