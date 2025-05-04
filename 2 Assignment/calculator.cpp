#include <iostream>
#include <random>
#include "calculator.h"
#include <cmath>

void add(int firstNumber, int secondNumber, int &result)
{
    result =  firstNumber + secondNumber;
}

int addNumbers(int firstNumber, int secondNumber, int thirdNumber, int fourthNumber) 
{
    return firstNumber + secondNumber + thirdNumber + fourthNumber;
}

void printType(const int&){std::cout << "type is int" << std::endl;}
void printType(const double&){std::cout << "type is double" << std::endl;}
void printType(const float&){std::cout << "type is float" << std::endl;}
void printType(const std::string&){std::cout << "type is string" << std::endl;}

double throwDarts(int numberOfDarts)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution dist(0.0, 1.0);
    double count = 0.0;
    for (int i = 0; i < numberOfDarts; ++i)
    {
        double x = dist(mt);
        double y = dist(mt);
        if (sqrt((x * x) + (y * y)) <= 1) 
        {
            ++count;
        }
    }

    return 4.0 * (count / numberOfDarts);
}