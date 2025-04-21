#pragma once
#include "D2.h"
#include "D1.h"

class D4 : public D2, private D1
{
protected:
    int d4;

public:
    D4(int b2 = 0, int d2Val = 0, int b1 = 0, int d1Val = 0, int d4Val = 0);

    int get_d4() const;
    int get_d2() const;
    int get_d1() const;
    int get_b() const;

    friend std::ostream &operator<<(std::ostream &out, const D4 &obj);
};
