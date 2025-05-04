#include <iostream>
#include "vector.hh"

int main()
{
    std::cout << "****************************" << std::endl;
    std::cout << "******** VECTOR TEST *******" << std::endl;
    std::cout << "****************************\n" << std::endl;

    // 1) Initialisation
    Vector v1;                      // empty vector
    Vector v2(100);                 // vector with 100 elements initialised to 0!
    Vector v3(100, 42);             // vector with 100 elements initialised to 42!

    std::cout << "v1 has size " << v1.size() << std::endl;
    std::cout << "v2 has size " << v2.size() << std::endl;
    std::cout << "v3 has size " << v3.size() << "\n" << std::endl;

    // 2) Element access
    std::cout << "v1 contains value: " << v1.at(0) << std::endl;         // --> warning!
    std::cout << "v2 contains value: " << v2.at(0) << std::endl;
    std::cout << "v3 contains value: " << v3.at(0) << "\n" << std::endl;
    std::cout << "v3 contains value: " << v3.at(142) << "\n" << std::endl; // --> warning!

    // 3) Add Element
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    std::cout << "\n" << "v1 has size " << v1.size() << " and contains: " << std::endl;
    for (int i = 0; i < v1.size(); ++i)
    {
        std::cout << i << ": " << v1.at(i) << std::endl;
    }

    // 4) Remove Element
    v1.pop_back();
    v1.pop_back();

    std::cout << "\n" << "v1 has size " << v1.size() << " and contains: " << std::endl;
    for (int i = 0; i < v1.size(); ++i)
    {
        std::cout << i << ": " << v1.at(i) << std::endl;
    }

    // 4) Clear Elements
    v1.clear();
    std::cout << "\n" << "v1 has size " << v1.size() << std::endl;

    // 5) Check Copy Constructor
    Vector vCopy(v3);
    std::cout << "vCopy has size " << vCopy.size() << "\n" << std::endl;
    std::cout << "vCopy contains value: " << vCopy.at(0) << "\n" << std::endl;

    // 6) Check Move Constructor
    Vector vMove = std::move(v3);
    std::cout << "vMove has size " << vMove.size() << "\n" << std::endl;
    std::cout << "vMove contains value: " << vMove.at(0) << "\n" << std::endl;

    std::cout << "v3 has size " << v3.size() << "\n" << std::endl;

    std::cout << "****************************" << std::endl;
    std::cout << "***** VECTOR TEST PASSED *****" << std::endl;
    std::cout << "****************************" << std::endl;

    return 0;
}