#include "D4.h"

D4::D4(int b2, int d2Val, int b1, int d1Val, int d4Val)
    : D2(b2, d2Val), D1(b1, d1Val), d4(d4Val) {}

int D4::get_d4() const
{
    return d4;
}

int D4::get_d2() const
{
    return d2;
}

int D4::get_d1() const
{
    return d1;
}

int D4::get_b() const
{
    return D2::get_b(); // або D1::get_b()
}

std::ostream &operator<<(std::ostream &out, const D4 &obj)
{
    out << static_cast<const D2 &>(obj) << ", "
        << static_cast<const D1 &>(obj) << ", D4: " << obj.d4;
    return out;
}
