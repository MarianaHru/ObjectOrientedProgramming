#include "lab6_4.h"
#include <gtest/gtest.h>

TEST(MyVectorTest, AdditionCorrectness)
{
    MyVector<int> a(3);
    MyVector<int> b(3);

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    b[0] = 4;
    b[1] = 5;
    b[2] = 6;

    MyVector<int> result = a + b;

    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 7);
    EXPECT_EQ(result[2], 9);
}

TEST(MyVectorTest, ScalarMultiplication)
{
    MyVector<int> a(3);
    a[0] = 2;
    a[1] = -1;
    a[2] = 3;

    MyVector<int> result = a * 3;

    EXPECT_EQ(result[0], 6);
    EXPECT_EQ(result[1], -3);
    EXPECT_EQ(result[2], 9);
}

TEST(MyVectorTest, MismatchedAdditionThrows)
{
    MyVector<int> a(2);
    MyVector<int> b(3);

    EXPECT_THROW(a + b, std::runtime_error);
}

TEST(MyVectorTest, OutOfRangeIndexThrows)
{
    MyVector<int> a(2);
    EXPECT_THROW(a[-1], std::out_of_range);
    EXPECT_THROW(a[2], std::out_of_range);
}
