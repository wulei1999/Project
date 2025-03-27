#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

class Figure
{
protected:
    /* data */
    double xsize, ysize;

public:
    Figure(double, double);
};

class Figure_2D : public Figure
{
public:
    Figure_2D(double, double);
    virtual double area() = 0;
    virtual double pcrimeter() = 0;
};

class Figure_3D : public Figure
{
protected:
    double zsize;

public:
    Figure_3D(double, double, double);
    virtual double cubage() = 0;
};

class Rectangle : public Figure_2D
{
public:
    Rectangle(double, double);
    virtual double area() override;
    virtual double pcrimeter() override;
};

class Circle : public Figure_2D
{
public:
    Circle(double, double);
    virtual double area() override;
    virtual double pcrimeter() override;
};

class Sphere : public Figure_3D
{
public:
    Sphere(double, double, double);
    virtual double cubage() override;
};

class Cone : public Figure_3D
{
public:
    Cone(double, double, double);
    virtual double cubage() override;
};
#endif /* FIGURE_H */