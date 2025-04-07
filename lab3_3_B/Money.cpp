#include "Money.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

Money::Money() : hryvna(0), kopek(0) {}

Money::Money(long hryvna, unsigned char kopek)
{
    this->hryvna = hryvna;
    if (!SetKopek(kopek))
        this->kopek = 0;
}

Money::Money(const Money &other)
{
    this->hryvna = other.hryvna;
    this->kopek = other.kopek;
}

bool Money::SetKopek(unsigned char k)
{
    if (k < 100)
    {
        kopek = k;
        return true;
    }
    std::cout << "Error: kopeks must be less than 100" << std::endl;
    return false;
}

std::ostream &operator<<(std::ostream &out, const Money &m)
{
    out << m.toString();
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
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        in.setstate(std::ios::failbit);
    }
    return in;
}

std::string Money::toString() const
{
    std::stringstream sout;
    sout << hryvna << "," << std::setw(2) << std::setfill('0') << static_cast<int>(kopek) << " UAH";
    return sout.str();
}

void Money::fromString(const std::string &s)
{
    std::stringstream sin(s);
    char comma;
    int kop;
    std::string currency;

    if (!(sin >> hryvna >> comma >> kop))
    {
        throw std::invalid_argument("Invalid numeric format");
    }

    if (sin >> currency)
    {
        if (currency != "UAH")
        {
            std::cerr << "Parsed currency: " << currency << std::endl;
            throw std::invalid_argument("Invalid currency format");
        }
    }

    if (!SetKopek(static_cast<unsigned char>(kop)))
    {
        throw std::invalid_argument("Invalid kopek value");
    }
}

// Оператор + для Money
Money operator+(const Money &m1, const Money &m2)
{
    long totalKopeks = (m1.hryvna * 100 + m1.kopek) + (m2.hryvna * 100 + m2.kopek);
    return Money(totalKopeks / 100, totalKopeks % 100);
}

// Оператор / для Money
double operator/(const Money &m1, const Money &m2)
{
    if (m2.hryvna == 0 && m2.kopek == 0)
    {
        throw std::invalid_argument("Division by zero!");
    }

    double total1 = m1.hryvna * 100.0 + m1.kopek;
    double total2 = m2.hryvna * 100.0 + m2.kopek;
    return total1 / total2;
}

// Оператор / для Money і числа
Money operator/(const Money &m, double divisor)
{
    if (divisor == 0)
    {
        throw std::invalid_argument("Division by zero!");
    }

    double totalKopeks = (m.hryvna * 100.0 + m.kopek) / divisor;
    return Money(static_cast<long>(totalKopeks) / 100, static_cast<unsigned char>(static_cast<long>(totalKopeks) % 100));
}

// Префіксний інкремент
Money &Money::operator++()
{
    long totalKopeks = hryvna * 100 + kopek + 1;
    hryvna = totalKopeks / 100;
    kopek = totalKopeks % 100;
    return *this;
}

// Постфіксний інкремент
Money Money::operator++(int)
{
    Money temp = *this;
    ++(*this);
    return temp;
}

// Префіксний декремент
Money &Money::operator--()
{
    if (hryvna == 0 && kopek == 0)
    {
        std::cout << "Cannot decrement below zero!" << std::endl;
        return *this;
    }

    long totalKopeks = hryvna * 100 + kopek - 1;
    hryvna = totalKopeks / 100;
    kopek = totalKopeks % 100;
    return *this;
}

// Постфіксний декремент
Money Money::operator--(int)
{
    Money temp = *this;
    --(*this);
    return temp;
}

// Операція порівняння
bool Money::operator==(const Money &other) const
{
    return (hryvna == other.hryvna) && (kopek == other.kopek);
}

bool Money::operator!=(const Money &other) const
{
    return !(*this == other);
}

// Операція присвоєння
Money &Money::operator=(const Money &other)
{
    if (this == &other)
    {
        return *this;
    }
    hryvna = other.hryvna;
    kopek = other.kopek;
    return *this;
}
