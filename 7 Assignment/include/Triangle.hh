#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.hh"

/**
 * @class Triangle
 * @brief Represents an isosceles triangle, derived from the Shape base class.
 * 
 * This class is marked as final, meaning it cannot be inherited from.
 */
class Triangle final: public Shape
{
    public:
        /**
         * @brief Constructs a Triangle with a given base and height.
         * @param base The length of the base of the triangle.
         * @param height The height from the base to the top vertex.
         */
        Triangle(double base, double height):
            Shape("Triangle"),
            base(base),
            height(height)
            {};

        /**
         * @brief Calculates and returns the area of the triangle.
         * @return The area of the triangle.
         */
        double getArea() override;

        /**
         * @brief Calculates and returns the circumference of the triangle.
         * @return The circumference of the triangle.
         */
        double getCircumference() override;

        /**
         * @brief Destructor for the Triangle class.
         */
        ~Triangle() override;

    private:
        /**
         * @brief The length of the base of the triangle.
         */
        double base{0};

        /**
         * @brief The height from the base to the top vertex.
         */
        double height{0};

        /**
         * @brief The length of the two equal sides of the isosceles triangle.
         */
        double equalSide{0};
};

#endif