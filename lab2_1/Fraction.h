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

    // Ініціалізація
    void Init(int f, int s);

    // Введення та виведення
    void Read();
    void Display() const;

    // Приведення до рядка
    std::string toString() const;

    // Оператор присвоєння
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

// **Оголошення makeFraction тут**
Fraction makeFraction(int f, int s);

#endif
