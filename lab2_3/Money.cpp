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
    out << m.toString();
    return out;
}

istream &operator>>(istream &in, Money &m)
{
    string input;
    getline(in, input);
    try
    {
        m.fromString(input);
    }
    catch (const invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
        in.setstate(ios::failbit);
    }
    return in;
}

string Money::toString() const
{
    stringstream sout;
    sout << hryvna << "," << setw(2) << setfill('0') << static_cast<int>(kopek) << " UAH";
    return sout.str();
}

// void Money::fromString(const string &s)
// {
//     stringstream sin(s);
//     char comma;
//     sin >> hryvna >> comma >> kopek;
// }

void Money::fromString(const string &s)
{
    stringstream sin(s);
    char comma;
    int kop;
    string currency;

    if (!(sin >> hryvna >> comma >> kop))
    {
        throw invalid_argument("Invalid numeric format");
    }

    if (sin >> currency)
    {
        if (currency != "UAH")
        {
            cerr << "Parsed currency: " << currency << endl;
            throw invalid_argument("Invalid currency format");
        }
    }

    if (!SetKopek(static_cast<unsigned char>(kop)))
    {
        throw invalid_argument("Invalid kopek value");
    }
}

Money operator+(const Money &m1, const Money &m2)
{
    long totalKopeks = (m1.hryvna * 100 + m1.kopek) + (m2.hryvna * 100 + m2.kopek);
    return Money(totalKopeks / 100, totalKopeks % 100);
}

double operator/(const Money &m1, const Money &m2)
{
    if (m2.hryvna == 0 && m2.kopek == 0)
    {
        throw invalid_argument("Division by zero!");
    }

    double total1 = m1.hryvna * 100.0 + m1.kopek;
    double total2 = m2.hryvna * 100.0 + m2.kopek;
    return total1 / total2;
}

Money operator/(const Money &m, double divisor)
{
    if (divisor == 0)
    {
        throw invalid_argument("Division by zero!");
    }

    double totalKopeks = (m.hryvna * 100.0 + m.kopek) / divisor;
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

bool Money::operator==(const Money &other) const
{
    return (hryvna == other.hryvna) && (kopek == other.kopek);
}

bool Money::operator!=(const Money &other) const
{
    return !(*this == other);
}

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
