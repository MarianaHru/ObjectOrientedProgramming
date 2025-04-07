#pragma once
#include <string>
#include <iostream>

class Money
{
protected:
    long hryvna;
    unsigned char kopek;

public:
    Money();
    Money(long hryvna, unsigned char kopek);
    Money(const Money &other);

    // Геттери та сеттери
    long GetHryvna() const { return hryvna; }
    unsigned char GetKopek() const { return kopek; }
    void SetHryvna(long h) { hryvna = h; }
    bool SetKopek(unsigned char k);

    // Операції вводу/виводу
    std::string toString() const;
    void fromString(const std::string &s);

    // Операції
    friend Money operator+(const Money &m1, const Money &m2);
    friend double operator/(const Money &m1, const Money &m2); // Оператор ділення для двох Money
    friend Money operator/(const Money &m, double divisor);    // Оператор ділення Money на число

    Money &operator++();   // Префіксний інкремент
    Money operator++(int); // Постфіксний інкремент
    Money &operator--();   // Префіксний декремент
    Money operator--(int); // Постфіксний декремент

    bool operator==(const Money &other) const;
    bool operator!=(const Money &other) const;

    Money &operator=(const Money &other);

    friend std::ostream &operator<<(std::ostream &out, const Money &m);
    friend std::istream &operator>>(std::istream &in, Money &m);

    operator std::string() const { return toString(); }
};
