// D1.h
#pragma once
#include "B.h"

class D1 : public B
{
protected:
    int d1;

public:
    D1(int bVal = 0, int d1Val = 0);
    int get_d1() const;
    friend ostream &operator<<(ostream &out, const D1 &obj);
};
