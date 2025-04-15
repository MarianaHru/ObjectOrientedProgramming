#include "Pair.h"
#include <iostream>
#include <string>
#include <sstream>

Pair::Pair(int x, int y) : first(x), second(y) {}

Pair::Pair(const Pair &other) : first(other.first), second(other.second) {}

void Pair::Init(int x, int y)
{
    first = x;
    second = y;
}

int Pair::getFirst() const
{
    return first;
}

int Pair::getSecond() const
{
    return second;
}

void Pair::setFirst(int f)
{
    first = f;
}

void Pair::setSecond(int s)
{
    second = s;
}

void Pair::Read()
{
    std::cout << "Введіть перше число: ";
    std::cin >> first;
    std::cout << "Введіть друге число: ";
    std::cin >> second;
}

void Pair::Display() const
{
    std::cout << "(" << first << ", " << second << ")";
}

std::string Pair::toString() const
{
    std::stringstream ss;
    ss << "(" << first << ", " << second << ")";
    return ss.str();
}

bool Pair::operator==(const Pair &other) const
{
    return (first == other.first) && (second == other.second);
}

bool Pair::operator!=(const Pair &other) const
{
    return !(*this == other);
}

bool Pair::operator>(const Pair &other) const
{
    return (first > other.first) || (first == other.first && second > other.second);
}

bool Pair::operator<(const Pair &other) const
{
    return (first < other.first) || (first == other.first && second < other.second);
}

bool Pair::operator>=(const Pair &other) const
{
    return (*this > other) || (*this == other);
}

bool Pair::operator<=(const Pair &other) const
{
    return (*this < other) || (*this == other);
}

std::ostream &operator<<(std::ostream &out, const Pair &p)
{
    out << p.toString();
    return out;
}

std::istream &operator>>(std::istream &in, Pair &p)
{
    char openBracket, comma, closeBracket;
    if (in >> openBracket >> p.first >> comma >> p.second >> closeBracket &&
        openBracket == '(' && comma == ',' && closeBracket == ')')
    {
        return in;
    }
    else
    {
        in.setstate(std::ios::failbit);
        return in;
    }
}