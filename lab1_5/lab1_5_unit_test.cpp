#include <gtest/gtest.h>
#include "Liquid.h"
#include "Alcohol.h"

// Тестування класу Liquid
TEST(LiquidTest, Initialization)
{
    Liquid water;
    water.Init("Water", 1.0);
    EXPECT_EQ(water.getName(), "Water");
    EXPECT_DOUBLE_EQ(water.getDensity(), 1.0);
}

TEST(LiquidTest, SettersAndGetters)
{
    Liquid juice;
    juice.setName("Juice");
    juice.setDensity(1.2);
    EXPECT_EQ(juice.getName(), "Juice");
    EXPECT_DOUBLE_EQ(juice.getDensity(), 1.2);
}

// Тестування класу Alcohol
TEST(AlcoholTest, Initialization)
{
    Liquid ethanol;
    ethanol.Init("Ethanol", 0.789);
    Alcohol vodka;
    vodka.Init(ethanol, 40.0);
    EXPECT_EQ(vodka.getLiquid().getName(), "Ethanol");
    EXPECT_DOUBLE_EQ(vodka.getLiquid().getDensity(), 0.789);
    EXPECT_DOUBLE_EQ(vodka.getStrength(), 40.0);
}

TEST(AlcoholTest, SettersAndGetters)
{
    Liquid whiskeyLiquid;
    whiskeyLiquid.Init("Whiskey", 0.94);
    Alcohol whiskey;
    whiskey.setLiquid(whiskeyLiquid);
    whiskey.setStrength(45.0);
    EXPECT_EQ(whiskey.getLiquid().getName(), "Whiskey");
    EXPECT_DOUBLE_EQ(whiskey.getLiquid().getDensity(), 0.94);
    EXPECT_DOUBLE_EQ(whiskey.getStrength(), 45.0);
}

// Основна функція для запуску тестів
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
