#ifndef SALEDATA_H
#define SALEDATA_H
#include <iostream>
#include <string>

using namespace std;

class SaleData {
    // 若不在类里声明为友元函数，则在类外定义函数的函数体中不能访问类中私有成员
    friend istream& operator>>(istream&, SaleData&);
    friend ostream& operator<<(ostream&, SaleData&);
    friend bool operator<(const SaleData&, const SaleData&);
    friend bool operator==(const SaleData&, const SaleData&);
    friend SaleData operator+(const SaleData&, const SaleData&);
    friend SaleData operator-(const SaleData&, const SaleData&);

private:
    /* data */
    string book_number;
    unsigned int units_sold = 0;
    double sellingprice = 0.0;
    double sale_price = 0.0;
    double revenue = 0.0;
    double avg_p = 0.0;
    double discount = 0.0;

public:
    // 构造函数的三种形式
    // default，无需在类的外部定义，编译器来构造
    // 若有其他类型的构造函数，必须给出默认构造函数，防止编译不能生成默认构造函数
    SaleData(/* args */) = default;
    // SaleData(const string& book = "") : book_number(book) {}
    SaleData(const string& book) : book_number(book) {}
    SaleData(const string& book, unsigned sold_num, double sold_price)
        : book_number(book), units_sold(sold_num), sale_price(sold_price) {
        cout << "三参数构造函数\n";
        cout << book_number << " " << units_sold << " " << sale_price << endl;
    }

    SaleData(istream& is) {
        is >> *this;
    }

    // 委托构造函数：
    /*关键点说明：
    1委托构造函数使用另一个构造函数来初始化对象
    2委托构造函数的初始化列表只能包含一个委托
    3被委托的构造函数先执行，然后执行委托构造函数的函数体
    4构造函数体内可以包含其他语句（如输出信息）
    5委托构造函数中不能指定参数类型，只能使用实参
    6不要在同一个类中混用委托构造函数和普通构造函数的初始化方式
    7默认参数构造函数和普通构造函数会造成歧义
    8使用委托构造函数时，应该有一个主构造函数完成实际的初始化工作
    其他构造函数通过委托到这个主构造函数来完成初始化
    */
    /*
    与单个参数构造函数产生二义性
    SaleData(const string& book = "") : SaleData("", 0, 0) {
        cout << "默认构造函数\n";
    }
    */
    /*
     SaleData() : SaleData("", 0, 0) {
         cout << "默认构造函数\n";
         cout << book_number << " " << units_sold << " " << sale_price << endl;
     }
     SaleData(const string& book) : SaleData(book, 0, 0) {
         cout << "单参数构造函数\n";
         cout << book_number << " " << units_sold << " " << sale_price << endl;
     }
     SaleData(istream& is) : SaleData() {
         is >> *this;
         cout << "istream构造函数\n";
         cout << book_number << " " << units_sold << " " << sale_price << endl;
     }
     */
    ~SaleData();
    // 内联函数，成员函数直接定义，无需inline标识符就是内联函数
    // const成员函数,表示this是一个指向常量SaleData 类型的常量指针
    // 普通函数默认的的this为常量指针指向的是非常量类类型
    SaleData& operator=(const string&);
    string isbn() const {
        return book_number;
    }
    SaleData& combine(const SaleData& trans) {
        units_sold += trans.units_sold;
        revenue += trans.revenue;
        avg_p = revenue / units_sold;
        return *this;
    }
    double avg_price() const;
    SaleData& operator+=(const SaleData&);
    SaleData& operator-=(const SaleData&);

    explicit operator double() const {
        return revenue;
    }
    explicit operator string() const {
        return book_number;
    }
};
// 如果要使用=default，使编译器生成构造函数即合成构造函数需要加上，用类内初始值来初始化对象成员
// 如果不使用，则声明上不加，需要自己写个下面的默认构造函数定义
// SaleData::SaleData(/* args */){}

SaleData::~SaleData() {}

inline SaleData& SaleData::operator=(const string& isbn) {
    // TODO: 在此处插入 return 语句
    book_number = isbn;
    return *this;
}

istream& operator>>(istream& in, SaleData& sd) {
    cout << "请依次输入书号，数量，预售价，销售价" << endl;
    in >> sd.book_number >> sd.units_sold >> sd.sellingprice >> sd.sale_price;
    sd.revenue = sd.units_sold * sd.sale_price;
    sd.avg_p = sd.avg_price();
    if (in && sd.sellingprice > 0) {
        sd.discount = sd.sale_price - sd.sellingprice / sd.sellingprice;
    } else {
        sd = SaleData();
    }
    return in;
}
ostream& operator<<(ostream& out, SaleData& sd) {
    out << "书号：" << sd.isbn() << "销售数量： " << sd.units_sold << "销售均价： " << sd.avg_p
        << "总额 " << sd.revenue << "折扣： " << sd.discount;
    return out;
}

SaleData& SaleData::operator+=(const SaleData& sd) {
    units_sold += sd.units_sold;
    revenue += sd.revenue;
    sale_price = revenue / sale_price;
    if (sellingprice != 0) {
        discount = sale_price / sellingprice;
    }
    return *this;
}
SaleData& SaleData::operator-=(const SaleData& sd) {
    units_sold -= sd.units_sold;
    revenue -= sd.revenue;
    sale_price = revenue / sale_price;
    if (sellingprice != 0) {
        discount = sale_price / sellingprice;
    }
    return *this;
}

inline double SaleData::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

SaleData operator+(const SaleData& sd1, const SaleData& sd2) {
    SaleData sd_temp(sd2);
    sd_temp += sd1;
    return sd_temp;
}
SaleData operator-(const SaleData& lhs, const SaleData& rhs) {
    SaleData temp = lhs;
    temp -= rhs;
    return temp;
}
SaleData add(SaleData& sd1, SaleData& sd2) {
    SaleData sd_temp = sd1;
    sd_temp.combine(sd2);
    return sd_temp;
}

istream& read(istream& in, SaleData& sd) {
    in >> sd;
    return in;
}

ostream& print(ostream& out, SaleData& sd) {
    out << sd;
    return out;
}

inline bool compareIsbn(const SaleData& lhs, const SaleData& rhs) {
    return lhs.isbn() < rhs.isbn();
}
#endif /*SaleData_H*/