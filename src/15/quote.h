#ifndef QUOTE_H
#define QUOTE_H
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>


using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::istream;
using std::make_shared;
using std::multiset;
using std::ostream;
using std::shared_ptr;
using std::string;
using std::vector;
class Quote {
    friend ostream &operator<<(ostream &, Quote &);

private:
    /* data */
    string book_no;

protected:
    double price = 0.0;

public:
    /*两个构造函数都匹配
    但带默认参数的构造函数优先级更高
    因为默认构造函数是合成的，而带默认参数的构造函数是用户定义的
    */
    /*
        Quote() = default;
    Quote(const string &book = "", double sale_price = 0.0) : book_no(book), price(sale_price) {
        cout << "default Quote" << endl;
    }
    Quote类的拷贝构造函数会隐式调用默认构造函数(如果存在)
    Disc_quote类作为抽象基类(net_price=0)，其默认构造函数实际上被编译器视为删除的
    删除Quote() = default;后,编译器会使用合成的默认构造函数，不会报错
    */
    Quote() = default;
    Quote(const string &book, double sale_price) : book_no(book), price(sale_price) {
        cout << "default Quote" << endl;
    }
    Quote(const Quote &rhs) : book_no(rhs.book_no), price(rhs.price) {
        cout << "const Quote &" << endl;
    }
    Quote(Quote &&) = default;
    virtual ~Quote() {
        cout << "~Quote" << endl;
    }
    Quote &operator=(const Quote &) {
        cout << "const Quote & =" << endl;
        return *this;
    }
    Quote &operator=(Quote &&) = default;
    string isbn() const {
        return book_no;
    }
    virtual double net_price(size_t n) const {
        return n * price;
    }
    virtual void debug() const {
        cout << "bookNo：" << book_no << " price: " << price << endl;
    }
    virtual Quote *clone() const & {
        return new Quote(*this);
    }
    virtual Quote *clone() && {
        return new Quote(std::move(*this));
    }
};

double print_total(ostream &os, const Quote &qt, size_t n) {
    double ret = qt.net_price(n);
    os << "ISBN: " << qt.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

class Disc_quote : public Quote {
protected:
    /* data */
    size_t min_qty;
    double discount;

public:
    Disc_quote() = default;  // 抽象基类没有默认合成构造函数,所以给他个显示的默认构造函数，以便派生类不给它传参数
    Disc_quote(const string &book, double sale_price, size_t min, double dis)
        : Quote(book, sale_price), min_qty(min), discount(dis) {}
    Disc_quote(const Disc_quote &rhs) : Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) {}
    double net_price(size_t cnt) const = 0;
    virtual Quote *clone() const & = 0;
    virtual Quote *clone() && = 0;
};

class Bulk_quote : public Disc_quote {
    friend ostream &operator<<(ostream &, Bulk_quote &);

private:
    /* data */
public:
    // using Disc_quote::Disc_quote;
    Bulk_quote(const string &book = "", double sale_price = 0.0, size_t min = 0, double dis = 0.0)
        : Disc_quote(book, sale_price, min, dis) {
        cout << "Bulk_quote 初始化 min_qty=" << this->min_qty << " discount=" << this->discount
             << endl;
    }
    // 必须显式调用基类拷贝构造函数
    // 因为Disc_quote是抽象基类且有其他构造函数
    // 默认构造函数实际上不可用,
    /*建议保持当前设计，因为Disc_quote作为抽象基类，应该要求派生类提供必要的参数
    需要确保Bulk_quote的拷贝构造函数正确调用基类拷贝构造函数
    */
    Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs) {
        cout << "Bulk_quote &" << endl;
    }
    Bulk_quote(Bulk_quote &&) = default;
    ~Bulk_quote() {
        cout << "~Bulk_quote" << endl;
    }
    Bulk_quote &operator=(const Bulk_quote &rhs) {
        cout << "const Bulk_quote & = " << endl;
        return *this;
    }
    Bulk_quote &operator=(Bulk_quote &&) = default;
    double net_price(size_t cnt) const override {
        if (cnt <= min_qty) {
            return cnt * discount * price;
        } else {
            return (cnt - min_qty) * price + min_qty * discount * price;
        }
    }
    void debug() const override {
        Quote::debug();
        cout << "min_qty: " << min_qty << "discount: " << discount << endl;
    }
    Bulk_quote *clone() const &{
        return new Bulk_quote(*this);
    }
    Bulk_quote *clone() &&{
        return new Bulk_quote(std::move(*this));
    }
    // 添加公共访问方法
    size_t get_min_qty() const {
        return min_qty;
    }
    double get_discount() const {
        return discount;
    }
};

class Basket {
private:
    /* data */
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare) *> items{compare};

public:
/*
    void add_item(const shared_ptr<Quote> &sale) {
        items.insert(sale);
    }
        */
    void add_item(Quote &sale) {
        items.insert(shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale) {
        items.insert(shared_ptr<Quote>(std::move(sale).clone()));
    }
    double total_receipt(ostream &) const;
};

#endif /* QUOTE_H */
