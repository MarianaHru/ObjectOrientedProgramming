#include "Money.h"
#include "MoneyException.h"
#include <gtest/gtest.h>

// Основні операції
TEST(MoneyTest, ConstructorAndToString)
{
    Money m(12, 5);
    EXPECT_EQ((std::string)m, "12,05 UAH");
}

TEST(MoneyTest, Addition)
{
    Money m1(10, 50);
    Money m2(5, 75);
    Money result = m1 + m2;
    EXPECT_EQ((std::string)result, "16,25 UAH");
}

TEST(MoneyTest, DivisionByMoney)
{
    Money m1(10, 0);
    Money m2(5, 0);
    double ratio = m1 / m2;
    EXPECT_DOUBLE_EQ(ratio, 2.0);
}

TEST(MoneyTest, DivisionByDouble)
{
    Money m(10, 0);
    Money result = m / 2.0;
    EXPECT_EQ((std::string)result, "5,00 UAH");
}

// Інкременти / декременти
TEST(MoneyTest, PrefixIncrement)
{
    Money m(1, 99);
    ++m;
    EXPECT_EQ((std::string)m, "2,00 UAH");
}

TEST(MoneyTest, PostfixDecrement)
{
    Money m(2, 0);
    Money old = m--;
    EXPECT_EQ((std::string)old, "2,00 UAH");
    EXPECT_EQ((std::string)m, "1,99 UAH");
}

// Винятки
TEST(MoneyTest, InvalidKopekThrows)
{
    EXPECT_THROW(Money(10, 150), std::invalid_argument);
}

TEST(MoneyTest, FromStringInvalidCurrency)
{
    Money m;
    EXPECT_THROW(m.fromString("100,50 USD"), MoneyException);
}

TEST(MoneyTest, DivisionByZeroMoneyThrows)
{
    Money m1(10, 0);
    Money m2(0, 0);
    EXPECT_THROW(m1 / m2, std::domain_error);
}

TEST(MoneyTest, DivisionByZeroDoubleThrows)
{
    Money m(10, 0);
    EXPECT_THROW(m / 0.0, MoneyException);
}

TEST(MoneyTest, DecrementBelowZeroThrows)
{
    Money m(0, 0);
    EXPECT_THROW(m--, std::underflow_error *);
}
