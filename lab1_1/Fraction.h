// Fraction.h
#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
    int first;  // Чисельник (додатне число)
    int second; // Знаменник (додатне число, не нуль)

public:
    // Конструктор за замовчуванням
    Fraction() : first(1), second(1) {}

    // Конструктор з параметрами
    Fraction(int numerator, int denominator);

    // Методи доступу
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    void setFirst(int value);
    void setSecond(int value);

    // Метод ініціалізації
    bool Init(int numerator, int denominator);

    // Методи введення та виведення
    void Read();
    void Display() const;

    // Метод виділення цілої частини дробу
    int ipart() const;
};

// Функція створення об'єкта класу
Fraction makeFraction(int numerator, int denominator);