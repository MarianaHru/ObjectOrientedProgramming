#ifndef LAB5_1_A_UNIT_TEST_H
#define LAB5_1_A_UNIT_TEST_H

#include "Fraction.h"
#include <gtest/gtest.h>

class FractionTest : public ::testing::Test
{
protected:
    Fraction f1;
    Fraction f2;
    Fraction f3;

    void SetUp() override
    {
        f1 = Fraction();
        f2 = Fraction(3, 4);
        f3 = Fraction(f2);
    }
};

#endif
