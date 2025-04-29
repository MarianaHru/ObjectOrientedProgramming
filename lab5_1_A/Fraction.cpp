// #include "Fraction.h"
// #include <sstream>

// // Конструктори
// Fraction::Fraction() noexcept : first(0), second(1) {}

// Fraction::Fraction(int f, int s) throw(std::invalid_argument, FractionException, OwnException)
// {
//     Init(f, s);
// }

// Fraction::Fraction(const Fraction &other) noexcept : first(other.first), second(other.second) {}

// // Методи доступу
// int Fraction::getFirst() const noexcept { return first; }
// int Fraction::getSecond() const noexcept { return second; }

// void Fraction::setFirst(int f) noexcept { first = f; }

// void Fraction::setSecond(int s) throw(std::invalid_argument)
// {
//     if (s == 0)
//         throw std::invalid_argument("Знаменник не може бути нулем (передача за значенням)!");
//     second = s;
// }

// void Fraction::Init(int f, int s) throw(std::invalid_argument, FractionException, OwnException)
// {
//     if (s == 0)
//     {
//         if (f < 0)
//             throw FractionException("Неправильні дані: чисельник від'ємний, знаменник нуль (передача за посиланням).");
//         else
//             throw OwnException("Помилка: знаменник не може бути нулем (передача за вказівником)!");
//     }
//     first = f;
//     second = s;
// }

// int Fraction::ipart() const throw(std::bad_exception)
// {
//     if (second == 0)
//     {
//         throw std::bad_exception(); // Демонструємо стандартний виняток
//     }
//     return first / second;
// }

// Fraction::operator std::string() const noexcept
// {
//     std::ostringstream oss;
//     oss << first << "/" << second;
//     return oss.str();
// }

// Fraction &Fraction::operator=(const Fraction &other) noexcept
// {
//     if (this != &other)
//     {
//         first = other.first;
//         second = other.second;
//     }
//     return *this;
// }

// // Оператори інкременту та декременту
// Fraction &Fraction::operator++() noexcept
// {
//     ++first;
//     return *this;
// }

// Fraction Fraction::operator++(int) noexcept
// {
//     Fraction temp = *this;
//     ++first; // Виправлено: інкрементуємо чисельник
//     return temp;
// }

// Fraction &Fraction::operator--() noexcept
// {
//     --first;
//     return *this;
// }

// Fraction Fraction::operator--(int) noexcept
// {
//     Fraction temp = *this;
//     --first; // Виправлено: декрементуємо чисельник
//     return temp;
// }

// // Дружні оператори введення/виведення
// std::ostream &operator<<(std::ostream &out, const Fraction &f)
// {
//     out << static_cast<std::string>(f);
//     return out;
// }

// std::istream &operator>>(std::istream &in, Fraction &f)
// {
//     std::string input;
//     in >> input;
//     std::istringstream iss(input);
//     int num, denom;
//     char slash;
//     if (iss >> num >> slash >> denom && slash == '/')
//     {
//         f.Init(num, denom);
//     }
//     else
//     {
//         throw std::invalid_argument("Невірний формат дробу. Використовуйте формат a/b.");
//     }
//     return in;
// }

// Fraction makeFraction(int f, int s) throw(std::invalid_argument, FractionException, OwnException)
// {
//     return Fraction(f, s);
// }
#include "Fraction.h"
#include <sstream>

// Конструктори
Fraction::Fraction() noexcept : first(0), second(1) {}

Fraction::Fraction(int f, int s) noexcept(false)
{
    first = f;  // Просто присвоюємо значення
    second = s; // Просто присвоюємо значення
    if (second == 0)
    {
        throw std::invalid_argument("Знаменник не може бути нулем (передача за значенням)!");
    }
}

Fraction::Fraction(const Fraction &other) noexcept : first(other.first), second(other.second) {}

// Методи доступу
int Fraction::getFirst() const noexcept { return first; }
int Fraction::getSecond() const noexcept { return second; }

void Fraction::setFirst(int f) noexcept { first = f; }

void Fraction::setSecond(int s) noexcept(false)
{
    if (s == 0)
        throw std::invalid_argument("Знаменник не може бути нулем (передача за значенням)!");
    second = s;
}

void Fraction::Init(int f, int s) noexcept(false)
{
    if (s == 0)
    {
        if (f < 0)
            throw FractionException("Неправильні дані: чисельник від'ємний, знаменник нуль (передача за посиланням).");
        else
            throw FractionException("Знаменник не може бути нулем (Init).");
    }
    first = f;
    second = s;
}
int Fraction::ipart() const noexcept(false)
{
    if (second == 0)
    {
        throw std::bad_exception(); // Використовуємо стандартний виняток
    }
    return first / second;
}

Fraction::operator std::string() const noexcept
{
    std::ostringstream oss;
    oss << first << "/" << second;
    return oss.str();
}

Fraction &Fraction::operator=(const Fraction &other) noexcept
{
    if (this != &other)
    {
        first = other.first;
        second = other.second;
    }
    return *this;
}
Fraction &Fraction::operator++() noexcept
{

    this->first += this->second;
    return *this;
}

Fraction Fraction::operator++(int) noexcept
{
    Fraction temp = *this;

    this->first += this->second;
    return temp;
}

Fraction &Fraction::operator--() noexcept
{

    this->first -= this->second;
    return *this;
}

Fraction Fraction::operator--(int) noexcept
{
    Fraction temp = *this;

    this->first -= this->second;
    return temp;
}

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

Fraction makeFraction(int f, int s) noexcept(false)
{
    return Fraction(f, s);
}
