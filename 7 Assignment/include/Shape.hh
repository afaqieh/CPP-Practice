#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

/**
 * @class Shape
 * @brief Abstract base class for geometric shapes.
 */
class Shape
{
    public:
        /**
         * @brief Constructs a Shape with a specified type name.
         * @param Type The name of the shape (e.g., "Circle", "Square").
         */
        explicit Shape(const std::string& Type): name(Type){};

        /**
         * @brief Computes and returns the area of the shape.
         * @return The area of the shape.
         */
        virtual double getArea();

        /**
         * @brief Computes and returns the circumference of the shape.
         * @return The circumference of the shape.
         */
        virtual double getCircumference();

        /**
         * @brief Virtual destructor for the Shape class.
         */
        virtual ~Shape();

        /**
         * @brief Outputs the shape's type, area, and circumference.
         */
        void report();

    private:
        /**
         * @brief Stores the type name of the shape.
         */
        std::string name{"Undefined shape"};
};

#endif