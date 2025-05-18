// lab7_1_unit_test.cpp
#include <gtest/gtest.h>
#include "lab7_1.h"
#include <vector>

TEST(CountOddElementsTest, NoOddElements)
{
    std::vector<int> a = {2, 4, 6, 8};
    EXPECT_EQ(count_odd_elements(a), 0);
}

TEST(CountOddElementsTest, AllOddElements)
{
    std::vector<int> a = {1, 3, 5, 7, 9};
    EXPECT_EQ(count_odd_elements(a), 5);
}

TEST(CountOddElementsTest, MixedElements)
{
    std::vector<int> a = {1, 2, 3, 4, 5};
    EXPECT_EQ(count_odd_elements(a), 3);
}

TEST(CountOddElementsTest, EmptyArray)
{
    std::vector<int> a;
    EXPECT_EQ(count_odd_elements(a), 0);
}

TEST(CountOddElementsTest, SingleEven)
{
    std::vector<int> a = {2};
    EXPECT_EQ(count_odd_elements(a), 0);
}

TEST(CountOddElementsTest, SingleOdd)
{
    std::vector<int> a = {7};
    EXPECT_EQ(count_odd_elements(a), 1);
}
