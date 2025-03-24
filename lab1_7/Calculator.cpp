#include "Calculator.h"
#include <string>

using namespace std;

void Calculator::Init(long whole, unsigned char fr) {
 fraction.Init(whole, fr);
}

void Calculator::Read()
{
 fraction.Read();
}

void Calculator::Display()
{
 fraction.Display();
}

string Calculator::toString()
{
 return fraction.toString();
}

Calculator Calculator::operator+(const Calculator& other) const 
{
 Calculator result1;
 result1.SetFraction(fraction + other.fraction);
 return result1;
}

Calculator Calculator::operator-(const Calculator& other) const
{
 Calculator result2;
 result2.SetFraction(fraction - other.fraction);
 return result2;
}

Calculator Calculator::operator*(const Calculator& other) const
{
 Calculator result3;
 result3.SetFraction(fraction * other.fraction);
 return result3;
}

bool Calculator::operator==(const Calculator& other) const
{
 return fraction == other.fraction;
}

bool Calculator::operator!=(const Calculator& other) const
{
 return !(*this == other);
}

bool Calculator::operator<(const Calculator& other) const
{
 return fraction < other.fraction;  
}

bool Calculator::operator>(const Calculator& other) const
{
 return fraction > other.fraction;  
}