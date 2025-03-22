#ifndef MESSAGE_H
#define MESSAGE_H
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <set>
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
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

class Folder;
class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);

private:
    /* data */
    string contents;
    set<Folder *> folders;
    // 拷贝构造函数，拷贝赋值运算符， 析构函数所需要的工具函数
    void add_to_folders(const Message &);
    void remove_from_folders();
    void add_fldr(Folder *);
    void rem_fldr(Folder *);
    void move_folders(Message *m);

public:
    explicit Message(const string &str = "") : contents(str) {}
    Message(const Message &);
    Message(Message &&m) noexcept : contents(std::move(m.contents)){
        move_folders(&m);
    }
    ~Message();
    Message &operator=(const Message &);
    Message &operator=(Message &&) noexcept;

    void save(Folder &);
    void remove(Folder &);
    void debug_print();
};

#endif /* MESSAGE_H */