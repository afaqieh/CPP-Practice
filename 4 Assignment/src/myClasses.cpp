#include <iostream>
#include <algorithm>
#include "myClasses.hh"

bool Book::checkAvailability()
{
    if (bookName == "" || author == "" || ISBN == "")
    {
        return false;
    }
    else
        return true;

}

void Book::printInformation()
{
    bool available{checkAvailability()};
    if (available == true)
    {
        std::cout << "Title: " << bookName << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << ISBN << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "One of the entries of the book is missing and cannot be left empty" << std::endl;
    }
}

bool Book::requestValidity()
{
    bool result{checkValidity()};
    return result;

}

bool Book::checkValidity()
{
    bool available{checkAvailability()};
    if (available == true)
    {
        ISBN.erase(std::remove(ISBN.begin(), ISBN.end(), '-'), ISBN.end());
        
        auto validity{0};
        for (int i = 0; i < 10; ++i)
        {
            if (!isdigit(ISBN[i])) {
                std::cout << "Invalid ISBN: contains non-numeric characters!" << std::endl;
                isValid = false;
                return isValid;
            }

            int number = std::stoi(ISBN.substr(i,1));
            auto result{(i+1) * number};
            validity += result;
        }
        if (validity % 11 == 0)
        {
            isValid = true;
            std::cout << "ISBN is valid!" << std::endl;
            return isValid;
        }
        else
        {
            std::cout << "ISBN is not valid!" << std::endl;
            isValid = false;
            return isValid;
        }
    }
    else 
    {
        std::cout << "One of the entries of the book is missing and cannot be left empty" << std::endl;
        isValid = false;
        return isValid;
    }
}

void Library::addBook(const Book& book)
{
    library.push_back(book);
}

void Library::cleanUp()
{
    std::vector<int> invalidBooks;
    for (int i = 0; i < library.size(); ++i)
    {
        auto result{library[i].requestValidity()};
        if (result == false)
        {
            invalidBooks.push_back(i);
        }

    }
    deleteBook(invalidBooks);
}

void Library::deleteBook(std::vector<int> invalid)
{
    // descending order to prevent shifting issues
    std::sort(invalid.rbegin(), invalid.rend());

    for (int index : invalid) 
    {
        if (index >= 0 && index < library.size()) {  // Ensure index is valid
            library.erase(library.begin() + index);
        }
    }
}

void Library::printInventory()
{
    for (Book book: library)
    {
        book.printInformation();
    }
}