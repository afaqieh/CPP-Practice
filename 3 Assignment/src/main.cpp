#include <iostream>
#include "myfunctions.hh"

int main()
{
    SumMinMaxUnsafeArrays();
    SumMinMaxSmartPointer();
    SumMinMaxSTL();

    /*
    Exercise 2.2 "What's Wrong here:"
    1.  we can replace the first int with auto
    2.  we should also set our pointer equal to a nullptr after deleting
    3.  the main issue, however, is in the line code 'pointToAnInt = 9;'
        We first create a pointer in order to allocate new memory that can store an integer value but then instead of having it store the value of 9, we 
        instead change the pointer itself to hold 9 as an address which is not valued and will lead to a crash. This means that we also lose the memory allocated 
        place that we created. To fix this, we instead need to do: '*pointToAnInt = 9;' which changes the value at that address.
    */

    /*
    "Why and were does the program crash?"
    1.  the line code 'int pointToAnInt = new int;' because it is supposed to return a pointer but we are setting it equal to a normal int variable
    2.  Another issue is that both "pointers" (if we were to fix the above issue) point towards the same memory location and we are trying to free the same
    memory location twice
    */

    /*
    "Fix the function"
    */
    auto* arrayFixed = allocateArray(5);
    delete[] arrayFixed; // we need to free the memory after allocating it

    /*
    "Hoppla!"
    There are 2 main issues here which is that we allocate 5 spaces for the array size but we only use 4 and in this type of function we are only printing 
    out the values of the array and not trying to change anything so that extra memory is wasted. Another issue is that our for loop loops 6 times trying to
    print 6 values in our array when we only have 4. This will lead to printing 'garbage data'. To fix this we can loop 4 times instead.
    */
    std::cout << std::endl;
    int array[4]{0,1,2,3};
    for (int count = 0; count < 4; ++count)
    {
        std::cout << array[count] << " ";
    }

    return 0;
}