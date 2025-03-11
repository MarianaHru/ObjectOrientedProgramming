#ifndef MONEY_H
#define MONEY_H

#include <iostream>
using namespace std;

class Money
{
private:
    long hryvnias;
    unsigned char kopecks;

public:
    Money();                        // Конструктор за замовчуванням
    Money(long h, unsigned char k); // Конструктор із параметрами

    bool Init(long h, unsigned char k);
    void Read();
    void Display() const;

    Money Add(const Money &other) const;
    Money Divide(const Money &other) const;
    Money DivideByNumber(double number) const;
};

#endif