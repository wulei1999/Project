#include <iostream>
#include <vector>
// #include <algorithm>
#include <functional>
using std::begin;
using std::bind;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::vector;
using namespace std::placeholders;
using std::bind2nd;
using std::string;

int main() {
    vector<int> vi{1, 3, 2, 3, 3, 2, 4};
    cout << std::count_if(vi.begin(), vi.end(), bind2nd(std::greater<int>(), 2)) << endl;

    vector<string> vs = {"pooh", "pooh", "qqq"};
    cout << *(std::find_if(vs.begin(), vs.end(), bind(std::not_equal_to<string>(), _1, "qqq")))
         << endl;
    std::transform(vi.begin(), vi.end(), vi.begin(), std::bind1st(std::multiplies<int>(), 2));
    for (auto elem : vi) {
        cout << elem << " ";
    }
    cout << endl;
    std::transform(vi.begin(), vi.end(), vi.begin(), std::bind(std::plus<int>(), _1, 2));
    for (auto elem : vi) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "vi中的数能整除3的有："
         << vi.size() - std::count_if(vi.begin(), vi.end(), std::bind(std::modulus<int>(), _1, 3)) << " 个"
         << endl;
    return 0;
}