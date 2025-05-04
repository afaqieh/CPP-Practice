#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <vector>

/**
 * @class Book
 * @brief Represents a book with a title, author, and ISBN.
 */
class Book
{
    public:
        /**
         * @brief Constructs a new Book object.
         * @param bookName_ The title of the book.
         * @param author_ The author's name.
         * @param ISBN_ The ISBN number.
         */
        Book(const std::string& bookName_, const std::string& author_, const std::string& ISBN_):
        bookName(bookName_), ///< The title of the book.
        author(author_),   ///< The author's name.
        ISBN(ISBN_)
        {}

        /**
         * @brief Checks if the book is valid.
         * @return True if valid, false otherwise.
         */
        bool requestValidity();

        /**
         * @brief Prints book details including title, author, and ISBN.
         */
        void printInformation();

    private:
        std::string bookName; ///< The title of the book.
        std::string author;   ///< The author's name.
        std::string ISBN;     ///< The ISBN number.

        /**
         * @brief Checks if the book has a title, author, and ISBN.
         * @return True if all fields are filled, false otherwise.
         */
        bool checkAvailability();

        /**
         * @brief Validates the ISBN number.
         * @return True if ISBN is valid, false otherwise.
         */
        bool checkValidity();

        bool isValid; ///< Stores whether the book is valid.
};

/**
 * @class Library
 * @brief Manages a collection of books.
 */
class Library
{
    public:
        /**
         * @brief Adds a book to the library.
         * @param book The book to be added.
         */
        void addBook(const Book& book);

        /**
         * @brief Removes invalid books from the library.
         */
        void cleanUp();

        /**
         * @brief Prints the inventory of books in the library.
         */
        void printInventory();

    private:
        std::vector<Book> library; ///< Collection of books in the library.

        /**
         * @brief Deletes books at specified indices.
         * @param invalid A list of indices corresponding to books to be removed.
         */
        void deleteBook(std::vector<int> invalid);
};

#endif // CLASSES_H