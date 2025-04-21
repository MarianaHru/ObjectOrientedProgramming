
// D2.cpp
#include "D2.h"

D2::D2(int bVal, int d2Val) : B(bVal), d2(d2Val) {}

int D2::get_d2() const
{
    return d2;
}

int D2::get_b() const
{
    return b;
}

ostream &operator<<(ostream &out, const D2 &obj)
{
    out << "B (from D2): " << obj.b << ", D2: " << obj.d2;
    return out;
}
