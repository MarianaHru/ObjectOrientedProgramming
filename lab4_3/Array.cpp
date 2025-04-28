// Array.cpp
#include "Array.h"

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
