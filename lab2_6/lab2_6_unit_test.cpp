#include "Alcohol.h"
#include "gtest/gtest.h"

// TEST(AlcoholTest, ConstructorAndGetters)
// {
//     Alcohol a("Сік", 1.05, 0);
//     EXPECT_EQ(string(a.liquid), "Liquid: Сік | Density: 1.05");
//     EXPECT_EQ(string(a), "Liquid: Сік | Density: 1.05 | Strength: 0%");
// }

TEST(AlcoholTest, CopyConstructor)
{
    Alcohol a1("Whiskey", 0.94, 43);
    Alcohol a2(a1);
    EXPECT_EQ(string(a2), "Liquid: Whiskey | Density: 0.94 | Strength: 43%");
}

TEST(AlcoholTest, AssignmentOperator)
{
    Alcohol a1("Rum", 0.95, 40);
    Alcohol a2;
    a2 = a1;
    EXPECT_EQ(string(a2), "Liquid: Rum | Density: 0.95 | Strength: 40%");
}

TEST(AlcoholTest, IncrementAndDecrement)
{
    Alcohol a("Beer", 1.01, 5);
    EXPECT_EQ(string(++a), "Liquid: Beer | Density: 1.01 | Strength: 6%");
    EXPECT_EQ(string(a++), "Liquid: Beer | Density: 1.01 | Strength: 6%");
    EXPECT_EQ(string(a), "Liquid: Beer | Density: 1.01 | Strength: 7%");
    EXPECT_EQ(string(--a), "Liquid: Beer | Density: 1.01 | Strength: 6%");
    EXPECT_EQ(string(a--), "Liquid: Beer | Density: 1.01 | Strength: 6%");
    EXPECT_EQ(string(a), "Liquid: Beer | Density: 1.01 | Strength: 5%");
}

TEST(AlcoholTest, InitMethod)
{
    Alcohol a;
    a.Init("Wine", 0.99, 12);
    EXPECT_EQ(string(a), "Liquid: Wine | Density: 0.99 | Strength: 12%");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}