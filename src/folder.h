#ifndef FOLDER_H
#define FOLDER_H
#include "message.h"

class Folder {
    friend class Message;
    friend void swap(Message &lhs, Message &rhs);

private:
    /* data */
    set<Message *> msgs;
    void add_to_messages(const Folder &);
    void remove_from_messages();
    void addMsg(Message *m) {
        msgs.insert(m);
    }
    void remMsg(Message *m) {                                                                                                                                                                                                                                                             
        msgs.erase(m);
    }

public:
    Folder() = default;
    Folder(const Folder &fd);
    ~Folder();
    Folder &operator=(Folder &);
    void save(Message &);    // add this message to folder
    void remove(Message &);  // remove this message from this folder
    void debug_print();
};

#endif /* FOLDER_H */