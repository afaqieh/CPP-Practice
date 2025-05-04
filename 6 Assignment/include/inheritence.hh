#ifndef inheritance_H
#define inheritance_H
#include <iostream>

// 2.3

/**
 * @class A
 * @brief A simple class with a constructor and destructor that prints messages.
 */
class A {
    public:
        /**
         * @brief Constructor that prints "A()".
         */
        A() { std::cout << "A()\n"; }

        /**
         * @brief Destructor that prints "~A()".
         */
        ~A() { std::cout << "~A()\n"; }
};

/**
 * @class B
 * @brief A simple class with a constructor and destructor that prints messages.
 */
class B {
    public:
        /**
         * @brief Constructor that prints "B()".
         */
        B() { std::cout << "B()\n"; }

        /**
         * @brief Destructor that prints "~B()".
         */
        ~B() { std::cout << "~B()\n"; }
};

/**
 * @class C
 * @brief A simple class with a constructor and destructor that prints messages.
 */
class C {
    public:
        /**
         * @brief Constructor that prints "C()".
         */
        C() { std::cout << "C()\n"; }

        /**
         * @brief Destructor that prints "~C()".
         */
        ~C() { std::cout << "~C()\n"; }
};

/**
 * @class ABC
 * @brief Inherits publicly from A, C, and B. Demonstrates the order of constructor and destructor calls.
 */
class ABC : public A, public C, public B {
    public:
        /**
         * @brief Constructor that prints "ABC()" after base class constructors.
         */
        ABC() { std::cout << "ABC()\n"; }

        /**
         * @brief Destructor that prints "~ABC()" before base class destructors.
         */
        ~ABC() { std::cout << "~ABC()\n"; }
};

/*
The above gives the following output:
A()
C()
B()
ABC()
~ABC()
~B()
~C()
~A()

When an object of class ABC is created, the constructors of its base classes are called in the order they are listed in the inheritance declaration—A, 
then C, then B—regardless of the order in any initializer list. After the base class constructors, the constructor of ABC itself is called. 
When the object goes out of scope, the destructors are called in the reverse order: first ~ABC(), then ~B(), ~C(), and finally ~A(). 
*/

#endif