#pragma once
#include "Calculator.h"
#include <gtest/gtest.h>

class CalculatorTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        c1 = Calculator(Calculator::Fraction(3, 50));
        c2 = Calculator(Calculator::Fraction(2, 25));
    }

    Calculator c1, c2;
};

class FractionTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        f1 = Calculator::Fraction(3, 50);
        f2 = Calculator::Fraction(2, 25);
    }

    Calculator::Fraction f1, f2;
};