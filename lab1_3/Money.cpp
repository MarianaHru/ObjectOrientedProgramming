#include "Money.h"

Money::Money() : hryvnias(0), kopecks(0) {}

Money::Money(long h, unsigned char k)
{
    if (!Init(h, k))
    {
        hryvnias = 0;
        kopecks = 0;
    }
}

bool Money::Init(long h, unsigned char k)
{
    hryvnias = h + k / 100;
    kopecks = k % 100;
    return true;
}

void Money::Read()
{
    long h;
    unsigned int k;
    do
    {
        cout << "Input money amount (hryvnias kopecks): ";
        cin >> h >> k;
    } while (!Init(h, k));
}

void Money::Display() const
{
    cout << hryvnias << "," << (int)kopecks << " UAH" << endl;
}

Money Money::Add(const Money &other) const
{
    long totalKopecks = (hryvnias * 100 + kopecks) + (other.hryvnias * 100 + other.kopecks);
    return Money(totalKopecks / 100, (unsigned char)(totalKopecks % 100));
}

Money Money::Divide(const Money &other) const
{
    double val1 = hryvnias + kopecks / 100.0;
    double val2 = other.hryvnias + other.kopecks / 100.0;
    if (val2 == 0)
    {
        cout << "Division by zero error!" << endl;
        return Money(0, 0);
    }
    double result = val1 / val2;
    return Money(static_cast<long>(result), static_cast<unsigned char>((result - static_cast<long>(result)) * 100));
}

Money Money::DivideByNumber(double number) const
{
    if (number == 0)
    {
        cout << "Division by zero error!" << endl;
        return Money(0, 0);
    }
    double total = (hryvnias + kopecks / 100.0) / number;
    return Money(static_cast<long>(total), static_cast<unsigned char>((total - static_cast<long>(total)) * 100));
}