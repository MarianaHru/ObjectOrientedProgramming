#include "gtest/gtest.h"
#include "Vector.h"

TEST(VectorTest, DefaultConstructor)
{
    Vector v;
    EXPECT_EQ(v.GetSize(), 0);
    EXPECT_EQ(v.GetDate(), nullptr);
}

TEST(VectorTest, SizeConstructor)
{
    Vector v(5);
    EXPECT_EQ(v.GetSize(), 5);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(v.GetDate()[i], 0);
    }
}

TEST(VectorTest, SizeAndValueConstructor)
{
    int values[] = {1, 2, 3, 4, 5};
    Vector v(5, values);
    EXPECT_EQ(v.GetSize(), 5);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(v.GetDate()[i], values[i]);
    }
}

TEST(VectorTest, CopyConstructor)
{
    int values[] = {1, 2, 3, 4, 5};
    Vector v1(5, values);
    Vector v2(v1);
    EXPECT_EQ(v2.GetSize(), 5);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(v2.GetDate()[i], values[i]);
    }
}

TEST(VectorTest, SetSize)
{
    Vector v;
    EXPECT_TRUE(v.SetSize(3));
    EXPECT_EQ(v.GetSize(), 3);
}

TEST(VectorTest, SetSizeNegative)
{
    Vector v;
    EXPECT_FALSE(v.SetSize(-1));
}

TEST(VectorTest, StringConversion)
{
    int values[] = {1, 2, 3};
    Vector v(3, values);
    EXPECT_EQ(std::string(v), "Vector: [1,2,3]");
}

TEST(VectorTest, Equality)
{
    int values1[] = {1, 2, 3};
    int values2[] = {1, 2, 3};
    int values3[] = {1, 2, 4};
    Vector v1(3, values1);
    Vector v2(3, values2);
    Vector v3(3, values3);
    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
}

TEST(VectorTest, ScalarMultiplication)
{
    int values[] = {1, 2, 3};
    Vector v(3, values);
    Vector result = v * 2;
    EXPECT_EQ(result.GetDate()[0], 2);
    EXPECT_EQ(result.GetDate()[1], 4);
    EXPECT_EQ(result.GetDate()[2], 6);
}

TEST(VectorTest, Norm)
{
    int values[] = {3, 4, 0};
    Vector v(3, values);
    EXPECT_DOUBLE_EQ(norm(v), 5.0);
}