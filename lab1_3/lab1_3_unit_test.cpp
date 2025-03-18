#include <gtest/gtest.h>
#include "Money.h"

TEST(MoneyTest, Addition)
{
    Money m1(5, 50);
    Money m2(3, 75);
    Money result = m1 + m2;
    EXPECT_EQ(result.GetFirst(), 9);
    EXPECT_EQ(result.GetSecond(), 25);
}

TEST(MoneyTest, DivisionByMoney)
{
    Money m1(10, 0);
    Money m2(5, 0);
    EXPECT_DOUBLE_EQ(m1 / m2, 2.0);
}

TEST(MoneyTest, DivisionByZeroMoney)
{
    Money m1(10, 0);
    Money m2(0, 0);
    EXPECT_THROW(m1 / m2, std::invalid_argument);
}

TEST(MoneyTest, DivisionByDouble)
{
    Money m1(10, 0);
    Money result = m1 / 2.0;
    EXPECT_EQ(result.GetFirst(), 5);
    EXPECT_EQ(result.GetSecond(), 0);
}

TEST(MoneyTest, DivisionByZeroDouble)
{
    Money m1(10, 0);
    EXPECT_THROW(m1 / 0.0, std::invalid_argument);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
