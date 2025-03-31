#include "Fraction.h"
#include <iostream>
#include <sstream>

// Конструктори
Fraction::Fraction() : first(0), second(1) {}
Fraction::Fraction(int f, int s) { Init(f, s); }
Fraction::Fraction(const Fraction &other) : first(other.first), second(other.second) {}

// Методи доступу
int Fraction::getFirst() const { return first; }
int Fraction::getSecond() const { return second; }
void Fraction::setFirst(int f) { first = f; }
void Fraction::setSecond(int s) { second = s; }

void Fraction::Init(int f, int s)
{
    if (s == 0)
    {
        throw std::invalid_argument("Помилка: знаменник не може бути 0!");
    }
    first = f;
    second = s;
}

Fraction::operator std::string() const
{
    std::ostringstream oss;
    oss << first << "/" << second;
    return oss.str();
}

Fraction &Fraction::operator=(const Fraction &other)
{
    if (this != &other)
    {
        first = other.first;
        second = other.second;
    }
    return *this;
}

// Оператори інкременту та декременту
Fraction &Fraction::operator++()
{
    ++first;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp = *this;
    ++second;
    return temp;
}

Fraction &Fraction::operator--()
{
    --first;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp = *this;
    --second;
    return temp;
}

// Дружні оператори введення/виведення
std::ostream &operator<<(std::ostream &out, const Fraction &f)
{
    out << static_cast<std::string>(f);
    return out;
}

std::istream &operator>>(std::istream &in, Fraction &f)
{
    std::string input;
    in >> input;
    std::istringstream iss(input);
    int num, denom;
    char slash;
    if (iss >> num >> slash >> denom && slash == '/')
    {
        f.Init(num, denom);
    }
    else
    {
        throw std::invalid_argument("Невірний формат дробу. Використовуйте формат a/b.");
    }
    return in;
}

Fraction makeFraction(int f, int s)
{
    return Fraction(f, s);
}
