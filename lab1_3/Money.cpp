#include "Money.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

Money::Money(long hryvna, unsigned char kopek)
{
    this->hryvna = hryvna;
    this->kopek = kopek;
}

bool Money::SetSecond(unsigned char first)
{
    if (first < 100)
    {
        kopek = first;
        return true;
    }
    else
    {
        cout << "Error, pennies cant be more than 99";
        return false;
    }
}

bool Money::Init(long hr, unsigned char kop)
{
    SetFirst(hr);
    return SetSecond(kop);
}

void Money::Read()
{
    long hr;
    unsigned char kop;
    cout << "Write hryvnias: ";
    cin >> hr;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int temp_kop;

    do
    {
        cout << "Write pennies(0-99) ";
        cin >> temp_kop;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        kop = static_cast<unsigned char>(temp_kop);
    } while (!Init(hr, kop));
}

void Money::Display() const
{
    cout << toString() << endl;
}

string Money::toString() const
{
    stringstream sout;

    sout << hryvna << ",";
    if (kopek < 10)
    {
        sout << "0";
    }
    sout << (int)kopek << "grn";
    return sout.str();
}

Money Money::operator+(const Money &other) const
{
    long totalKop = (hryvna * 100 + kopek) + (other.hryvna * 100 + other.kopek);
    return Money(totalKop / 100, totalKop % 100);
}

double Money::operator/(const Money &other) const
{
    if (other.hryvna == 0 && other.kopek == 0)
    {

        throw invalid_argument("cant be zero");
    }

    double totalKop1 = hryvna * 100.0 + kopek;
    double totalKop2 = other.hryvna * 100.0 + other.kopek;
    double result = totalKop1 / totalKop2;

    return result;
}

Money Money::operator/(double divisor) const
{
    if (divisor == 0)
    {
        throw std::invalid_argument("cant be zero!");
    }

    double totalKop = (hryvna * 100.0 + kopek) / divisor;
    return Money((long)totalKop / 100, (unsigned char)((long)totalKop % 100));
}
