// Decimal.cpp
#include "Decimal.h"
#include <iostream>
#include <stdexcept>

Decimal::Decimal(int n, unsigned char val) : Array(n)
{
    for (int i = 0; i < n; ++i)
        (*this)[i] = val % 10; // кожна цифра від 0 до 9
}

// Сума з урахуванням переносу
Array *Decimal::add(const Array &other) const
{
    if (getSize() != other.getSize())
        throw std::invalid_argument("Decimal: size mismatch for addition");

    Decimal *result = new Decimal(getSize());
    int carry = 0;
    for (int i = 0; i < getSize(); ++i)
    {
        int sum = (*this)[i] + other[i] + carry;
        (*result)[i] = sum % 10;
        carry = sum / 10;
    }
    return result;
}

// Віднімання (без від’ємного результату)
Array *Decimal::subtract(const Array &other) const
{
    if (getSize() != other.getSize())
        throw std::invalid_argument("Decimal: size mismatch for subtraction");

    Decimal *result = new Decimal(getSize());
    int borrow = 0;
    for (int i = 0; i < getSize(); ++i)
    {
        int diff = (*this)[i] - other[i] - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        (*result)[i] = diff;
    }
    return result;
}

// Множення нацифру (простий алгоритм)
Array *Decimal::multiply(const Array &other) const
{
    if (getSize() != other.getSize())
        throw std::invalid_argument("Decimal: size mismatch for multiplication");

    Decimal *result = new Decimal(getSize());

    for (int i = 0; i < getSize(); ++i)
        for (int j = 0; j < getSize() && i + j < getSize(); ++j)
        {
            int product = (*result)[i + j] + (*this)[i] * other[j];
            (*result)[i + j] = product % 10;
            if (i + j + 1 < getSize())
                (*result)[i + j + 1] += product / 10;
        }

    return result;
}

// Ділення — поки що заглушка
Array *Decimal::divide(const Array & /*other*/) const
{
    throw std::logic_error("Decimal::divide not implemented");
}

void Decimal::print() const
{
    bool leadingZero = true;
    for (int i = getSize() - 1; i >= 0; --i)
    {
        if (leadingZero && (*this)[i] == 0)
            continue;

        leadingZero = false;
        std::cout << (int)(*this)[i];
    }

    if (leadingZero)
        std::cout << "0";

    std::cout << std::endl;
}

int Decimal::compare(const Array &other) const
{
    for (int i = getSize() - 1; i >= 0; --i)
    {
        if ((*this)[i] != other[i])
            return (*this)[i] - other[i];
    }
    return 0;
}
