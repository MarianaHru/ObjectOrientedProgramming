#pragma once
#include "Calculator.h"
#include <gtest/gtest.h>

TEST(FractionTest, Addition)
{
    Calculator::Fraction f1(3, 25);
    Calculator::Fraction f2(2, 75);
    Calculator::Fraction result = Calculator::Add(f1, f2);
    EXPECT_EQ(result.GetIntegerPart(), 5);
    EXPECT_EQ(result.GetFractionalPart(), 100);
}

TEST(FractionTest, Subtraction)
{
    Calculator::Fraction f1(5, 50);
    Calculator::Fraction f2(2, 25);
    Calculator::Fraction result = Calculator::Subtract(f1, f2);
    EXPECT_EQ(result.GetIntegerPart(), 3);
    EXPECT_EQ(result.GetFractionalPart(), 25);
}

TEST(FractionTest, Multiplication)
{
    Calculator::Fraction f1(2, 10);
    Calculator::Fraction f2(3, 5);
    Calculator::Fraction result = Calculator::Multiply(f1, f2);
    EXPECT_EQ(result.GetIntegerPart(), 6);
    EXPECT_EQ(result.GetFractionalPart(), 50);
}

TEST(FractionTest, Comparison)
{
    Calculator::Fraction f1(4, 20);
    Calculator::Fraction f2(4, 20);
    EXPECT_TRUE(Calculator::Compare(f1, f2));
    Calculator::Fraction f3(5, 30);
    EXPECT_FALSE(Calculator::Compare(f1, f3));
}
