#include "gtest/gtest.h"
#include "B.h"
#include "D1.h"
#include "D2.h"
#include "D3.h"
#include "D4.h"

TEST(ClassBTest, Initialization)
{
    B obj(10);
    EXPECT_EQ(obj.get_b(), 10);
}

TEST(ClassD1Test, Initialization)
{
    D1 obj(20, 30);
    EXPECT_EQ(obj.get_b(), 20);
    EXPECT_EQ(obj.get_d1(), 30);
}

TEST(ClassD2Test, Initialization)
{
    D2 obj(40, 50);
    EXPECT_EQ(obj.get_b(), 40);
    EXPECT_EQ(obj.get_d2(), 50);
}

TEST(ClassD4Test, Initialization)
{
    D4 obj(60, 70, 0, 0, 80);
    EXPECT_EQ(obj.get_b(), 60);
    EXPECT_EQ(obj.get_d2(), 70);
    EXPECT_EQ(obj.get_d4(), 80);
}

TEST(ClassD3Test, Initialization)
{
    D3 obj(90, 100, 110);
    EXPECT_EQ(obj.get_b(), 90);
    EXPECT_EQ(obj.get_d1(), 100);
    EXPECT_EQ(obj.get_d3(), 110);
}
