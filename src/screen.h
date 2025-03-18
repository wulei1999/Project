#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include "window_mgr.h"

using namespace std;

class Screen {
    //包含对应的头文件，使得Screen类知道有该类和函数
    friend class WindowMsg;
    friend void WindowMgr::clear(screenIndex);

public:
    typedef std::string::size_type pos;
    Screen(/* args */) = default;
    Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}
    Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {}
    ~Screen();
    char get() const {
        return contents[cursor];
    }
    char get(pos r, pos c) const {
        return contents[r * width + c];
    }
    Screen move(pos r, pos c);
    Screen &set(pos, pos, char);
    Screen set(char);
    Screen &display(std::ostream &out) {
        do_display(out);
        return *this;
    }
    const Screen &display(std::ostream &out) const {
        do_display(out);
        return *this;
    }

    void clearScreen(pos index){
        // WindowMgr::clear(index);//非静态成员必须通过对象调用，这是因为在WindowMgr作用域外,在类内可以用类作用域符指定成员来隐藏别的同名声明的变量或函数
        // clear(index);//需要定义了才能使用，单声明为友元函数还不行
    }

private:
    /* data */
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
    void do_display(std::ostream &out) const {
        out << contents;
    }
};

/*Screen::Screen() {}*/
Screen::~Screen() {}

inline Screen Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(pos row, pos col, char ch) {
    contents[row * width + col] = ch;
    return *this;
}
inline Screen Screen::set(char ch){
    contents[cursor] = ch;
    return *this;
}
void WindowMgr::clear(screenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}
#endif /*SCREEN_H*/