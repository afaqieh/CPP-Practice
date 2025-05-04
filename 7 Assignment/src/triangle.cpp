#include <iostream>
#include "Triangle.hh"

double Triangle::getArea()
{
    return (0.5 * base * height);
}

double Triangle::getCircumference()
{
    equalSide = sqrt((base / 2) * (base / 2) + (height * height));
    return (equalSide + equalSide + base);
}

Triangle::~Triangle()
{
    std::cout << "Triangle destroyed!" << std::endl;
}
