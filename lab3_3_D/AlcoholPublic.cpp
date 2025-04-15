// AlcoholPublic.cpp
#include "AlcoholPublic.h"

AlcoholPublic::AlcoholPublic() : Liquid(), strength(0) {}

AlcoholPublic::AlcoholPublic(string n, double d, double s) : Liquid(n, d), strength(s < 0 ? 0 : s) {}

AlcoholPublic &AlcoholPublic::operator=(const AlcoholPublic &other)
{
    if (this != &other)
    {
        name = other.name;
        density = other.density;
        strength = other.strength;
    }
    return *this;
}

AlcoholPublic &AlcoholPublic::operator++()
{
    ++strength;
    return *this;
}

AlcoholPublic AlcoholPublic::operator++(int)
{
    AlcoholPublic temp = *this;
    strength++;
    return temp;
}

AlcoholPublic &AlcoholPublic::operator--()
{
    --strength;
    if (strength < 0)
        strength = 0;
    return *this;
}

AlcoholPublic AlcoholPublic::operator--(int)
{
    AlcoholPublic temp = *this;
    strength--;
    if (strength < 0)
        strength = 0;
    return temp;
}

bool operator==(const AlcoholPublic &a, const AlcoholPublic &b)
{
    return a.name == b.name && a.density == b.density && a.strength == b.strength;
}

bool operator!=(const AlcoholPublic &a, const AlcoholPublic &b)
{
    return !(a == b);
}

bool operator>(const AlcoholPublic &a, const AlcoholPublic &b)
{
    return a.strength > b.strength;
}

bool operator<(const AlcoholPublic &a, const AlcoholPublic &b)
{
    return a.strength < b.strength;
}

bool operator>=(const AlcoholPublic &a, const AlcoholPublic &b)
{
    return !(a < b);
}

bool operator<=(const AlcoholPublic &a, const AlcoholPublic &b)
{
    return !(a > b);
}
