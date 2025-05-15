#ifndef DECIMAL_H
#define DECIMAL_H

#include "Array.h"

class Decimal : public Array
{
public:
    // Конструктор з ініціалізацією
    Decimal(int n = 0, unsigned char val = 0);

    // Операції для масивів
    Array *add(const Array &other) const override;
    Array *subtract(const Array &other) const override;
    Array *multiply(const Array &other) const override;
    Array *divide(const Array &other) const override;

    // Виведення на екран
    void print() const override;

    // Порівняння масивів
    int compare(const Array &other) const override;

    // Дружні функції порівняння
    friend bool operator==(const Decimal &lhs, const Array &rhs);
    friend bool operator!=(const Decimal &lhs, const Array &rhs);
    friend bool operator>(const Decimal &lhs, const Array &rhs);
    friend bool operator<(const Decimal &lhs, const Array &rhs);
    friend bool operator>=(const Decimal &lhs, const Array &rhs);
    friend bool operator<=(const Decimal &lhs, const Array &rhs);
};

#endif
