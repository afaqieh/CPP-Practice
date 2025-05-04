#ifndef accessSpecifier_H
#define accessSpecifier_H
#include <iostream>

// 2.4

/**
 * @class A
 * @brief Class A demonstrates encapsulation with a private member and a public accessor.
 */
class A {
    public:
        /**
         * @brief Constructor that initializes m_A to 42 and prints a message.
         */
        A() : m_A(42) {
            std::cout << "A()\n";
        }
    
        /**
         * @brief Prints the value of m_A.
         */
        void showA() const {
            std::cout << "m_A = " << m_A << '\n';
        }
    
    private:
        int m_A; ///< Private integer member variable
};

/**
 * @class B
 * @brief Publicly inherits from A and provides access to A's functionality.
 */
class B : public A {
    public:
        /**
         * @brief Constructor that prints a message.
         */
        B() {
            std::cout << "B()\n";
        }
    
        /**
         * @brief Calls the public method showA() from class A.
         */
        void accessA() {
            showA(); // Allowed: accessing through A's public function
        }
};

/**
 * @class C
 * @brief Privately inherits from B, hiding B's public members from external access.
 */
class C : private B {
    public:
        /**
         * @brief Constructor that prints a message.
         * @note accessA() is not accessible here due to private inheritance.
         */
        C() {
            std::cout << "C()\n";
            // accessA(); Not allowed: B's public becomes private here
        }
};

/*
B inherits from A publicly, so it can access A’s public members (like showA()), but not private data directly.
C inherits from B privately, so all public members of B become private in C, making them inaccessible from C.

There are two possible solutions to ensure that class B has access to m_A from class A, but class C does not. The first solution is to keep m_A private in 
class A and provide a public method like showA() that class B can use to access it. Then, class C inherits privately from B, which hides B’s public interface 
from C, effectively preventing C from accessing A’s data. The second solution is to declare m_A as protected in class A, allowing B to access it directly, and 
again use private inheritance from B to C to block further access. While both approaches work, the first solution is preferable because it preserves encapsulation.
*/

#endif