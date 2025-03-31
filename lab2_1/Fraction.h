#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

class Fraction
{
private:
    int first;
    int second;

public:
    // Конструктори
    Fraction();
    Fraction(int f, int s);
    Fraction(const Fraction &other);

    // Методи доступу
    int getFirst() const;
    int getSecond() const;
    void setFirst(int f);
    void setSecond(int s);

    void Init(int f, int s);

    // Оператор приведення до рядка
    operator std::string() const;

    Fraction &operator=(const Fraction &other);

    // Оператори інкременту та декременту
    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--();
    Fraction operator--(int);

    // Дружні оператори введення/виведення
    friend std::ostream &operator<<(std::ostream &out, const Fraction &f);
    friend std::istream &operator>>(std::istream &in, Fraction &f);
};

Fraction makeFraction(int f, int s);

#endif
