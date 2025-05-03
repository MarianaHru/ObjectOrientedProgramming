// Array.cpp
#include "Array.h"
#include <stdexcept>
#include <iostream>

Array::Array(int n, unsigned char val)
{
    if (n < 0 || n > MAX_SIZE)
    {
        throw std::out_of_range("Invalid array size");
    }
    size = n;
    for (int i = 0; i < size; ++i)
    {
        data[i] = val;
    }
}

int Array::getSize() const
{
    return size;
}

bool Array::rangeCheck(int index) const
{
    return index >= 0 && index < size;
}

unsigned char &Array::operator[](int index)
{
    if (!rangeCheck(index))
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const unsigned char &Array::operator[](int index) const
{
    if (!rangeCheck(index))
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

Array *Array::add(const Array &other) const
{
    if (getSize() != other.getSize())
    {
        throw std::invalid_argument("Arrays must be the same size to add");
    }

    Array *result = new Array(getSize());
    for (int i = 0; i < getSize(); ++i)
    {
        (*result)[i] = (this->operator[](i) + other[i]) % 256;
    }

    return result;
}

Array *Array::subtract(const Array &other) const
{
    throw std::logic_error("subtract() must be overridden in derived class");
}

Array *Array::multiply(const Array &other) const
{
    throw std::logic_error("multiply() must be overridden in derived class");
}

Array *Array::divide(const Array &other) const
{
    throw std::logic_error("divide() must be overridden in derived class");
}

void Array::print() const
{
    throw std::logic_error("print() must be overridden in derived class");
}

int Array::compare(const Array &other) const
{
    throw std::logic_error("compare() must be overridden in derived class");
}
