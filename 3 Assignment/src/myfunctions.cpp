#include <iostream>
#include <limits>
#include <memory>
#include <vector>
#include <numeric>
#include <algorithm>
#include "myfunctions.hh"

void SumMinMaxUnsafeArrays()
{
    std::cout << "Unsafe Arrays ->" << std::endl;
    std::cout << "How many values do you want to enter?: ";
    auto answer{0};
    std::cin >> answer;
    auto* array = new int[answer];
    auto summationIndex{0};
    auto summationPointer{summationIndex};
    auto maxIndex = std::numeric_limits<int>::min(); // The smallest possible value as an integer
    auto minIndex = std::numeric_limits<int>::max(); // The largest possible value as an integer
    auto maxPointer{maxIndex};
    auto minPointer{minIndex};
    
    for (int i = 0; i < answer; ++i) 
    {   
        int result{0};
        std::cout<< "value: ";
        std::cin >> result;
        array[i] = result;
    }

    // results using index access []
    for (int i = 0; i < answer; ++i)
    {
        summationIndex += array[i];
        if (array[i] < minIndex)
        {
            minIndex = array[i];
        }
        if (array[i] > maxIndex)
        {
            maxIndex = array[i];
        }
    }

    // results using pointer arithmetics
    int* temp = array; // using a temporary pointer
    for (int i = 0; i < answer; ++i)
    {
        summationPointer += *temp;
        if (*temp < minPointer)
        {
            minPointer = *temp;
        }
        if (*temp > maxPointer)
        {
            maxPointer = *temp;
        }
        
        ++temp;
    }

    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Results (Index / Pointer Arithmetic):" << std::endl;
    std::cout << "Sum:" << summationIndex << " / " << summationPointer << std::endl;
    std::cout << "Min:" <<  minIndex << " / " << minPointer <<std::endl;
    std::cout << "Max:" << maxIndex << " / " << maxPointer <<std::endl;

    delete[] array;
    array = nullptr;
}

void SumMinMaxSmartPointer()
{
    std::cout << "\nSmart Pointer ->" << std::endl;
    std::cout << "How many values do you want to enter?: ";
    auto answer{0};
    std::cin >> answer;
    std::unique_ptr<int[]> smartPtr(new int[answer]);
    auto summation{0};
    auto max = std::numeric_limits<int>::min();
    auto min = std::numeric_limits<int>::max();

    for (int i = 0; i < answer; ++i) 
    {   
        int result{0};
        std::cout<< "value: ";
        std::cin >> result;
        smartPtr[i] = result;
    }

    for (int i = 0; i < answer; ++i)
    {
        summation += smartPtr[i];
        if (smartPtr[i] < min)
        {
            min = smartPtr[i];
        }
        if (smartPtr[i] > max)
        {
            max = smartPtr[i];
        }
    }
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Results:" << std::endl;
    std::cout << "Sum:" << summation << std::endl;
    std::cout << "Min:" <<  min << std::endl;
    std::cout << "Max:" << max << std::endl;
}

void SumMinMaxSTL()
{
    std::cout << "\nSTL Dynamic Pointer ->" << std::endl;
    std::cout << "How many values do you want to enter?: ";
    auto answer{0};
    std::cin >> answer;
    std::vector<int> vector(answer);

    for (int& value: vector) // i am using SonarQube for standard ways to write the code as you suggested and it suggested this form of a for loop
    {   
        int result{0};
        std::cout<< "value: ";
        std::cin >> result;
        value = result;
    }

    int sum{std::accumulate(vector.begin(), vector.end(), 0)};
    int max{*std::ranges::max_element(vector)}; // returns an iterator pointing to the maximum value so we need to dereference it
    int min{*std::ranges::min_element(vector)};

    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Results:" << std::endl;
    std::cout << "Sum:" << sum << std::endl;
    std::cout << "Min:" <<  min << std::endl;
    std::cout << "Max:" << max << std::endl;
}

int* allocateArray(int length)
{
    // I also removed 'const' because since we are already passing the variable 'length' by copy and not reference then the original either 
    // way wont be modified since we will be working on the copy. if we were to be passing it by reference and we dont want the original
    // to be modified then yes we would need the const
    auto* temp = new int[length]; // it was not returning a pointer and was not dynamically allocating memory using new
    return temp;
}