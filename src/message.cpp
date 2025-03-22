#include "message.h"

#include "folder.h"

void Message::add_fldr(Folder *f) {
    folders.insert(f);
}

void Message::rem_fldr(Folder *f) {
    folders.erase(f);
}

void Message::move_folders(Message *m) {
    folders = std::move(m->folders);
    for (auto f : folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}
void Message::add_to_folders(const Message &m) {
    for (auto &f : m.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_folders() {
    for (auto &f : folders) {
        f->remMsg(this);
    }
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_folders(m);
}

Message::~Message() {
    remove_from_folders();
}

Message &Message::operator=(const Message &rhs) {
    // TODO: 在此处插入 return 语句
    remove_from_folders();  // 防止自赋值
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}

Message &Message::operator=(Message &&rhs) noexcept {
    // TODO: 在此处插入 return 语句
    if (this != &rhs) {
        remove_from_folders();
        contents = std::move(rhs.contents);
        move_folders(&rhs);
    }
    return *this;
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::debug_print() {
    std::cerr << "Message:\n\t" << contents << endl;
    std::cerr << "Appears in " << folders.size() << " Folders" << endl;
}
void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);

    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);

    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}
