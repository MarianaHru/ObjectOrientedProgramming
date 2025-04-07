#include "Money.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>

Money::Money() : hryvna(0), kopek(0) {}

Money::Money(long hryvna, unsigned char kopek)
{
    this->hryvna = hryvna;
    if (!SetKopek(kopek))
        this->kopek = 0;
}

Money::Money(const Money &other)
{
    this->hryvna = other.hryvna;
    this->kopek = other.kopek;
}

long Money::GetHryvna() const { return hryvna; }

unsigned char Money::GetKopek() const { return kopek; }

void Money::SetHryvna(long h) { hryvna = h; }

bool Money::SetKopek(unsigned char k)
{
    if (k < 100)
    {
        kopek = k;
        return true;
    }
    cout << "Error: kopeks must be less than 100" << endl;
    return false;
}

string Money::toString() const
{
    stringstream sout;
    sout << hryvna << "," << setw(2) << setfill('0') << static_cast<int>(kopek) << " UAH";
    return sout.str();
}

void Money::fromString(const string &s)
{
    stringstream sin(s);
    char comma;
    int kop;
    string currency;

    if (!(sin >> hryvna >> comma >> kop))
    {
        throw invalid_argument("Invalid numeric format");
    }

    if (sin >> currency && currency != "UAH")
    {
        throw invalid_argument("Invalid currency format");
    }

    if (!SetKopek(static_cast<unsigned char>(kop)))
    {
        throw invalid_argument("Invalid kopek value");
    }
}

ostream &operator<<(ostream &out, const Money &m)
{
    out << m.toString();
    return out;
}

istream &operator>>(istream &in, Money &m)
{
    string input;
    getline(in, input);
    try
    {
        m.fromString(input);
    }
    catch (const invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
        in.setstate(ios::failbit);
    }
    return in;
}
