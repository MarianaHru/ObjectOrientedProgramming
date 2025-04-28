// Decimal.cpp
#include "Decimal.h"
#include <iostream>

Decimal::Decimal(int n, unsigned char val) : Array(n, val) {}

Array *Decimal::add(const Array &other) const
{
    if (getSize() != other.getSize())
    {
        throw std::invalid_argument("Decimal: size mismatch for addition");
    }

    Decimal *result = new Decimal(getSize());
    int carry = 0;

    for (int i = getSize() - 1; i >= 0; --i)
    {
        int sum = (*this)[i] + other[i] + carry;
        (*result)[i] = sum % 10;
        carry = sum / 10;
    }

    return result;
}

Array *Decimal::subtract(const Array &other) const
{
    throw std::logic_error("Decimal::subtract not implemented");
}

Array *Decimal::multiply(const Array &other) const
{
    throw std::logic_error("Decimal::multiply not implemented");
}

Array *Decimal::divide(const Array &other) const
{
    throw std::logic_error("Decimal::divide not implemented");
}

void Decimal::print() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << (int)data[i];
    }
    std::cout << std::endl;
}

int Decimal::compare(const Array &other) const
{
    if (getSize() != other.getSize())
        return getSize() - other.getSize();

    for (int i = 0; i < getSize(); ++i)
    {
        if ((*this)[i] != other[i])
        {
            return (*this)[i] - other[i];
        }
    }
    return 0;
}
