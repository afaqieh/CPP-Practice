#ifndef CIRCLE_H
#define CIRCLE_H
#include <numbers>
#include "Shape.hh"

/**
 * @class Circle
 * @brief Represents a circle shape, derived from the Shape base class.
 */
class Circle: public Shape
{
    public:
        /**
         * @brief Constructs a Circle object with the specified radius.
         * @param radius The radius of the circle.
         */
        explicit Circle(double radius): Shape("Circle"), radius(radius){};

        /**
         * @brief Calculates and returns the area of the circle.
         * @return The area of the circle.
         */
        double getArea() override;

        /**
         * @brief Calculates and returns the circumference of the circle.
         * @return The circumference of the circle.
         */
        double getCircumference() override;

        /**
         * @brief Destructor for the Circle class.
         */
        ~Circle() override;

    private:
        /**
         * @brief The value of π (pi) used for calculations.
         */
        double pi{std::numbers::pi};

        /**
         * @brief The radius of the circle.
         */
        double radius{0};
};

#endif