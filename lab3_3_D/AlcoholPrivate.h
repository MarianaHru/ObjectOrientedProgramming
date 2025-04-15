// AlcoholPrivate.h
#pragma once
#include "Liquid.h"

class AlcoholPrivate : private Liquid
{
    double strength;

public:
    AlcoholPrivate();
    AlcoholPrivate(string, double, double);

    using Liquid::Display;
    using Liquid::Init;
    using Liquid::Read;
    using Liquid::operator string;

    AlcoholPrivate &operator++();
    AlcoholPrivate operator++(int);
    AlcoholPrivate &operator--();
    AlcoholPrivate operator--(int);

    double getStrength() const
    {
        return strength;
    }

    friend bool operator==(const AlcoholPrivate &, const AlcoholPrivate &);
    friend bool operator!=(const AlcoholPrivate &, const AlcoholPrivate &);
    friend bool operator>(const AlcoholPrivate &, const AlcoholPrivate &);
    friend bool operator<(const AlcoholPrivate &, const AlcoholPrivate &);
    friend bool operator>=(const AlcoholPrivate &, const AlcoholPrivate &);
    friend bool operator<=(const AlcoholPrivate &, const AlcoholPrivate &);

    friend ostream &operator<<(ostream &, const AlcoholPrivate &);
    friend istream &operator>>(istream &, AlcoholPrivate &);
};