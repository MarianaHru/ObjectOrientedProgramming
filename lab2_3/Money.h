#pragma once
#include <iostream>
#include <string>

using namespace std;

class Money
{
private:
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

    // Операції введення/виводу
    string toString() const;
    void fromString(const string &s);

    // Операції
    friend Money operator+(const Money &m1, const Money &m2);
    friend double operator/(const Money &m1, const Money &m2);
    friend Money operator/(const Money &m, double divisor);

    Money &operator++();   // Префіксний інкремент
    Money operator++(int); // Постфіксний інкремент
    Money &operator--();   // Префіксний декремент
    Money operator--(int); // Постфіксний декремент

    // Операції порівняння
    bool operator==(const Money &other) const;
    bool operator!=(const Money &other) const;

    // Операція присвоєння
    Money &operator=(const Money &other);

    // Додавання операторів введення/виведення
    friend ostream &operator<<(ostream &out, const Money &m);
    friend istream &operator>>(istream &in, Money &m);

    operator string() const { return toString(); }
};
