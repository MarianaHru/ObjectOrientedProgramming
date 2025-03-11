#include <gtest/gtest.h>
#include "Fraction.h"

// Тест конструктора
TEST(FractionTest, ConstructorTest)
{
    Fraction f(3, 4);
    EXPECT_EQ(f.getFirst(), 3);
    EXPECT_EQ(f.getSecond(), 4);
}

// Тест ініціалізації
TEST(FractionTest, InitTest)
{
    Fraction f;
    EXPECT_TRUE(f.Init(5, 6));
    EXPECT_EQ(f.getFirst(), 5);
    EXPECT_EQ(f.getSecond(), 6);
    EXPECT_FALSE(f.Init(-3, 4)); // Перевірка на некоректні значення
}

// Тест встановлення чисельника
TEST(FractionTest, SetFirstTest)
{
    Fraction f;
    f.setFirst(7);
    EXPECT_EQ(f.getFirst(), 7);
}

// Тест встановлення знаменника
TEST(FractionTest, SetSecondTest)
{
    Fraction f;
    f.setSecond(8);
    EXPECT_EQ(f.getSecond(), 8);
}

// Тест цілочисельної частини дробу
TEST(FractionTest, IntegerPartTest)
{
    Fraction f(10, 3);
    EXPECT_EQ(f.ipart(), 3);
}

// Тест створення об'єкта через makeFraction
TEST(FractionTest, MakeFractionTest)
{
    Fraction f = makeFraction(9, 2);
    EXPECT_EQ(f.getFirst(), 9);
    EXPECT_EQ(f.getSecond(), 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
