#include "hasptr.h"

#if 1
//类值拷贝赋值运算符函数和析构函数
inline HasPtr & HasPtr::operator=(const HasPtr &rhs){
    auto p = new string(*rhs.ps);//先拷贝右侧对象，处理自赋值情况，保证异常发生的时候也是安全的
    delete ps;//在销毁左侧运算对象，释放就内存，保证安全,先delete后赋值的话的话，发生异常原本数据就没了
    //ps = new string(*rhs.ps);//这样会导致释放不了旧内存
    ps = p;
    i = rhs.i;
    return *this;
}

HasPtr::~HasPtr() {
    delete ps;
}
#endif
inline HasPtr &HasPtr::operator=(const string &str) {
    *ps = str;
    return *this;
}
#if 0
inline HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    ++*(rhs.use);
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}
#endif
/*
inline HasPtr &HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);  // 用的自定义版本的swap
    return *this;
}
*/
string &HasPtr::operator*() {
    return *ps;
}

bool HasPtr::operator<(const HasPtr &rhs) const{
    //return *ps < *rhs.ps;//按string排序
    return stoi(*ps) < stoi(*rhs.ps);
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;  // 使用标准库版本的swap
    cout << "交换" << *lhs.ps << "和" << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

#if 0
int main() {
    HasPtr h("hi mom!");
    HasPtr h2(h);
    HasPtr h3 = h;//用的是拷贝构造函数而不是拷贝赋值运算符函数
    h = "hi dad";
    h3 = "hi son";
    swap(h2, h3);
    cout << "h =  " << *h << endl;
    cout << "h2 = " << *h2 << endl;
    cout << "h3 = " << *h3 << endl;
    return 0;
}
#endif

int main(int agrc, char *argv[]) {
    vector<HasPtr> vh;
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++){
        vh.push_back(std::to_string(n - i));
    }
    for(auto p : vh){
        cout << *p << " ";
    }
    cout << endl;
    std::sort(vh.begin(), vh.end());
    for(auto p : vh){
        cout << *p << " ";
    }
    cout << endl;
    return 0;
}