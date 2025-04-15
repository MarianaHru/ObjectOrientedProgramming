// AlcoholPublic.h
#pragma once
#include "Liquid.h"

class AlcoholPublic : public Liquid
{
    double strength;

public:
    AlcoholPublic();
    AlcoholPublic(string, double, double);
    AlcoholPublic(const AlcoholPublic &); // Конструктор копіювання
    AlcoholPublic &operator=(const AlcoholPublic &);

    using Liquid::Display;
    using Liquid::Init;
    using Liquid::Read;
    using Liquid::operator string;

    AlcoholPublic &operator++();
    AlcoholPublic operator++(int);
    AlcoholPublic &operator--();
    AlcoholPublic operator--(int);

    double getStrength() const
    {
        return strength;
    }

    friend bool operator==(const AlcoholPublic &, const AlcoholPublic &);
    friend bool operator!=(const AlcoholPublic &, const AlcoholPublic &);
    friend bool operator>(const AlcoholPublic &, const AlcoholPublic &);
    friend bool operator<(const AlcoholPublic &, const AlcoholPublic &);
    friend bool operator>=(const AlcoholPublic &, const AlcoholPublic &);
    friend bool operator<=(const AlcoholPublic &, const AlcoholPublic &);
};