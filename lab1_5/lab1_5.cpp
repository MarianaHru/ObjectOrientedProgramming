#include "Alcohol.h"

#ifndef UNIT_TESTING

int main()
{
    Alcohol a1;
    a1.Read();
    a1.Display();

    Liquid l1;
    l1.Init("Water", 1.0);
    Alcohol a2;
    a2.Init(l1, 40.0);
    a2.Display();

    return 0;
}

#endif