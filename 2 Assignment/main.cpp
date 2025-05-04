#include <iostream>
#include "calculator.h"


void doubleNumber(int &num){num = num * 2;} // to fix it, we pass by reference

int main()
{
    // 2.1.1
    std::cout << "Exercise 2.1.1" <<std::endl;
    std::cout << "Enter two numbers: ";
    int number1{0};
    int number2{0};
    int result{0};
    std::cin >> number1 >> number2;
    add(number1, number2, result);
    std::cout << "The sum is " << result;
    
    // 2.1.3
    /*
    The problem in part 2.1.3 is that the variable is not passed by reference and is passed by value and so the value of num will not change and 
    therefore will print 35 instead
    }
    */
    std::cout << std::endl;
    std::cout << "\nExercise 2.1.3" << std::endl;
    int num{35};
    doubleNumber(num);
    std::cout << num;

    //2.2
    std::cout << std::endl;
    std::cout << "\nExercise 2.2" << std::endl;
    int firstResult{addNumbers(1,2,3,4)};
    int secondResult{addNumbers(1,2,3)};
    int thirdResult{addNumbers(1,2)};
    int fourthResult{addNumbers(1)};
    int fifthResult{addNumbers()};
    std::cout << "The result of addNumbers is " << firstResult << " " << secondResult << " " << thirdResult << " " << fourthResult << " " << fifthResult << " respectively.";

    // 2.3
    std::cout << "\n" << std::endl;
    std::cout << "\nExercise 2.3" << std::endl;
    int intNumber{42};
    printType(intNumber);
    double doubleNumber{2.56};
    printType(doubleNumber);
    float floatNumber{1.666f};
    printType(floatNumber);
    std::string stringVariable{"Hello"};
    printType(stringVariable);

    // 3
    std::cout << std::endl;
    std::cout << "\nExercise 3" << std::endl;
    std::cout << "Enter the number of darts you would like to throw: " << std::endl;
    int numberOfDarts{0};
    std::cin >> numberOfDarts;
    double pi = throwDarts(numberOfDarts);
    std::cout << "Value of pi is " << pi << std::endl;

    return 0;
}

