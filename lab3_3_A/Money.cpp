#include "Money.h"
#include <string>
#include <sstream>

Money::Money() : hryvnia(0), kopiyky(0) {}
Money::Money(long h, unsigned char k) : hryvnia(h), kopiyky(k) {}
Money::Money(const Money &m) : hryvnia(m.hryvnia), kopiyky(m.kopiyky) {}

void Money::Init(long h, unsigned char k)
{
    hryvnia = h;
    kopiyky = k;
}

void Money::Read()
{
    long h;
    int k;
    cout << "Hryvnia: ";
    cin >> h;
    cout << "Kopiyky: ";
    cin >> k;
    Init(h, k);
}

void Money::Display() const
{
    cout << hryvnia << " грн " << (int)kopiyky << " коп" << endl;
}

Money::operator string() const
{
    stringstream ss;
    ss << hryvnia << " грн " << (int)kopiyky << " коп";
    return ss.str();
}

ostream &operator<<(ostream &out, const Money &m)
{
    out << (string)m;
    return out;
}

istream &operator>>(istream &in, Money &m)
{
    long h;
    int k;
    in >> h >> k;
    m.Init(h, k);
    return in;
}