#include "Money.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>

Money::Money() : Pair(0, 0), kopek(0) {}

Money::Money(long hryvna, unsigned char kopek) : Pair(hryvna, kopek), kopek(0)
{
    SetHryvna(hryvna);
    SetKopek(kopek);
}

Money::Money(const Money &other) : Pair(other.first, other.second), kopek(other.kopek) {}

long Money::GetHryvna() const { return first; }

unsigned char Money::GetKopek() const { return kopek; }

void Money::SetHryvna(long h) { first = h; }

bool Money::SetKopek(unsigned char k)
{
    if (k < 100)
    {
        second = k;
        kopek = k;
        return true;
    }
    std::cout << "Error: kopeks must be less than 100" << std::endl;
    return false;
}

void Money::Init(long hryvna, unsigned char kopek)
{
    SetHryvna(hryvna);
    SetKopek(kopek);
}

std::string Money::toString() const
{
    std::stringstream sout;
    sout << first << "," << std::setw(2) << std::setfill('0') << static_cast<int>(kopek);
    return sout.str();
}

void Money::fromString(const std::string &s)
{
    std::stringstream sin(s);
    char comma;
    int kop;
    if (sin >> first >> comma >> kop && comma == ',')
    {
        if (!SetKopek(static_cast<unsigned char>(kop)))
        {
            throw std::invalid_argument("Invalid kopek value");
        }
        second = kopek;
    }
    else
    {
        throw std::invalid_argument("Invalid money format");
    }
}

Money operator+(const Money &m1, const Money &m2)
{
    long totalKopeks1 = m1.first * 100 + m1.kopek;
    long totalKopeks2 = m2.first * 100 + m2.kopek;
    long sumTotalKopeks = totalKopeks1 + totalKopeks2;
    return Money(sumTotalKopeks / 100, sumTotalKopeks % 100);
}

Money operator-(const Money &m1, const Money &m2)
{
    long totalKopeks1 = m1.first * 100 + m1.kopek;
    long totalKopeks2 = m2.first * 100 + m2.kopek;
    long diffTotalKopeks = totalKopeks1 - totalKopeks2;
    if (diffTotalKopeks < 0)
    {
        throw std::invalid_argument("Resulting money cannot be negative");
    }
    return Money(diffTotalKopeks / 100, diffTotalKopeks % 100);
}

double operator/(const Money &m1, const Money &m2)
{
    if (m2.first == 0 && m2.kopek == 0)
    {
        throw std::invalid_argument("Division by zero!");
    }
    double total1 = m1.first * 100.0 + m1.kopek;
    double total2 = m2.first * 100.0 + m2.kopek;
    return total1 / total2;
}

Money operator/(const Money &m, double divisor)
{
    if (divisor == 0)
    {
        throw std::invalid_argument("Division by zero!");
    }
    double totalKopeks = (m.first * 100.0 + m.kopek) / divisor;
    return Money(static_cast<long>(totalKopeks) / 100, static_cast<unsigned char>(static_cast<long>(totalKopeks) % 100));
}

Money &Money::operator++()
{
    long totalKopeks = first * 100 + kopek + 1;
    first = totalKopeks / 100;
    kopek = totalKopeks % 100;
    second = kopek;
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
    if (first == 0 && kopek == 0)
    {
        std::cout << "Cannot decrement below zero!" << std::endl;
        return *this;
    }
    long totalKopeks = first * 100 + kopek - 1;
    first = totalKopeks / 100;
    kopek = totalKopeks % 100;
    second = kopek;
    return *this;
}

Money Money::operator--(int)
{
    Money temp = *this;
    --(*this);
    return temp;
}

Money &Money::operator=(const Money &other)
{
    if (this == &other)
    {
        return *this;
    }
    Pair::operator=(other);
    kopek = other.kopek;
    return *this;
}

Money makeMoney(long hryvna, unsigned char kopek)
{
    if (hryvna < 0 || kopek >= 100)
    {
        std::cerr << "Error: Invalid parameters for Money object." << std::endl;
        exit(1);
    }
    return Money(hryvna, kopek);
}