#include "gtest/gtest.h"
#include "Liquid.h"
#include "Alcohol.h"

TEST(LiquidTest, ConstructorAndGetters)
{
    Liquid l("Water", 1.0);
    ASSERT_EQ(l.getName(), "Water");
    ASSERT_DOUBLE_EQ(l.getDensity(), 1.0);
}

TEST(LiquidTest, Setters)
{
    Liquid l;
    l.setName("Juice");
    l.setDensity(1.2);
    ASSERT_EQ(l.getName(), "Juice");
    ASSERT_DOUBLE_EQ(l.getDensity(), 1.2);
}

TEST(AlcoholTest, ConstructorAndGetters)
{
    Liquid l("Vodka", 0.9);
    Alcohol a(l, 40.0);
    ASSERT_EQ(static_cast<std::string>(a), "Liquid: Vodka | Density: 0.900000 | Strength: 40.000000%");
}

TEST(AlcoholTest, SetStrength)
{
    Liquid l("Wine", 1.0);
    Alcohol a(l, 12.0);
    a.setStrength(13.5);
    ASSERT_EQ(static_cast<std::string>(a), "Liquid: Wine | Density: 1.000000 | Strength: 13.500000%");
}

TEST(AlcoholTest, IncrementDecrement)
{
    Liquid l("Beer", 1.0);
    Alcohol a(l, 5.0);
    ++a;
    ASSERT_EQ(static_cast<std::string>(a), "Liquid: Beer | Density: 1.000000 | Strength: 6.000000%");
    a--;
    ASSERT_EQ(static_cast<std::string>(a), "Liquid: Beer | Density: 1.000000 | Strength: 5.000000%");
}