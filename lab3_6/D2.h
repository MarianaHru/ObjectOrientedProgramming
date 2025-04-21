// D2.h
#pragma once
#include "B.h"

class D2 : private B
{
protected:
    int d2;

public:
    D2(int bVal = 0, int d2Val = 0);
    int get_d2() const;
    int get_b() const;
    friend ostream &operator<<(ostream &out, const D2 &obj);
};
