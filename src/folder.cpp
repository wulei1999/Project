#include "folder.h"

#if 0
inline void Folder::addMsg(Message *m) {
    msgs.insert(m);
}

inline void Folder::remMsg(Message *m) {
    msgs.erase(m);
}
#endif

inline void Folder::add_to_messages(const Folder &f) {
    for (auto m : f.msgs) {
        m->add_fldr(this);
    }
}

void Folder::remove_from_messages() {
    while (!msgs.empty())
        (*msgs.begin())->remove(*this);
}


inline Folder::Folder(const Folder &fd) : msgs(fd.msgs) {
    add_to_messages(fd);
}

inline Folder::Folder::~Folder() {
    remove_from_messages();
}

Folder &Folder::operator=(Folder &f) {
    // TODO: 在此处插入 return 语句
    remove_from_messages();
    msgs = f.msgs;
    add_to_messages(f);
    return *this;
}

void Folder::save(Message &m) {
    msgs.insert(&m);
    m.add_fldr(this);
}

void Folder::remove(Message &m)
{
    // erase m from msgs and remove this folder from m
    msgs.erase(&m);
    m.rem_fldr(this);
}

void Folder::debug_print()
{
    std::cerr << "Folder contains " << msgs.size() << " messages" << endl;
    int ctr = 1;
    for (set<Message*>::iterator m = msgs.begin();
			m != msgs.end(); ++m) {
        std::cerr << "Message " << ctr++ << ":\n\t" << (*m)->contents << endl;
	}
}
