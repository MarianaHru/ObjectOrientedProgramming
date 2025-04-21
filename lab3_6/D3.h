// D3.h
#pragma once
#include "D1.h"

class D3 : private D1
{
protected:
    int d3;

public:
    D3(int bVal = 0, int d1Val = 0, int d3Val = 0);
    int get_d3() const;
    int get_d1() const;
    int get_b() const;
    friend ostream &operator<<(ostream &out, const D3 &obj);
};
