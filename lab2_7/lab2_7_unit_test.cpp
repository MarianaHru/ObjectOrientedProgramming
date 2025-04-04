#include "lab2_7_unit_test.h"

TEST_F(FractionTest, AdditionTest)
{
    Fraction result = f1 + f2;
    EXPECT_EQ(result.GetFirst(), 5);
    EXPECT_EQ(result.GetSecond(), 75);
}

TEST_F(FractionTest, SubtractionTest)
{
    Fraction result = f1 - f2;
    EXPECT_EQ(result.GetFirst(), 1);
    EXPECT_EQ(result.GetSecond(), 25);
}

TEST_F(FractionTest, MultiplicationTest)
{
    Fraction result = f1 * f2;
    EXPECT_EQ(result.GetFirst(), 6);
    EXPECT_EQ(result.GetSecond(), 12);
}

TEST_F(FractionTest, EqualityTest)
{
    EXPECT_FALSE(f1 == f2);
}

TEST_F(FractionTest, InequalityTest)
{
    EXPECT_TRUE(f1 != f2);
}

TEST_F(FractionTest, ComparisonTest)
{
    EXPECT_TRUE(f1 > f2);
    EXPECT_FALSE(f1 < f2);
    EXPECT_TRUE(f1 >= f2);
    EXPECT_FALSE(f1 <= f2);
}

TEST_F(CalculatorTest, AdditionTest)
{
    Calculator result = c1 + c2;
    EXPECT_EQ(result.GetFraction().GetFirst(), 5);
    EXPECT_EQ(result.GetFraction().GetSecond(), 75);
}

TEST_F(CalculatorTest, SubtractionTest)
{
    Calculator result = c1 - c2;
    EXPECT_EQ(result.GetFraction().GetFirst(), 1);
    EXPECT_EQ(result.GetFraction().GetSecond(), 25);
}

TEST_F(CalculatorTest, MultiplicationTest)
{
    Calculator result = c1 * c2;
    EXPECT_EQ(result.GetFraction().GetFirst(), 6);
    EXPECT_EQ(result.GetFraction().GetSecond(), 12);
}

TEST_F(CalculatorTest, EqualityTest)
{
    EXPECT_FALSE(c1 == c2);
}

TEST_F(CalculatorTest, InequalityTest)
{
    EXPECT_TRUE(c1 != c2);
}

TEST_F(CalculatorTest, ComparisonTest)
{
    EXPECT_TRUE(c1 > c2);
    EXPECT_FALSE(c1 < c2);
    EXPECT_TRUE(c1 >= c2);
    EXPECT_FALSE(c1 <= c2);
}
