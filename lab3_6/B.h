// B.h
#pragma once
#include <iostream>
using namespace std;

class B
{
protected:
    int b;

public:
    B(int value = 0);
    int get_b() const;
    friend ostream &operator<<(ostream &out, const B &obj);
};
