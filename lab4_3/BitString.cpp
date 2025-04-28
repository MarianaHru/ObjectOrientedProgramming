// BitString.cpp
#include "BitString.h"
#include <iostream>

BitString::BitString(int n, unsigned char val) : Array(n, val) {}

Array *BitString::add(const Array &other) const
{
    if (getSize() != other.getSize())
    {
        throw std::invalid_argument("BitString: size mismatch for bitwise OR");
    }

    BitString *result = new BitString(getSize());
    for (int i = 0; i < getSize(); ++i)
    {
        (*result)[i] = ((*this)[i] | other[i]) & 1;
    }

    return result;
}

Array *BitString::subtract(const Array &other) const
{
    throw std::logic_error("BitString::subtract not implemented");
}

Array *BitString::multiply(const Array &other) const
{
    throw std::logic_error("BitString::multiply not implemented");
}

Array *BitString::divide(const Array &other) const
{
    throw std::logic_error("BitString::divide not implemented");
}

void BitString::print() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << (int)(data[i] & 1);
    }
    std::cout << std::endl;
}

int BitString::compare(const Array &other) const
{
    if (getSize() != other.getSize())
        return getSize() - other.getSize();

    for (int i = 0; i < getSize(); ++i)
    {
        if (((*this)[i] & 1) != (other[i] & 1))
        {
            return ((*this)[i] & 1) - (other[i] & 1);
        }
    }
    return 0;
}
