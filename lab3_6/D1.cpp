
// D1.cpp
#include "D1.h"

D1::D1(int bVal, int d1Val) : B(bVal), d1(d1Val) {}

int D1::get_d1() const
{
    return d1;
}

ostream &operator<<(ostream &out, const D1 &obj)
{
    out << static_cast<const B &>(obj) << ", D1: " << obj.d1;
    return out;
}
