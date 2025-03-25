#include <iostream>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

class Date {
private:
    /* data */
    unsigned int year = 1900;
    unsigned int month = 1;
    unsigned int day = 1;

public:
    Date(/* args */) = default;
    Date(unsigned int y, unsigned int m, unsigned int d) : year(y), month(m), day(d) {}
    ~Date() = default;
    explicit operator bool(){
        vector<vector<int>> days_per_month = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                              {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
        return 1 <= month && month <= 12 && 1 <= day &&
               day <= days_per_month[is_leap_year() ? 1 : 0][month - 1];
    }
    bool is_leap_year(){
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};