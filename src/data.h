#ifndef DATA_H
#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::forward_list;
using std::ifstream;
using std::invalid_argument;
using std::list;
using std::ostream;
using std::string;
using std::vector;

class Data {
    friend ostream &operator<<(ostream &, const Data &);

private:
    /* data */
    unsigned year, month, day;

public:
    Data(/* args */) = default;
    Data(string &str_data);
    unsigned y() const {
        return year;
    }
    unsigned m() const {
        return month;
    }
    unsigned d() const {
        return day;
    }
    ~Data();
};

const string month_fullname[] = {"January",   "February", "March",    "April",
                                 "May",       "June",     "July",     "August",
                                 "September", "October",  "November", "December"};
const string month_simplename[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline int getMonth(string &data, int &end_of_month) {
    int i, j;
    for (i = 0; i < 12; ++i) {
        for (j = 0; j < month_simplename[i].size(); ++j) {
            if (data[j] != month_simplename[i][j]) {
                break;
            }
        }
        if (j == month_simplename[i].size()) {
            break;
        }
    }

    if (i == 12) {
        throw invalid_argument("不是合法月份");
    }
    if (data[j] == ' ') {
        end_of_month = j + 1;
        return i + 1;
    }
    for (; j < month_fullname[i].size(); ++j) {
        if (data[j] != month_fullname[i][j]) {
            break;
        }
    }
    if (j == month_fullname[i].size() && data[j] == ' ') {
        end_of_month = j + 1;
        return i + 1;
    }
    throw invalid_argument("不是合法月份");
}

inline int getDay(string &data, int month, int &p) {
    size_t q;
    int day = stoi(data.substr(p), &q);
    if (day < 1 || day > days[month]) {
        throw invalid_argument("不是合法天数");
    }
    p += q;
    return day;
}

inline int getYear(string &data, int &p) {
    size_t q;
    int year = stoi(data.substr(p), &q);
    if (p + q < data.size()) {
        throw invalid_argument("不是合法结尾内容");
    }
    return year;
}

Data::Data(string &str_data) {
    int p;
    size_t q;
    if ((p = str_data.find_first_of("0123456789")) == string::npos) {
        throw invalid_argument("没有数字");
    }

    if (p > 0) {
        month = getMonth(str_data, p);
        day = getDay(str_data, month, p);
        if (str_data[p] != ' ' && str_data[p] != ',') {
            throw invalid_argument("非法间隔符");
        }
        ++p;
        year = getYear(str_data, p);
    } else {
        month = stoi(str_data, &q);
        p = q;
        if (month < 1 || month > 12) {
            throw invalid_argument("不是合法月份数值");
        }
        if (str_data[p++] != '/') {
            throw invalid_argument("非法间隔符");
        }
        day = getDay(str_data, month, p);
        if (str_data[p++] != '/') {
            throw invalid_argument("非法间隔符");
        }
        year = getYear(str_data, p);
    }
}
Data::~Data() {}

ostream &operator<<(ostream &out, const Data &data) {
    out << data.y() << "年" << data.m() << "月" << data.d() << "日" << endl;
    return out;
}

#define DATA_H
#endif /*DATA_H*/