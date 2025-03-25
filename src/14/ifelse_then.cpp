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
using std::ostream;
using std::out_of_range;
using std::shared_ptr;
using std::string;
using std::vector;
class IfElseThen {
private:
    /* data */
    ostream &os;

public:
    IfElseThen(ostream &out = cout) : os(out) {}
    int operator()(bool flag, int val1, int val2) const {
        os << (flag ? val1 : val2) << endl;
    }
};

int main(){
    IfElseThen obj;
    obj(true, 2, 3);
    return 0;
}


