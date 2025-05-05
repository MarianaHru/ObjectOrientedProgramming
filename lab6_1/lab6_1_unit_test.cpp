#include <gtest/gtest.h>
#include "lab6_1_unit_test.h"
#include <cmath>

TEST(ArrayConstructorTest, ThrowsOnZeroSize)
{
    EXPECT_THROW(Array a(0), std::invalid_argument);
}

TEST(ArrayConstructorTest, ValidSizeInitialization)
{
    Array a(5);
    EXPECT_EQ(a.size(), 5);
    EXPECT_EQ(a.capacity(), 5);
    for (size_t i = 0; i < 5; ++i)
        EXPECT_EQ(a[i], 0);
}

TEST(ArrayOperatorTest, IndexOperatorThrows)
{
    Array a(3);
    EXPECT_THROW(a[10], std::out_of_range);
}

TEST(ArrayPushBackTest, ExpandsArrayAndAddsElements)
{
    Array a(2);
    a.push_back(1.5);
    a.push_back(2.5);
    a.push_back(3.5);
    EXPECT_EQ(a.size(), 5);
    EXPECT_DOUBLE_EQ(a[2], 1.5);
    EXPECT_DOUBLE_EQ(a[3], 2.5);
    EXPECT_DOUBLE_EQ(a[4], 3.5);
}

TEST(CreateDynamicArrayTest, CorrectComputation)
{
    int arr[] = {1, 3, 5};
    Array result = createDynamicArray(arr, 3);

    EXPECT_EQ(result.size(), 5);

    EXPECT_DOUBLE_EQ(result[0], -4);
    EXPECT_DOUBLE_EQ(result[1], -2);
    EXPECT_DOUBLE_EQ(result[2], 0);

    EXPECT_DOUBLE_EQ(result[3], -6);
    EXPECT_DOUBLE_EQ(result[4], 2.0);
}
TEST(CreateDynamicArrayTest, EmptyInput)
{
    int *empty = nullptr;
    EXPECT_THROW(createDynamicArray(empty, 0), std::invalid_argument);
}
