#ifndef TEST_PAIR_H
#define TEST_PAIR_H

#include "gtest/gtest.h"
#include "Pair.h"

TEST(PairTest, DefaultConstructor)
{
    Pair p;
    EXPECT_EQ(0, p.getFirst());
    EXPECT_EQ(0, p.getSecond());
}

TEST(PairTest, ParameterizedConstructor)
{
    Pair p(5, 10);
    EXPECT_EQ(5, p.getFirst());
    EXPECT_EQ(10, p.getSecond());
}

TEST(PairTest, InitMethod)
{
    Pair p;
    p.Init(15, 20);
    EXPECT_EQ(15, p.getFirst());
    EXPECT_EQ(20, p.getSecond());
}

TEST(PairTest, ToStringMethod)
{
    Pair p(1, 2);
    EXPECT_EQ("(1, 2)", p.toString());
}

TEST(PairTest, EqualityOperator)
{
    Pair p1(3, 4);
    Pair p2(3, 4);
    EXPECT_TRUE(p1 == p2);
}

TEST(PairTest, InequalityOperator)
{
    Pair p1(5, 6);
    Pair p2(7, 8);
    EXPECT_TRUE(p1 != p2);
}

TEST(PairTest, GreaterThanOperator)
{
    Pair p1(10, 5);
    Pair p2(9, 15);
    EXPECT_TRUE(p1 > p2);
    Pair p3(10, 10);
    EXPECT_FALSE(p1 > p3);
}

TEST(PairTest, LessThanOperator)
{
    Pair p1(2, 8);
    Pair p2(5, 3);
    EXPECT_TRUE(p1 < p2);
    Pair p3(2, 10);
    EXPECT_TRUE(p1 < p3);
}

#endif