#include <iostream>
#include <vector>
#include "Triangle.hh"
#include "Square.hh"
#include "Circle.hh"

int main()
{
    
    Triangle t1(1,2);
    Triangle t2(3,4);
    Triangle t3(5,6);
    Square s1(1);
    Square s2(2);
    Square s3(3);
    Circle c1(1);
    Circle c2(2);
    Circle c3(3);
    
    // 1) create one (!) suitable container with the appropriate type(s);
    // 2) add the above instances to that one container;
    std::vector<Shape*> Shapes = {&t1, &t2, &t3, &s1, &s2, &s3, &c1, &c2, &c3};

    // 3) loop over these instances in that container;
    for (Shape* element: Shapes)
    {
        // 4) in the loop, call the ‘report‘ member function on the current object
        element->report();
    }

    return 0;
}