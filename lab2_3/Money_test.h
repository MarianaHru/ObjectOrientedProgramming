#pragma once
#include "Money.h"
#include <gtest/gtest.h>

TEST(MoneyTest, DefaultConstructor)
{
    Money m;
    EXPECT_EQ(m.GetHryvna(), 0);
    EXPECT_EQ(m.GetKopek(), 0);
}

TEST(MoneyTest, ParameterizedConstructor)
{
    Money m(10, 50);
    EXPECT_EQ(m.GetHryvna(), 10);
    EXPECT_EQ(m.GetKopek(), 50);
}

TEST(MoneyTest, CopyConstructor)
{
    Money m1(5, 75);
    Money m2(m1);
    EXPECT_EQ(m2.GetHryvna(), 5);
    EXPECT_EQ(m2.GetKopek(), 75);
}

TEST(MoneyTest, AdditionOperator)
{
    Money m1(5, 50);
    Money m2(3, 75);
    Money result = m1 + m2;
    EXPECT_EQ(result.GetHryvna(), 9);
    EXPECT_EQ(result.GetKopek(), 25);
}

TEST(MoneyTest, DivisionOperator)
{
    Money m1(10, 0);
    Money m2(2, 0);
    EXPECT_DOUBLE_EQ(m1 / m2, 5.0);
}

TEST(MoneyTest, DivisionByZero)
{
    Money m1(10, 50);
    Money m2(0, 0);
    EXPECT_THROW(m1 / m2, std::invalid_argument);
}

TEST(MoneyTest, DivisionByNumber)
{
    Money m(10, 0);
    Money result = m / 2;
    EXPECT_EQ(result.GetHryvna(), 5);
    EXPECT_EQ(result.GetKopek(), 0);
}

TEST(MoneyTest, DivisionByZeroNumber)
{
    Money m(10, 50);
    EXPECT_THROW(m / 0, std::invalid_argument);
}

TEST(MoneyTest, PrefixIncrement)
{
    Money m(10, 99);
    ++m;
    EXPECT_EQ(m.GetHryvna(), 11);
    EXPECT_EQ(m.GetKopek(), 0);
}

TEST(MoneyTest, PostfixIncrement)
{
    Money m(10, 99);
    Money m2 = m++;
    EXPECT_EQ(m2.GetHryvna(), 10);
    EXPECT_EQ(m2.GetKopek(), 99);
    EXPECT_EQ(m.GetHryvna(), 11);
    EXPECT_EQ(m.GetKopek(), 0);
}

TEST(MoneyTest, PrefixDecrement)
{
    Money m(11, 0);
    --m;
    EXPECT_EQ(m.GetHryvna(), 10);
    EXPECT_EQ(m.GetKopek(), 99);
}

TEST(MoneyTest, PostfixDecrement)
{
    Money m(11, 0);
    Money m2 = m--;
    EXPECT_EQ(m2.GetHryvna(), 11);
    EXPECT_EQ(m2.GetKopek(), 0);
    EXPECT_EQ(m.GetHryvna(), 10);
    EXPECT_EQ(m.GetKopek(), 99);
}

TEST(MoneyTest, ToStringTest)
{
    Money m(7, 5);
    std::string expected = "7,05 UAH";
    EXPECT_EQ(std::string(m), expected);
}
