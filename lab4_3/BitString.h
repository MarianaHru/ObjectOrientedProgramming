// BitString.h
#ifndef BITSTRING_H
#define BITSTRING_H

#include "Array.h"

class BitString : public Array
{
public:
    BitString(int n = 0, unsigned char val = 0); // конструктор з ініціалізацією

    Array *add(const Array &other) const override;      // реалізує побітову OR
    Array *subtract(const Array &other) const override; // реалізує побітову AND
    Array *multiply(const Array &other) const override; // реалізує побітову XOR
    Array *divide(const Array &other) const override;   // реалізує побітову NOT (унарна, other ігнорується)

    void leftShift(int bits);  // зсув вліво
    void rightShift(int bits); // зсув вправо

    void print() const override;
    int compare(const Array &other) const override;
};

#endif
