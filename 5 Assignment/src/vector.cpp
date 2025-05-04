#include <iostream>
#include "vector.hh"


Vector::Vector(const int& size)
{
    m_data = new int[size];
    for (int i = 0; i < size; ++i)
    {
        m_data[i] = 0;
    }
    m_size = size;
}

Vector::Vector(const int& size, const int& value)
{
    m_data = new int[size];
    for (int i = 0; i < size; ++i)
    {
        m_data[i] = value;
    }
    m_size = size;
}

Vector::Vector(const Vector& other)
{
    m_size = other.m_size;
    m_data = new int[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        m_data[i] = other.m_data[i];
    }
}

Vector::Vector(Vector&& other) noexcept
{
    m_size = other.m_size;
    m_data = other.m_data;

    other.m_data = nullptr;
    other.m_size = 0;
}


int Vector::size() const
{
    return m_size;
}

int Vector::at(const int& index) const
{
    if (index < 0 || index >= m_size)
    {
        std::cout << "Warning: Index out of range!" << std::endl;
        return -1; 
    }
    return m_data[index];
}

void Vector::pop_back()
{
    m_size -= 1;
    auto* newArray = new int[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        newArray[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newArray;
}

void Vector::push_back(const int& value)
{
    m_size += 1;
    auto* newArray = new int[m_size];
    for (int i = 0; i < m_size - 1; ++i)
    {
        newArray[i] = m_data[i];
    }
    newArray[m_size - 1] = value;
    delete[] m_data;
    m_data = newArray;
}

void Vector::clear()
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
}

Vector::~Vector()
{
    if (m_data != nullptr)
    {
        delete[] m_data;
        m_data = nullptr;
    }
}
