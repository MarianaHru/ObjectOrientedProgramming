#ifndef DECIMAL_H
#define DECIMAL_H

#include "Array.h"

class Decimal : public Array
{
public:
    Decimal(int n = 0, unsigned char val = 0);

    Array *add(const Array &other) const override;
    Array *subtract(const Array &other) const override;
    Array *multiply(const Array &other) const override;
    Array *divide(const Array &other) const override;
    void print() const override;
    int compare(const Array &other) const override;
};

#endif
