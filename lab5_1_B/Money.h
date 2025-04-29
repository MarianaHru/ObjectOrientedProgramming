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
    Money(long hryvna, unsigned char kopek) noexcept(false);
    Money(const Money &other) noexcept;

    long GetHryvna() const noexcept { return hryvna; }
    unsigned char GetKopek() const noexcept { return kopek; }

    void SetHryvna(long h) noexcept { hryvna = h; }
    bool SetKopek(unsigned char k) noexcept(false);

    void fromString(const std::string &s) noexcept(false);

    friend Money operator+(const Money &m1, const Money &m2) noexcept;
    friend double operator/(const Money &m1, const Money &m2) noexcept(false);
    friend Money operator/(const Money &m, double divisor) noexcept(false);

    Money &operator++();   // Префіксний інкремент
    Money operator++(int); // Постфіксний інкремент
    Money &operator--();   // Префіксний декремент
    Money operator--(int); // Постфіксний декремент

    bool operator==(const Money &other) const noexcept;
    bool operator!=(const Money &other) const noexcept;
    Money &operator=(const Money &other) noexcept;

    friend std::ostream &operator<<(std::ostream &out, const Money &m);
    friend std::istream &operator>>(std::istream &in, Money &m);

    explicit operator std::string() const; // Приведення до рядка
};
