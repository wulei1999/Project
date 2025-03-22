#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <cstring>
#include <iostream>
#include <memory>
#include <new>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::istream;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::vector;

class Employee
{
private:
    /* data */
    static int uid;
    std::string uname;
    int myid;

public:
    Employee(/* args */){
        myid = uid++;
    }
    Employee(const std::string &name) : uname(name){
        myid = uid++;
    }
    Employee(const Employee &emp) : uname(emp.uname){
        myid = uid++;
    }
    Employee &operator=(Employee &emp){
        uname = emp.uname;
    }
    ~Employee();
};

Employee::Employee(/* args */)
{
}

Employee::~Employee()
{
}


#endif /* EMPLOYEE_H */