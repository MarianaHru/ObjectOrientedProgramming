
// test_fraction.cpp
#include "Fraction.h"
#include "Calculator.h"
#include <gtest/gtest.h>

TEST(FractionTest, Addition)
{
    Fraction f1(3, 50);
    Fraction f2(2, 25);
    Fraction result = f1 + f2;
    EXPECT_EQ(result.GetIntegerPart(), 5);
    EXPECT_EQ(result.GetFractionalPart(), 75);
}

TEST(FractionTest, Subtraction)
{
    Fraction f1(5, 80);
    Fraction f2(2, 30);
    Fraction result = f1 - f2;
    EXPECT_EQ(result.GetIntegerPart(), 3);
    EXPECT_EQ(result.GetFractionalPart(), 50);
}

TEST(FractionTest, Multiplication)
{
    Fraction f1(3, 10);
    Fraction f2(2, 5);
    Fraction result = f1 * f2;
    EXPECT_EQ(result.GetIntegerPart(), 6);
    EXPECT_EQ(result.GetFractionalPart(), 50);
}

TEST(FractionTest, Comparison)
{
    Fraction f1(4, 20);
    Fraction f2(4, 20);
    EXPECT_TRUE(f1 == f2);
    EXPECT_FALSE(f1 != f2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
