#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::istream;
using std::ostream;
using std::replace_if;
using std::string;
using std::vector;

class IntCompare
{
private:
    /* data */
    int value;

public:
    IntCompare(int v) : value(v){}
    ~IntCompare() = default;
    bool operator()(int v){
        return v == value;
    }
};

int main(){
    IntCompare obj(5);
    vector<int> vi{1, 2, 3, 4, 5};
    replace_if(vi.begin(), vi.end(), obj, 20);
    for(auto elem : vi){
        cout << elem << endl;
    }
    return 0;
}
