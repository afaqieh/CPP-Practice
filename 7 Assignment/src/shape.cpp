#include <iostream>
#include "Shape.hh"

double Shape::getArea()
{
    std::cout << "Area can't be calculated because no shape is selected." << std::endl;
    return 1;
}

double Shape::getCircumference()
{
    std::cout << "Circumference can't be calculated because no shape is selected." << std::endl;
    return 1;
}

Shape::~Shape()
{
    std::cout << "Shape destroyed!" << std::endl;
}

void Shape::report()
{std::cout << name << " has area: " << getArea() << " and circumference: " << getCircumference() << std::endl;}