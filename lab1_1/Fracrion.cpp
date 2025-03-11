#include "Fraction.h"

// Конструктор з параметрами
Fraction::Fraction(int numerator, int denominator)
{
    Init(numerator, denominator);
}

// Встановлення чисельника
void Fraction::setFirst(int value)
{
    if (value > 0)
    {
        first = value;
    }
    else
    {
        cerr << "Error: Numerator must be positive." << endl;
        exit(1);
    }
}

// Встановлення знаменника
void Fraction::setSecond(int value)
{
    if (value > 0)
    {
        second = value;
    }
    else
    {
        cerr << "Error: Denominator must be positive and non-zero." << endl;
        exit(1);
    }
}

// Метод ініціалізації
bool Fraction::Init(int numerator, int denominator)
{
    if (numerator > 0 && denominator > 0)
    {
        first = numerator;
        second = denominator;
        return true;
    }
    else
    {
        cerr << "Error: Invalid values for fraction." << endl;
        return false;
    }
}

// Метод введення
void Fraction::Read()
{
    int numerator, denominator;
    do
    {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
    } while (!Init(numerator, denominator));
}

// Метод виведення
void Fraction::Display() const
{
    cout << first << " / " << second << endl;
}

// Виділення цілої частини
int Fraction::ipart() const
{
    return first / second;
}

// Функція створення об'єкта класу
Fraction makeFraction(int numerator, int denominator)
{
    Fraction f;
    if (!f.Init(numerator, denominator))
    {
        cerr << "Error: Failed to create fraction." << endl;
    }
    return f;
}
