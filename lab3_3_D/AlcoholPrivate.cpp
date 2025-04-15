// AlcoholPrivate.cpp
#include "AlcoholPrivate.h"

AlcoholPrivate::AlcoholPrivate() : Liquid(), strength(0) {}

AlcoholPrivate::AlcoholPrivate(string n, double d, double s) : Liquid(n, d), strength(s < 0 ? 0 : s) {}

AlcoholPrivate::AlcoholPrivate(const AlcoholPrivate &other) : Liquid(other), strength(other.strength) {}

AlcoholPrivate &AlcoholPrivate::operator=(const AlcoholPrivate &other)
{
    if (this != &other)
    {
        Liquid::operator=(other); // Виклик оператора присвоєння базового класу
        strength = other.strength;
    }
    return *this;
}

AlcoholPrivate &AlcoholPrivate::operator++()
{
    ++strength;
    return *this;
}

AlcoholPrivate AlcoholPrivate::operator++(int)
{
    AlcoholPrivate temp = *this;
    strength++;
    return temp;
}

AlcoholPrivate &AlcoholPrivate::operator--()
{
    --strength;
    if (strength < 0)
        strength = 0;
    return *this;
}

AlcoholPrivate AlcoholPrivate::operator--(int)
{
    AlcoholPrivate temp = *this;
    strength--;
    if (strength < 0)
        strength = 0;
    return temp;
}

bool operator==(const AlcoholPrivate &a, const AlcoholPrivate &b)
{
    return (string)a == (string)b && a.strength == b.strength;
}

bool operator!=(const AlcoholPrivate &a, const AlcoholPrivate &b)
{
    return !(a == b);
}

bool operator>(const AlcoholPrivate &a, const AlcoholPrivate &b)
{
    return a.strength > b.strength;
}

bool operator<(const AlcoholPrivate &a, const AlcoholPrivate &b)
{
    return a.strength < b.strength;
}

bool operator>=(const AlcoholPrivate &a, const AlcoholPrivate &b)
{
    return !(a < b);
}

bool operator<=(const AlcoholPrivate &a, const AlcoholPrivate &b)
{
    return !(a > b);
}

ostream &operator<<(ostream &out, const AlcoholPrivate &a)
{
    out << (string)a << ", Strength: " << a.strength;
    return out;
}

istream &operator>>(istream &in, AlcoholPrivate &a)
{
    in >> (Liquid &)a;
    cout << "Enter strength: ";
    in >> a.strength;
    if (a.strength < 0)
        a.strength = 0;
    return in;
}