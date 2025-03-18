#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include <iostream>
#include <string>
#include <vector>

#include "screen.h"

using namespace std;

class WindowMgr {
private:
    /* data */
    using screenIndex = vector<Screen>::size_type;
    vector<Screen> screens{Screen(24, 80, ' ')};

public:
    WindowMgr(/* args */) = default;
    ~WindowMgr();
    void clear(screenIndex);
};

WindowMgr::~WindowMgr() {}
/*当编译器处理 window_mgr.h 时，虽然看到了 Screen 类中的友元声明
但是 WindowMgr::clear 的定义是在另一个翻译单元中
C++ 的访问检查是在定义点进行的，而不是在声明点
*/

/*解决方案*/
/*如果需要在不同文件中访问私有成员，最好提供公共接口
或者将实现代码也放在头文件中（但要注意使用 inline）
或者将相互依赖的类定义放在同一个头文件中(即可把clear的定义放在scree.h头文件中)
*/
/*但是即使将实现代码也放在头文件中（但要注意使用 inline）也不能访问，还是需要将其定义隔离开
将函数定义放在对应cpp中*/
/*
void WindowMgr::clear(screenIndex i){
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}
*/

typedef double Money;
class Account{
    public:
    Money balance() {
        return bal;
    }
    private:
        typedef double Money;  // 不能再重新定义类已经用过外层作用域Money的类名了;原则上是错的，但是这里编译器通过了
        Money bal;
};

#endif /*WINDOW_MGR_H*/