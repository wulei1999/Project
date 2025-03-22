#include "strvec.h"

allocator<string> StrVec::alloc;  // 静态成员类外定义

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);

    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
#if 0
    if (element) {
        auto beg = element;
        while (beg != first_free) {
            alloc.destroy(beg++);
        }
        alloc.deallocate(element, cap - element);
    }
#endif
#if 0
    if (element) {
        for (auto p = first_free; p != element;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(element, cap - element);
    }
#endif
    if (element) {
        for_each(element, first_free, [](const string &s) { alloc.destroy(&s); });
        alloc.deallocate(element, cap - element);
    }
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto source = element;
    auto elem = element;
    for (size_t i = 0; i < size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    element = newdata;
    first_free = dest;
    cap = element + newcapacity;
}

void StrVec::reallocate(size_t sz) {
    auto newdata = alloc.allocate(sz);
    auto dest = newdata;
    auto source = element;
    for (size_t i = 0; i < size(); i++) {
        alloc.construct(dest++, std::move(*source++));
    }
    free();
    element = newdata;
    first_free = dest;
    cap = element + sz;
}

void StrVec::push_back(const string &str) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(str));
}
StrVec::StrVec(const StrVec &sv) {
    auto newdata = alloc_n_copy(sv.begin(), sv.end());
    element = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(const initializer_list<string> &ini_list) {
    auto newdata = alloc_n_copy(ini_list.begin(), ini_list.end());
    element = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() {
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    element = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    // TODO: 在此处插入 return 语句
    if (this != &rhs) {
        free();
        element = rhs.element;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.element = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

void StrVec::reserve(size_t sz) {
    if (whole_cap() >= sz)
        return;
    else {
        reallocate(sz);
    }
}

void StrVec::resize(size_t sz) {
    if (size() < sz) {
        while (size() < sz)
            push_back("");
    } else if (size() > sz) {
        while (size() > sz) {
            alloc.destroy(--first_free);
        }
    }
}

void StrVec::resize(size_t sz, const string &s) {
    if (size() < sz) {
        while (size() < sz)
            push_back(s);
    }
}

int main() {
    return 0;
}
