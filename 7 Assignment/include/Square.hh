#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.hh"

/**
 * @class Square
 * @brief Represents a square shape, derived from the Shape base class.
 */
class Square: public Shape
{
    public:
        /**
         * @brief Constructs a Square object with the specified side length.
         * @param sideLength The length of one side of the square.
         */
        explicit Square(double sideLength): Shape("Square"), sideLength(sideLength){};

        /**
         * @brief Calculates and returns the area of the square.
         * @return The area of the square.
         */
        double getArea() override;

        /**
         * @brief Calculates and returns the circumference of the square.
         * @return The circumference of the square.
         */
        double getCircumference() override;

        /**
         * @brief Destructor for the Square class.
         */
        ~Square() override;

    private:
        /**
         * @brief The length of one side of the square.
         */
        double sideLength{0};
};

#endif