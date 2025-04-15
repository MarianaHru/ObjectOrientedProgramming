// Money_test.h
#pragma once
#include "gtest/gtest.h"
#include "Money.h"

TEST(MoneyTest, DefaultConstructor)
{
    Money m;
    ASSERT_EQ(m.toString(), "0.00");
}

TEST(MoneyTest, ValueConstructor)
{
    Money m(10, 50);
    ASSERT_EQ(m.toString(), "10.50");
}

TEST(MoneyTest, CopyConstructor)
{
    Money m1(5, 20);
    Money m2(m1);
    ASSERT_EQ(m2.toString(), "5.20");
}

TEST(MoneyTest, InitMethod)
{
    Money m;
    m.Init(25, 99);
    ASSERT_EQ(m.toString(), "25.99");
}

TEST(MoneyTest, Addition)
{
    Money m1(1, 50);
    Money m2(2, 25);
    Money sum = m1 + m2;
    ASSERT_EQ(sum.toString(), "3.75");
}

TEST(MoneyTest, DivisionByDouble)
{
    Money m(10, 0);
    Money div = m / 2.0;
    ASSERT_EQ(div.toString(), "5.00");
}

TEST(MoneyTest, DivisionByMoney)
{
    Money m1(10, 0);
    Money m2(2, 0);
    ASSERT_NEAR(m1 / m2, 5.0, 0.001);
}

TEST(MoneyTest, PrefixIncrement)
{
    Money m(1, 99);
    ++m;
    ASSERT_EQ(m.toString(), "2.00");
}

TEST(MoneyTest, PostfixIncrement)
{
    Money m(1, 98);
    Money m2 = m++;
    ASSERT_EQ(m.toString(), "1.99");
    ASSERT_EQ(m2.toString(), "1.98");
}

TEST(MoneyTest, PrefixDecrement)
{
    Money m(2, 0);
    --m;
    ASSERT_EQ(m.toString(), "1.99");
}

TEST(MoneyTest, PostfixDecrement)
{
    Money m(2, 1);
    Money m2 = m--;
    ASSERT_EQ(m.toString(), "2.00");
    ASSERT_EQ(m2.toString(), "2.01");
}

TEST(MoneyTest, AssignmentOperator)
{
    Money m1(3, 45);
    Money m2;
    m2 = m1;
    ASSERT_EQ(m2.toString(), "3.45");
}

TEST(MoneyTest, ToStringConversion)
{
    Money m(7, 10);
    std::string str = static_cast<std::string>(m);
    ASSERT_EQ(str, "7.10");
}

TEST(MoneyTest, GetCount)
{
    int initialCount = Object::getCount();
    Money m1;
    Money m2(1, 0);
    Money m3(m2);
    ASSERT_EQ(Object::getCount(), initialCount + 3);
}