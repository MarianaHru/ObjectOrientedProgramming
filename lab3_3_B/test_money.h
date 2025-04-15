#ifndef TEST_MONEY_H
#define TEST_MONEY_H

#include "gtest/gtest.h"
#include "Money.h"

TEST(MoneyTest, DefaultConstructor)
{
    Money m;
    EXPECT_EQ(0, m.GetHryvna());
    EXPECT_EQ(0, m.GetKopek());
}

TEST(MoneyTest, ParameterizedConstructor)
{
    Money m(10, 50);
    EXPECT_EQ(10, m.GetHryvna());
    EXPECT_EQ(50, m.GetKopek());
}

TEST(MoneyTest, InitMethod)
{
    Money m;
    m.Init(25, 75);
    EXPECT_EQ(25, m.GetHryvna());
    EXPECT_EQ(75, m.GetKopek());
}

TEST(MoneyTest, ToStringMethod)
{
    Money m(5, 5);
    EXPECT_EQ("5,05", m.toString());
    Money m2(100, 0);
    EXPECT_EQ("100,00", m2.toString());
    Money m3(0, 99);
    EXPECT_EQ("0,99", m3.toString());
}

TEST(MoneyTest, AdditionOperator)
{
    Money m1(10, 20);
    Money m2(5, 30);
    Money sum = m1 + m2;
    EXPECT_EQ(15, sum.GetHryvna());
    EXPECT_EQ(50, sum.GetKopek());
}

TEST(MoneyTest, SubtractionOperator)
{
    Money m1(20, 50);
    Money m2(10, 25);
    Money diff = m1 - m2;
    EXPECT_EQ(10, diff.GetHryvna());
    EXPECT_EQ(25, diff.GetKopek());
}

TEST(MoneyTest, DivisionByMoneyOperator)
{
    Money m1(10, 0);
    Money m2(2, 0);
    EXPECT_NEAR(5.0, m1 / m2, 0.0001);
}

TEST(MoneyTest, DivisionByDoubleOperator)
{
    Money m(10, 50);
    Money result = m / 2.0;
    EXPECT_EQ(5, result.GetHryvna());
    EXPECT_EQ(25, result.GetKopek());
}

TEST(MoneyTest, GreaterThanOperator)
{
    Money m1(10, 50);
    Money m2(10, 49);
    EXPECT_TRUE(m1 > m2);
    Money m3(11, 0);
    EXPECT_TRUE(m3 > m1);
}

TEST(MoneyTest, LessThanOperator)
{
    Money m1(5, 20);
    Money m2(5, 21);
    EXPECT_TRUE(m1 < m2);
    Money m3(4, 99);
    EXPECT_TRUE(m3 < m1);
}

#endif