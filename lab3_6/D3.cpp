// D3.cpp
#include "D3.h"

D3::D3(int bVal, int d1Val, int d3Val) : D1(bVal, d1Val), d3(d3Val) {}

int D3::get_d3() const
{
    return d3;
}

int D3::get_d1() const
{
    return d1;
}

int D3::get_b() const
{
    return b;
}

ostream &operator<<(ostream &out, const D3 &obj)
{
    out << static_cast<const D1 &>(obj) << ", D3: " << obj.d3;
    return out;
}
