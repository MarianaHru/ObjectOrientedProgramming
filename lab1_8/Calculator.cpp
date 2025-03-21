// Calculator.cpp
#include "Calculator.h"
#include <sstream>

// Fraction реалізація
Calculator::Fraction::Fraction() : integerPart(0), fractionalPart(0) {}
Calculator::Fraction::Fraction(long long integer, unsigned short fractional) : integerPart(integer), fractionalPart(fractional) {}

void Calculator::Fraction::Init(long long integer, unsigned short fractional)
{
    integerPart = integer;
    fractionalPart = fractional;
}

void Calculator::Fraction::Read()
{
    std::cout << "Enter integer part: ";
    std::cin >> integerPart;
    std::cout << "Enter fractional part: ";
    std::cin >> fractionalPart;
}

void Calculator::Fraction::Display() const
{
    std::cout << integerPart << "." << fractionalPart << std::endl;
}

std::string Calculator::Fraction::toString() const
{
    std::ostringstream oss;
    oss << integerPart << "." << fractionalPart;
    return oss.str();
}

long long Calculator::Fraction::GetIntegerPart() const { return integerPart; }
unsigned short Calculator::Fraction::GetFractionalPart() const { return fractionalPart; }
void Calculator::Fraction::SetIntegerPart(long long integer) { integerPart = integer; }
void Calculator::Fraction::SetFractionalPart(unsigned short fractional) { fractionalPart = fractional; }

Calculator::Fraction Calculator::Fraction::operator+(const Fraction &other) const
{
    return Fraction(integerPart + other.integerPart, fractionalPart + other.fractionalPart);
}

Calculator::Fraction Calculator::Fraction::operator-(const Fraction &other) const
{
    return Fraction(integerPart - other.integerPart, fractionalPart - other.fractionalPart);
}

Calculator::Fraction Calculator::Fraction::operator*(const Fraction &other) const
{
    return Fraction(integerPart * other.integerPart, fractionalPart * other.fractionalPart);
}

bool Calculator::Fraction::operator==(const Fraction &other) const
{
    return integerPart == other.integerPart && fractionalPart == other.fractionalPart;
}

bool Calculator::Fraction::operator!=(const Fraction &other) const
{
    return !(*this == other);
}

bool Calculator::Fraction::operator<(const Fraction &other) const
{
    return integerPart < other.integerPart || (integerPart == other.integerPart && fractionalPart < other.fractionalPart);
}

bool Calculator::Fraction::operator>(const Fraction &other) const
{
    return integerPart > other.integerPart || (integerPart == other.integerPart && fractionalPart > other.fractionalPart);
}

// Calculator реалізація
Calculator::Fraction Calculator::Add(const Fraction &a, const Fraction &b)
{
    return a + b;
}

Calculator::Fraction Calculator::Subtract(const Fraction &a, const Fraction &b)
{
    return a - b;
}

Calculator::Fraction Calculator::Multiply(const Fraction &a, const Fraction &b)
{
    return a * b;
}

bool Calculator::Compare(const Fraction &a, const Fraction &b)
{
    return a == b;
}
