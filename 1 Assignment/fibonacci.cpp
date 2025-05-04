#include <iostream>
#include "fibonacci.h"

int fibonacci(int f, int fprev)
{
    return f + fprev;
}

void GoldenRatio(double f_d, double fprev_d, double phi)
{
    double ratio = f_d / fprev_d;
    double deviation = ((phi - ratio) / phi) * 100;

    std::cout << "Ratio: " << ratio << " - Dev [%]: " << deviation << std::endl;
}