#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void add(int firstNumber, int secondNumber, int &result);
int addNumbers(int firstNumber = 0, int secondNumber = 0, int thirdNumber = 0, int fourthNumber = 0);

void printType(const int&); // use of const is to avoid copying of the variable for optimization purposes
void printType(const double&);
void printType(const float&);
void printType(const std::string&);

double throwDarts(int numberOfDarts);

#endif