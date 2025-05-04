#include <iostream>
#include "Circle.hh"

double Circle::getArea()
{
    return (pi * (radius * radius));
}

double Circle::getCircumference()
{
    return (2 * pi * radius);
}

Circle::~Circle()
{
    std::cout << "Circle destroyed!" << std::endl;
}
