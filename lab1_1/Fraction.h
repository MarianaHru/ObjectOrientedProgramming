// Fraction.h
#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
    int first;
    int second;

public:
    // Конструктор за замовчуванням
    Fraction() : first(1), second(1) {}

    // Конструктор з параметрами
    Fraction(int numerator, int denominator);

    // Методи доступу
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    bool setFirst(int value);
    bool setSecond(int value);

    bool Init(int numerator, int denominator);

    void Read();
    void Display() const;

    int ipart() const;
};

// Функція створення об'єкта класу
Fraction makeFraction(int numerator, int denominator);