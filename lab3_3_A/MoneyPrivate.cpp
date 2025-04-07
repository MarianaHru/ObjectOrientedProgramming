#include "MoneyPrivate.h"

MoneyPrivate::MoneyPrivate() : Money() {}

MoneyPrivate::MoneyPrivate(long hryvna, unsigned char kopek)
    : Money(hryvna, kopek) {}

MoneyPrivate::MoneyPrivate(const Money &other)
    : Money(other) {}

Money MoneyPrivate::toBase() const
{
    return *this;
}

MoneyPrivate MoneyPrivate::operator+(const MoneyPrivate &other) const
{
    long totalKopeks = (hryvna * 100 + kopek) + (other.hryvna * 100 + other.kopek);
    return MoneyPrivate(totalKopeks / 100, totalKopeks % 100);
}

MoneyPrivate MoneyPrivate::operator/(double divisor) const
{
    if (divisor == 0)
        throw invalid_argument("Division by zero!");

    double totalKopeks = (hryvna * 100.0 + kopek) / divisor;
    return MoneyPrivate(static_cast<long>(totalKopeks) / 100, static_cast<unsigned char>(static_cast<long>(totalKopeks) % 100));
}

double MoneyPrivate::operator/(const MoneyPrivate &other) const
{
    if (other.hryvna == 0 && other.kopek == 0)
        throw invalid_argument("Division by zero!");

    double total1 = hryvna * 100.0 + kopek;
    double total2 = other.hryvna * 100.0 + other.kopek;
    return total1 / total2;
}

MoneyPrivate &MoneyPrivate::operator++()
{
    long totalKopeks = hryvna * 100 + kopek + 1;
    hryvna = totalKopeks / 100;
    kopek = totalKopeks % 100;
    return *this;
}

MoneyPrivate MoneyPrivate::operator++(int)
{
    MoneyPrivate temp = *this;
    ++(*this);
    return temp;
}

MoneyPrivate &MoneyPrivate::operator--()
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

MoneyPrivate MoneyPrivate::operator--(int)
{
    MoneyPrivate temp = *this;
    --(*this);
    return temp;
}

bool MoneyPrivate::operator==(const MoneyPrivate &other) const
{
    return (hryvna == other.hryvna) && (kopek == other.kopek);
}

bool MoneyPrivate::operator!=(const MoneyPrivate &other) const
{
    return !(*this == other);
}
