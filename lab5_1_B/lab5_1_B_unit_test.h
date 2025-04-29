#pragma once

#include "Money.h"
#include <gtest/gtest.h>

class Lab5_1_B_Test : public ::testing::Test
{
protected:
    Money m1;
    Money m2;
    Money expectedSum;

    Lab5_1_B_Test()
        : m1(Fraction(1, 2)),
          m2(Fraction(2, 3)),
          expectedSum(m1.add(m2))
    {
    }
};
