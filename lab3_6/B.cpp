
// B.cpp
#include "B.h"

B::B(int value) : b(value) {}

int B::get_b() const
{
    return b;
}

ostream &operator<<(ostream &out, const B &obj)
{
    out << "B: " << obj.b;
    return out;
}
