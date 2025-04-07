#include "MoneyPrivate.h"
#include <sstream>
#include <iostream>

MoneyPrivate::MoneyPrivate() : Money() {}

MoneyPrivate::MoneyPrivate(long hryvna, unsigned char kopek) : Money(hryvna, kopek) {}

MoneyPrivate MoneyPrivate::operator+(const MoneyPrivate &other)
{
    MoneyPrivate result;
    long totalKopeks = (hryvna * 100 + kopek) + (other.hryvna * 100 + other.kopek);
    result.hryvna = totalKopeks / 100;
    result.kopek = totalKopeks % 100;
    return result;
}

MoneyPrivate MoneyPrivate::operator-(const MoneyPrivate &other)
{
    MoneyPrivate result;
    long totalKopeks = (hryvna * 100 + kopek) - (other.hryvna * 100 + other.kopek);
    result.hryvna = totalKopeks / 100;
    result.kopek = totalKopeks % 100;
    return result;
}

bool MoneyPrivate::operator==(const MoneyPrivate &other)
{
    return (hryvna == other.hryvna && kopek == other.kopek);
}

std::string MoneyPrivate::toString() const
{
    return Money::toString();
}

void MoneyPrivate::fromString(const std::string &s)
{
    Money::fromString(s);
}
