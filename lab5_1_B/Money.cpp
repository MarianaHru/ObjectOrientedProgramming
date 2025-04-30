#include "Money.h"
#include "MoneyException.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

// Конструктори
Money::Money() noexcept : hryvna(0), kopek(0) {}

Money::Money(long hryvna, unsigned char kopek)
{
    this->hryvna = hryvna;
    if (!SetKopek(kopek))
        throw MoneySimpleException("Некоректне значення копійок у конструкторі");
}

Money::Money(const Money &other) noexcept
    : hryvna(other.hryvna), kopek(other.kopek) {}

// Гетери і сетери
long Money::GetHryvna() const noexcept { return hryvna; }
unsigned char Money::GetKopek() const noexcept { return kopek; }

void Money::SetHryvna(long h) noexcept { hryvna = h; }

bool Money::SetKopek(unsigned char k)
{
    if (k < 100)
    {
        kopek = k;
        return true;
    }
    throw MoneyTooSmallException("Копійки мають бути менші за 100");
}

// Парсинг з рядка
void Money::fromString(const std::string &s)
{
    std::stringstream ss(s);
    char comma;
    int kop;
    std::string currency;

    if (!(ss >> hryvna >> comma >> kop))
        throw std::invalid_argument("Невірний формат чисел");

    if (ss >> currency && currency != "UAH")
        throw MoneySimpleException("Невірний формат валюти");

    if (!SetKopek(static_cast<unsigned char>(kop)))
        throw MoneySimpleException("Некоректні копійки у введенні");
}

// Оператори
Money operator+(const Money &m1, const Money &m2)
{
    long total = (m1.hryvna * 100 + m1.kopek) + (m2.hryvna * 100 + m2.kopek);
    return Money(total / 100, total % 100);
}

double operator/(const Money &m1, const Money &m2)
{
    if (m2.hryvna == 0 && m2.kopek == 0)
        throw std::domain_error("Ділення на нульовий об'єкт");

    double a = m1.hryvna * 100.0 + m1.kopek;
    double b = m2.hryvna * 100.0 + m2.kopek;
    return a / b;
}

Money operator/(const Money &m, double divisor)
{
    if (divisor == 0)
        throw MoneySimpleException("Ділення на нуль");

    double total = (m.hryvna * 100.0 + m.kopek) / divisor;
    return Money(static_cast<long>(total) / 100, static_cast<unsigned char>(static_cast<long>(total) % 100));
}

// Інкремент і декремент
Money &Money::operator++()
{
    long total = hryvna * 100 + kopek + 1;
    hryvna = total / 100;
    kopek = total % 100;
    return *this;
}

Money Money::operator++(int)
{
    Money temp = *this;
    ++(*this);
    return temp;
}

Money &Money::operator--()
{
    if (hryvna == 0 && kopek == 0)
        throw MoneyTooSmallException("Декремент нижче за нуль");

    long total = hryvna * 100 + kopek - 1;
    hryvna = total / 100;
    kopek = total % 100;
    return *this;
}

Money Money::operator--(int)
{
    Money temp = *this;
    --(*this);
    return temp;
}

// Порівняння
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

// Приведення до рядка
Money::operator std::string() const
{
    std::stringstream ss;
    ss << hryvna << "," << std::setw(2) << std::setfill('0') << static_cast<int>(kopek) << " UAH";
    return ss.str();
}
