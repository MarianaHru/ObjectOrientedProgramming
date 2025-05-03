// BitString.cpp
#include "BitString.h"
#include <iostream>
#include <stdexcept>

BitString::BitString(int n, unsigned char val) : Array(n, val % 2) {} // зберігаємо тільки 0 або 1

// Побітова OR (add)
Array *BitString::add(const Array &other) const
{
    if (getSize() != other.getSize())
        throw std::invalid_argument("BitString: size mismatch for OR");

    BitString *result = new BitString(getSize());
    for (int i = 0; i < getSize(); ++i)
        (*result)[i] = ((*this)[i] | other[i]) & 1;

    return result;
}

// Побітова AND (subtract)
Array *BitString::subtract(const Array &other) const
{
    if (getSize() != other.getSize())
        throw std::invalid_argument("BitString: size mismatch for AND");

    BitString *result = new BitString(getSize());
    for (int i = 0; i < getSize(); ++i)
        (*result)[i] = ((*this)[i] & other[i]) & 1;

    return result;
}

// Побітова XOR (multiply)
Array *BitString::multiply(const Array &other) const
{
    if (getSize() != other.getSize())
        throw std::invalid_argument("BitString: size mismatch for XOR");

    BitString *result = new BitString(getSize());
    for (int i = 0; i < getSize(); ++i)
        (*result)[i] = ((*this)[i] ^ other[i]) & 1;

    return result;
}

// Побітова NOT (унарна, other ігнорується)
Array *BitString::divide(const Array & /*other*/) const
{
    BitString *result = new BitString(getSize());
    for (int i = 0; i < getSize(); ++i)
        (*result)[i] = (~(*this)[i]) & 1;

    return result;
}

// Зсув вліво
void BitString::leftShift(int bits)
{
    if (bits <= 0 || bits >= getSize())
        return;

    for (int i = getSize() - 1; i >= bits; --i)
        (*this)[i] = (*this)[i - bits];

    for (int i = 0; i < bits; ++i)
        (*this)[i] = 0;
}

// Зсув вправо
void BitString::rightShift(int bits)
{
    if (bits <= 0 || bits >= getSize())
        return;

    for (int i = 0; i < getSize() - bits; ++i)
        (*this)[i] = (*this)[i + bits];

    for (int i = getSize() - bits; i < getSize(); ++i)
        (*this)[i] = 0;
}

void BitString::print() const
{
    for (int i = getSize() - 1; i >= 0; --i)
        std::cout << (int)((*this)[i] & 1);
    std::cout << std::endl;
}

int BitString::compare(const Array &other) const
{
    for (int i = getSize() - 1; i >= 0; --i)
    {
        int a = (*this)[i] & 1;
        int b = other[i] & 1;
        if (a != b)
            return a - b;
    }
    return 0;
}
