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
    // Конструктори
    Money();
    Money(long hryvna, unsigned char kopek);
    Money(const Money &other);

    // Геттери та сеттери
    long GetHryvna() const { return hryvna; }
    unsigned char GetKopek() const { return kopek; }
    void SetHryvna(long h) { hryvna = h; }
    bool SetKopek(unsigned char k);

    // Операції введення/виводу
    friend ostream &operator<<(ostream &out, const Money &m);
    friend istream &operator>>(istream &in, Money &m);

    // Операції
    Money operator+(const Money &other) const;
    double operator/(const Money &other) const;
    Money operator/(double divisor) const;

    Money &operator++();   // Префіксний інкремент
    Money operator++(int); // Постфіксний інкремент
    Money &operator--();   // Префіксний декремент
    Money operator--(int); // Постфіксний декремент

    operator string() const; // Перетворення у строку
};
