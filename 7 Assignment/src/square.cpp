#include <iostream>
#include "Square.hh"

double Square::getArea()
{
    return (sideLength * sideLength);
}

double Square::getCircumference()
{
    return (4 * sideLength);
}

Square::~Square()
{
    std::cout << "Square destroyed!" << std::endl;
}
