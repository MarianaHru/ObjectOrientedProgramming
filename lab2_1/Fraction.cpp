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

// Метод ініціалізації
void Fraction::Init(int f, int s)
{
    if (s == 0)
    {
        std::cerr << "Помилка: знаменник не може бути 0!" << std::endl;
        exit(1);
    }
    first = f;
    second = s;
}

// Введення та виведення
void Fraction::Read()
{
    int f, s;
    std::cout << "Введіть чисельник: ";
    std::cin >> f;
    std::cout << "Введіть знаменник: ";
    std::cin >> s;
    Init(f, s);
}

void Fraction::Display() const
{
    std::cout << first << "/" << second << std::endl;
}

// Приведення до рядка
std::string Fraction::toString() const
{
    std::ostringstream oss;
    oss << first << "/" << second;
    return oss.str();
}

// Оператор присвоєння
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
    out << f.first << "/" << f.second;
    return out;
}

std::istream &operator>>(std::istream &in, Fraction &f)
{
    int a, b;
    std::cout << "Введіть чисельник: ";
    in >> a;
    std::cout << "Введіть знаменник: ";
    in >> b;
    f.Init(a, b);
    return in;
}

// **Тепер функція makeFraction визначена тут**
Fraction makeFraction(int f, int s)
{
    if (s == 0)
    {
        std::cerr << "Помилка: знаменник не може бути 0!" << std::endl;
        exit(1);
    }
    return Fraction(f, s);
}
