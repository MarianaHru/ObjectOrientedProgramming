#ifndef FRACTION_TEST_H
#define FRACTION_TEST_H

#include "Fraction.h"
#include <gtest/gtest.h>

class FractionTest : public ::testing::Test
{
protected:
    Fraction f1;
    Fraction f2{3, 4};
    Fraction f3{5, 6};
};

#endif
