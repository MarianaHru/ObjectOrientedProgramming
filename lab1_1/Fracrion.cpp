#include "Fraction.h"

// Конструктор з параметрами
Fraction::Fraction(int numerator, int denominator)
{
    Init(numerator, denominator);
}

// Встановлення чисельника
bool Fraction::setFirst(int value)
{
    if (value > 0)
    {
        first = value;
        return true;
    }
    else
    {
        cerr << "Error: Numerator must be positive." << endl;
        exit(1);
        return false;
    }
}

// Встановлення знаменника
bool Fraction::setSecond(int value)
{
    if (value > 0)
    {
        second = value;
        return true;
    }
    else
    {
        cerr << "Error: Denominator must be positive and non-zero." << endl;
        exit(1);
        return false;
    }
}

bool Fraction::Init(int numerator, int denominator)
{
    return setFirst(numerator) && setSecond(denominator);
}

// return hrn + "," + monets

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

Fraction makeFraction(int numerator, int denominator)
{
    Fraction f;
    if (!f.Init(numerator, denominator))
    {
        cerr << "Error: Failed to create fraction." << endl;
        exit(1);
    }
    return f;
}
