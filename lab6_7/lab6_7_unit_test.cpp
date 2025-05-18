#include "lab6_7_unit_test.h"
#include <gtest/gtest.h>

TEST(Lab6_7_Tests, GenerateArrayCorrectSize)
{
    size_t size = 5;
    auto arr = generateRandomArray(size);
    EXPECT_EQ(arr.size(), size);
}

TEST(Lab6_7_Tests, CopyArrayMatchesOriginal)
{
    std::vector<int> original = {1, 2, 3, -4, 5};
    auto copied = copyArray(original);
    EXPECT_EQ(copied, original);
}

TEST(Lab6_7_Tests, CopyIfPositiveOnlyPositive)
{
    std::vector<int> original = {-10, 0, 5, 7, -3, 12};
    auto filtered = copyIfPositive(original);

    std::vector<int> expected = {5, 7, 12};
    EXPECT_EQ(filtered, expected);
}

TEST(Lab6_7_Tests, CopyIfPositiveEmptyResult)
{
    std::vector<int> original = {-5, -8, 0, -1};
    auto filtered = copyIfPositive(original);

    EXPECT_TRUE(filtered.empty());
}
