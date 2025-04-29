#include "Money.h"
#include "MoneyException.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <iostream>

Money::Money() noexcept : hryvna(0), kopek(0) {}

Money::Money(long hryvna, unsigned char kopek) noexcept(false)
{
    this->hryvna = hryvna;
    if (!SetKopek(kopek))
    {
        throw MoneyException("Некоректне значення копійок у конструкторі");
    }
}

Money::Money(const Money &other) noexcept
    : hryvna(other.hryvna), kopek(other.kopek) {}

bool Money::SetKopek(unsigned char k) noexcept(false)
{
    if (k < 100)
    {
        kopek = k;
        return true;
    }
    throw std::invalid_argument("Копійки мають бути менші за 100"); // стандартний виняток
}

void Money::fromString(const std::string &s) noexcept(false)
{
    std::stringstream ss(s);
    char comma;
    int kop;
    std::string currency;

    if (!(ss >> hryvna >> comma >> kop))
    {
        throw std::invalid_argument("Невірний формат чисел"); // стандартний виняток
    }

    if (ss >> currency && currency != "UAH")
    {
        throw MoneyException("Невірний формат валюти"); // власний виняток
    }

    if (!SetKopek(static_cast<unsigned char>(kop)))
    {
        throw MoneyException("Некоректні копійки у введенні");
    }
}

Money operator+(const Money &m1, const Money &m2) noexcept
{
    long totalKopeks = (m1.hryvna * 100 + m1.kopek) + (m2.hryvna * 100 + m2.kopek);
    return Money(totalKopeks / 100, totalKopeks % 100);
}

double operator/(const Money &m1, const Money &m2) noexcept(false)
{
    if (m2.hryvna == 0 && m2.kopek == 0)
        throw std::domain_error("Ділення на нульовий об'єкт Money (передача за посиланням)");

    double total1 = m1.hryvna * 100.0 + m1.kopek;
    double total2 = m2.hryvna * 100.0 + m2.kopek;
    return total1 / total2;
}

Money operator/(const Money &m, double divisor) noexcept(false)
{
    if (divisor == 0)
        throw MoneyException("Ділення на нуль (передача за значенням)");

    double totalKopeks = (m.hryvna * 100.0 + m.kopek) / divisor;
    return Money(static_cast<long>(totalKopeks) / 100, static_cast<unsigned char>(static_cast<long>(totalKopeks) % 100));
}

Money &Money::operator++()
{
    long total = hryvna * 100 + kopek + 1;
    hryvna = total / 100;
    kopek = total % 100;
    return *this;
}

Money Money::operator++(int)
{
    Money tmp = *this;
    ++(*this);
    return tmp;
}

Money &Money::operator--()
{
    if (hryvna == 0 && kopek == 0)
    {
        throw new std::underflow_error("Декремент нижче за нуль (передача за вказівником)");
    }
    long total = hryvna * 100 + kopek - 1;
    hryvna = total / 100;
    kopek = total % 100;
    return *this;
}

Money Money::operator--(int)
{
    Money tmp = *this;
    --(*this);
    return tmp;
}

bool Money::operator==(const Money &other) const noexcept
{
    return hryvna == other.hryvna && kopek == other.kopek;
}

bool Money::operator!=(const Money &other) const noexcept
{
    return !(*this == other);
}

Money &Money::operator=(const Money &other) noexcept
{
    if (this != &other)
    {
        hryvna = other.hryvna;
        kopek = other.kopek;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Money &m)
{
    out << static_cast<std::string>(m);
    return out;
}

std::istream &operator>>(std::istream &in, Money &m)
{
    std::string input;
    std::getline(in, input);
    try
    {
        m.fromString(input);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Помилка: " << e.what() << '\n';
        in.setstate(std::ios::failbit);
    }
    return in;
}

Money::operator std::string() const
{
    std::stringstream ss;
    ss << hryvna << "," << std::setw(2) << std::setfill('0') << static_cast<int>(kopek) << " UAH";
    return ss.str();
}
