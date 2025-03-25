#include "Fraction_test.h"

TEST_F(FractionTest, DefaultConstructor)
{
    EXPECT_EQ(f1.getFirst(), 0);
    EXPECT_EQ(f1.getSecond(), 1);
}

TEST_F(FractionTest, ParameterizedConstructor)
{
    EXPECT_EQ(f2.getFirst(), 3);
    EXPECT_EQ(f2.getSecond(), 4);
}

TEST_F(FractionTest, CopyConstructor)
{
    Fraction fCopy = f2;
    EXPECT_EQ(fCopy.getFirst(), 3);
    EXPECT_EQ(fCopy.getSecond(), 4);
}

TEST_F(FractionTest, InitMethod)
{
    f1.Init(7, 8);
    EXPECT_EQ(f1.getFirst(), 7);
    EXPECT_EQ(f1.getSecond(), 8);
}

TEST_F(FractionTest, IncrementOperators)
{
    Fraction f{1, 2};

    ++f;
    EXPECT_EQ(f.getFirst(), 2);
    EXPECT_EQ(f.getSecond(), 2);

    Fraction temp = f++;
    EXPECT_EQ(temp.getFirst(), 2);
    EXPECT_EQ(temp.getSecond(), 2);
    EXPECT_EQ(f.getSecond(), 3);
}

TEST_F(FractionTest, DecrementOperators)
{
    Fraction f{5, 6};

    --f;
    EXPECT_EQ(f.getFirst(), 4);
    EXPECT_EQ(f.getSecond(), 6);

    Fraction temp = f--;
    EXPECT_EQ(temp.getFirst(), 4);
    EXPECT_EQ(temp.getSecond(), 6);
    EXPECT_EQ(f.getSecond(), 5);
}

TEST_F(FractionTest, ToString)
{
    EXPECT_EQ(f2.toString(), "3/4");
    EXPECT_EQ(f3.toString(), "5/6");
}

TEST(FractionStandaloneTest, MakeFraction)
{
    Fraction f = makeFraction(9, 10);
    EXPECT_EQ(f.getFirst(), 9);
    EXPECT_EQ(f.getSecond(), 10);
}
