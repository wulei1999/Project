#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;
class Person {
    /*若想用外部类或者其他函数访问类中的private成员，需要将其变成友元类或友元函数*/
    /*虽然大多编译器运行只在类里进行友元声明一次，但是还有部分编译器不支持，需要在类外进行再一次对友元的函数声明(初始声明)*/
    friend istream &operator>>(istream &, Person &);
    friend std::ostream &operator<<(std::ostream &, const Person &);
    friend bool operator<(const Person &, const Person &);
    friend bool operator==(const Person &, const Person &);
    friend istream &read(istream &in, Person &people);
    
private:
    /* data */
    string name;
    string address;

public:
    Person(/* args */) = default;
    Person(string &n, string add) : name(n), address(add) {}
    explicit Person(istream &is) {
        is >> *this;
    }
    ~Person();

    string getName() const {
        return name;
    }
    string getAddress() const {
        return address;
    }
};
/*虽然大多编译器运行只在类里进行友元声明一次，但是还有部分编译器不支持，需要在类外进行再一次对友元的函数声明(初始声明)*/
istream &operator>>(istream &, Person &);
std::ostream &operator<<(std::ostream &, const Person &);
bool operator<(const Person &, const Person &);
bool operator==(const Person &, const Person &);
istream &read(istream &in, Person &people);
// Person::Person(/* args */) {}

Person::~Person() {}

istream &operator>>(istream &in, Person &per){
    in >> per.name >> per.address;
    return in;
}
istream &read(istream &in, Person &people) {
    cout << "请输入人的名字和地址" << endl;
    in >> people.name >> people.address;
    return in;
}

ostream &print(ostream &out, const Person &people) {
    out << "Name: " << people.getName() << "Address: " << people.getAddress() << endl;
}
#endif /*PERSON_H*/