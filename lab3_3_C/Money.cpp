// Money.cpp
#include "Money.h"
#include <sstream>
#include <iomanip>

// Конструктори
Money::Money() : hryvna(0), kopek(0) {}
Money::Money(long hryvna, unsigned char kopek) : hryvna(hryvna), kopek(kopek) {}
Money::Money(const Money &other) : hryvna(other.hryvna), kopek(other.kopek) {}

void Money::Init(long h, unsigned char k)
{
    hryvna = h;
    kopek = k;
}

void Money::Read()
{
    long h;
    int k;
    std::cout << "Enter hryvnia: ";
    std::cin >> h;
    std::cout << "Enter kopeks (0–99): ";
    std::cin >> k;
    while (k < 0 || k > 99)
    {
        std::cout << "Invalid kopeks. Re-enter: ";
        std::cin >> k;
    }
    Init(h, static_cast<unsigned char>(k));
}

void Money::display() const
{
    std::cout << *this << std::endl;
}

std::string Money::toString() const
{
    std::ostringstream oss;
    oss << hryvna << '.' << std::setw(2) << std::setfill('0') << static_cast<int>(kopek);
    return oss.str();
}

Money::operator std::string() const
{
    return toString();
}

Money &Money::operator=(const Money &other)
{
    if (this != &other)
    {
        hryvna = other.hryvna;
        kopek = other.kopek;
    }
    return *this;
}

Money Money::operator+(const Money &other) const
{
    long totalKopeks = (hryvna * 100 + kopek) + (other.hryvna * 100 + other.kopek);
    return Money(totalKopeks / 100, totalKopeks % 100);
}

double Money::operator/(const Money &other) const
{
    int thisTotal = hryvna * 100 + kopek;
    int otherTotal = other.hryvna * 100 + other.kopek;
    if (otherTotal == 0)
        throw std::runtime_error("Division by zero Money");
    return static_cast<double>(thisTotal) / otherTotal;
}

Money Money::operator/(double divisor) const
{
    if (divisor == 0.0)
        throw std::runtime_error("Division by zero double");
    int totalKopeks = hryvna * 100 + kopek;
    int result = static_cast<int>(totalKopeks / divisor);
    return Money(result / 100, result % 100);
}

Money &Money::operator++()
{
    int totalKopeks = hryvna * 100 + kopek + 1;
    hryvna = totalKopeks / 100;
    kopek = totalKopeks % 100;
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
    int totalKopeks = hryvna * 100 + kopek - 1;
    if (totalKopeks < 0)
        totalKopeks = 0;
    hryvna = totalKopeks / 100;
    kopek = totalKopeks % 100;
    return *this;
}

Money Money::operator--(int)
{
    Money temp = *this;
    --(*this);
    return temp;
}

std::istream &operator>>(std::istream &in, Money &money)
{
    long h;
    int k;
    std::cout << "Enter hryvnia: ";
    in >> h;
    std::cout << "Enter kopeks (0–99): ";
    in >> k;
    while (k < 0 || k > 99)
    {
        std::cout << "Invalid kopeks. Re-enter: ";
        in >> k;
    }
    money.Init(h, static_cast<unsigned char>(k));
    return in;
}

std::ostream &operator<<(std::ostream &out, const Money &money)
{
    out << money.hryvna << '.' << std::setw(2) << std::setfill('0') << static_cast<int>(money.kopek) << " UAH";
    return out;
}
