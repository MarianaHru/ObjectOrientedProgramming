#pragma once
#include <iostream>
#include <string>
#include "MoneyException.h"

class Money
{
private:
    long hryvna;
    unsigned char kopek;

public:
    Money() noexcept;
    Money(long hryvna, unsigned char kopek);
    Money(const Money &other) noexcept;

    long GetHryvna() const noexcept;
    unsigned char GetKopek() const noexcept;

    void SetHryvna(long h) noexcept;
    bool SetKopek(unsigned char k);

    void fromString(const std::string &s);

    friend Money operator+(const Money &m1, const Money &m2);
    friend double operator/(const Money &m1, const Money &m2);
    friend Money operator/(const Money &m, double divisor);

    Money &operator++();   // Префіксний інкремент
    Money operator++(int); // Постфіксний інкремент
    Money &operator--();   // Префіксний декремент
    Money operator--(int); // Постфіксний декремент

    bool operator==(const Money &other) const noexcept;
    bool operator!=(const Money &other) const noexcept;
    Money &operator=(const Money &other) noexcept;

    friend std::ostream &operator<<(std::ostream &out, const Money &m);
    friend std::istream &operator>>(std::istream &in, Money &m);

    explicit operator std::string() const;
};
