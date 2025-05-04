#include <iostream>
#include <cmath>
#include <iomanip>
#include "fibonacci.h"

/*
In order to debug i did the following:
1. i created a launch.json file where i edited this '"program": "${workspaceFolder}/build/exercise1",' to create the debugging for my specific program
2. i added a breakpoint at the start of the loop so that the during the debugging the program stops at each iteration
3. i initialized a variable called iterationNumber that kept track of the number of iterations
4. During the debugging i 'watched' the value of f as it changed throughout it
5. I was able to determine that the program overflowed when the value of f became negative as it is an unexpected result

If we want to make our code compute for even larger numbers of fibonacci results, we need to change the datatype from int to something that can handle
more bits such as a long or even a long long. Or since we start with 0 and 1 we can so unsigned int or unsigned long or unsigned long long.
*/

int main()
{
    // Upper limit of system
    int upperLimit = std::numeric_limits<int>::max();
    std::cout << "the upper limit of int on my system is: " << upperLimit << std::endl; // 2147483647

    // Main code
    int f = 1;
    int fprev = 0;
    std::cout << fprev << std::endl;

    int iterationNumber = 1; // To keep track of iteration numbers during debugging
    do
    {
        std::cout << f << std::endl; // added a breakpoint here to keep track of iterations
        int tmp = fibonacci(f, fprev);
        fprev = f;
        f = tmp;
        ++iterationNumber; // increment every complete iteration
    } while (iterationNumber < 47); // at iteration number 47, the program overflows

    // GOLDEN RATIO
    std::cout << std::endl;
    std::cout << "Lets estimate the golden ratio." << std::endl;

    const double phi = (1 + std::sqrt(5)) / 2;
    double f_d = 1;
    double fprev_d = 0;

    for (int counter = 0; counter < 45; ++counter)
    {
        std::cout << std::fixed << std::setprecision(17);
        int tmp_d = fibonacci(f_d, fprev_d);
        fprev_d = f_d;
        f_d = tmp_d;

        GoldenRatio(f_d, fprev_d, phi);
    }
    //
    return 0;
}