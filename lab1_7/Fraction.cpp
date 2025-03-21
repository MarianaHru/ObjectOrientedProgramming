// Fraction.cpp
#include "Fraction.h"
#include <sstream>

Fraction::Fraction() : integerPart(0), fractionalPart(0) {}
Fraction::Fraction(long long integer, unsigned short fractional) : integerPart(integer), fractionalPart(fractional) {}

void Fraction::Init(long long integer, unsigned short fractional)
{
    integerPart = integer;
    fractionalPart = fractional;
}

void Fraction::Read()
{
    std::cout << "Enter integer part: ";
    std::cin >> integerPart;
    std::cout << "Enter fractional part: ";
    std::cin >> fractionalPart;
}

void Fraction::Display() const
{
    std::cout << integerPart << "." << fractionalPart << std::endl;
}

std::string Fraction::toString() const
{
    std::ostringstream oss;
    oss << integerPart << "." << fractionalPart;
    return oss.str();
}

long long Fraction::GetIntegerPart() const { return integerPart; }
unsigned short Fraction::GetFractionalPart() const { return fractionalPart; }
void Fraction::SetIntegerPart(long long integer) { integerPart = integer; }
void Fraction::SetFractionalPart(unsigned short fractional) { fractionalPart = fractional; }

Fraction Fraction::operator+(const Fraction &other) const
{
    long long newInteger = integerPart + other.integerPart;
    unsigned short newFractional = fractionalPart + other.fractionalPart;
    return Fraction(newInteger, newFractional);
}

Fraction Fraction::operator-(const Fraction &other) const
{
    long long newInteger = integerPart - other.integerPart;
    unsigned short newFractional = fractionalPart - other.fractionalPart;
    return Fraction(newInteger, newFractional);
}

Fraction Fraction::operator*(const Fraction &other) const
{
    long long newInteger = integerPart * other.integerPart;
    unsigned short newFractional = fractionalPart * other.fractionalPart;
    return Fraction(newInteger, newFractional);
}

bool Fraction::operator==(const Fraction &other) const
{
    return (integerPart == other.integerPart) && (fractionalPart == other.fractionalPart);
}

bool Fraction::operator!=(const Fraction &other) const
{
    return !(*this == other);
}

bool Fraction::operator<(const Fraction &other) const
{
    return (integerPart < other.integerPart) || (integerPart == other.integerPart && fractionalPart < other.fractionalPart);
}

bool Fraction::operator>(const Fraction &other) const
{
    return (integerPart > other.integerPart) || (integerPart == other.integerPart && fractionalPart > other.fractionalPart);
}
