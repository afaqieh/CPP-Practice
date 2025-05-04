#include <iostream>
#include "ATM.hh"
#include "inheritence.hh"

int main()
{
    CheckingAccount myAccount(1000, 0.5); // initial amount and fee
    myAccount.credit(250);               // ok
    std::cout << myAccount.printBalance() << std::endl; // -> 1250

    myAccount.debit(1000);              // ok
    std::cout << myAccount.printBalance() << std::endl; // -> 249.5

    myAccount.debit(249.5);             // Warning: Not enough funds
    myAccount.debit(249);               // ok
    std::cout << myAccount.printBalance() << std::endl; // -> 0

    return 0;
}

/*
2.2a
the ouput is 
Base()
Derived()
Base()
~Base()
~Derived()
~Base()

When Derived d; is created, the Base constructor is called first (printing Base()), followed by the Derived constructor (printing Derived()). 
Then, Base b; is constructed, printing Base() again. Upon exiting main(), destructors are called in reverse order: first for b, printing ~Base(), 
then for d, where the base part is destroyed first (printing ~Base()), and finally the Derived destructor (printing ~Derived()), 
completing the object destruction process.
*/

/*
2.2b
the private member m_x is inaccessible so it wont compile.
*/