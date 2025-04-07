#include "Liquid.h"
#include "Alcohol.h"
#include <gtest/gtest.h>

// Тестування класу Liquid
TEST(LiquidTest, DefaultConstructor)
{
    Liquid liquid;
    EXPECT_EQ(liquid.getName(), "Unknown");
    EXPECT_DOUBLE_EQ(liquid.getDensity(), 0.0);
}

TEST(LiquidTest, ParameterizedConstructor)
{
    Liquid liquid("Water", 1.0);
    EXPECT_EQ(liquid.getName(), "Water");
    EXPECT_DOUBLE_EQ(liquid.getDensity(), 1.0);
}

TEST(LiquidTest, SettersAndGetters)
{
    Liquid liquid;
    liquid.setName("Oil");
    liquid.setDensity(0.8);
    EXPECT_EQ(liquid.getName(), "Oil");
    EXPECT_DOUBLE_EQ(liquid.getDensity(), 0.8);
}

TEST(LiquidTest, NegativeDensity)
{
    Liquid liquid;
    EXPECT_THROW(liquid.setDensity(-1.0), std::invalid_argument);
}

// Тестування класу Alcohol
TEST(AlcoholTest, DefaultConstructor)
{
    Alcohol alcohol;
    EXPECT_EQ(alcohol.getName(), "Unknown");
    EXPECT_DOUBLE_EQ(alcohol.getDensity(), 0.0);
    EXPECT_DOUBLE_EQ(alcohol.getStrength(), 0.0);
}

TEST(AlcoholTest, ParameterizedConstructor)
{
    Alcohol alcohol("Wine", 0.99, 12.0);
    EXPECT_EQ(alcohol.getName(), "Wine");
    EXPECT_DOUBLE_EQ(alcohol.getDensity(), 0.99);
    EXPECT_DOUBLE_EQ(alcohol.getStrength(), 12.0);
}

TEST(AlcoholTest, SettersAndGetters)
{
    Alcohol alcohol;
    alcohol.setName("Beer");
    alcohol.setDensity(1.01);
    alcohol.setStrength(5.0);
    EXPECT_EQ(alcohol.getName(), "Beer");
    EXPECT_DOUBLE_EQ(alcohol.getDensity(), 1.01);
    EXPECT_DOUBLE_EQ(alcohol.getStrength(), 5.0);
}

TEST(AlcoholTest, NegativeStrength)
{
    Alcohol alcohol;
    EXPECT_THROW(alcohol.setStrength(-5.0), std::invalid_argument);
}

TEST(AlcoholTest, IncrementDecrementOperators)
{
    Alcohol alcohol("Rum", 0.98, 40.0);
    ++alcohol;
    EXPECT_DOUBLE_EQ(alcohol.getStrength(), 41.0);
    alcohol++;
    EXPECT_DOUBLE_EQ(alcohol.getStrength(), 42.0);
    --alcohol;
    EXPECT_DOUBLE_EQ(alcohol.getStrength(), 41.0);
    alcohol--;
    EXPECT_DOUBLE_EQ(alcohol.getStrength(), 40.0);
}
