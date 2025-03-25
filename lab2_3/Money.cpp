#include "Money.h"
#include <iomanip>
#include <sstream>
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
    cout << "Error: kopeks must be less than 100" << endl;
    return false;
}

ostream &operator<<(ostream &out, const Money &m)
{
    out << m.hryvna << ",";
    out << setw(2) << setfill('0') << static_cast<int>(m.kopek) << " UAH";
    return out;
}

istream &operator>>(istream &in, Money &m)
{
    cout << "Enter hryvnia: ";
    in >> m.hryvna;

    int tempKopek;
    do
    {
        cout << "Enter kopeks (0-99): ";
        in >> tempKopek;
    } while (!m.SetKopek(static_cast<unsigned char>(tempKopek)));

    return in;
}

Money Money::operator+(const Money &other) const
{
    long totalKopeks = (hryvna * 100 + kopek) + (other.hryvna * 100 + other.kopek);
    return Money(totalKopeks / 100, totalKopeks % 100);
}

double Money::operator/(const Money &other) const
{
    if (other.hryvna == 0 && other.kopek == 0)
    {
        throw invalid_argument("Division by zero!");
    }

    double total1 = hryvna * 100.0 + kopek;
    double total2 = other.hryvna * 100.0 + other.kopek;
    return total1 / total2;
}

Money Money::operator/(double divisor) const
{
    if (divisor == 0)
    {
        throw invalid_argument("Division by zero!");
    }

    double totalKopeks = (hryvna * 100.0 + kopek) / divisor;
    return Money(static_cast<long>(totalKopeks) / 100, static_cast<unsigned char>(static_cast<long>(totalKopeks) % 100));
}

Money &Money::operator++()
{
    long totalKopeks = hryvna * 100 + kopek + 1;
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
    if (hryvna == 0 && kopek == 0)
    {
        cout << "Cannot decrement below zero!" << endl;
        return *this;
    }

    long totalKopeks = hryvna * 100 + kopek - 1;
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

Money::operator string() const
{
    stringstream sout;
    sout << hryvna << "," << setw(2) << setfill('0') << static_cast<int>(kopek) << " UAH";
    return sout.str();
}
