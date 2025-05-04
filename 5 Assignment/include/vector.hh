#ifndef VECTOR_H
#define VECTOR_H

/**
 * @class Vector
 * @brief A simple dynamic array implementation for integers.
 */
class Vector
{
    public:
        /**
         * @brief Default constructor. Creates an empty vector.
         */
        Vector() = default;

        /**
         * @brief Constructs a vector of a given size, initializing all elements to 0.
         * @param size The size of the vector.
         */
        explicit Vector(const int& size);

        /**
         * @brief Constructs a vector of a given size and initializes all elements with a specific value.
         * @param size The size of the vector.
         * @param value The value to initialize all elements with.
         */
        Vector(const int& size, const int& value);

        /**
         * @brief Copy constructor. Performs a deep copy.
         * @param other The vector to copy from.
         */
        Vector(const Vector& other);

        /**
         * @brief Move constructor. Transfers ownership of data from another vector.
         * @param other The vector to move from.
         */
        Vector(Vector&& other) noexcept;

        /**
         * @brief Returns the number of elements in the vector.
         * @return The size of the vector.
         */
        int size() const;

        /**
         * @brief Accesses the element at the specified index.
         * @param index The index of the element.
         * @return The value at the specified index.
         * @warning Prints a warning if the index is out of bounds.
         */
        int at(const int& index) const;

        /**
         * @brief Adds a new element to the end of the vector.
         * @param value The value to add.
         */
        void push_back(const int& value);

        /**
         * @brief Removes the last element of the vector.
         */
        void pop_back();

        /**
         * @brief Clears the contents of the vector.
         */
        void clear();

        /**
         * @brief Destructor. Frees dynamically allocated memory.
         */
        ~Vector();

    private:
        int* m_data{nullptr}; ///< Pointer to the dynamically allocated array.
        int m_size{0};        ///< Number of elements currently in the vector.
};

#endif