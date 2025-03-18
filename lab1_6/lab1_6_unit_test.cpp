
#include "AlcoholTest.h"

TEST_F(AlcoholTest, LiquidInitialization)
{
    EXPECT_EQ(liquid.getName(), "Ethanol");
    EXPECT_DOUBLE_EQ(liquid.getDensity(), 0.789);
}

TEST_F(AlcoholTest, AlcoholInitialization)
{
    EXPECT_EQ(alcohol.getLiquid().getName(), "Ethanol");
    EXPECT_DOUBLE_EQ(alcohol.getLiquid().getDensity(), 0.789);
    EXPECT_DOUBLE_EQ(alcohol.getStrength(), 40.0);
}

TEST_F(AlcoholTest, SetLiquid)
{
    Alcohol::Liquid newLiquid;
    newLiquid.Init("Methanol", 0.791);
    alcohol.setLiquid(newLiquid);
    EXPECT_EQ(alcohol.getLiquid().getName(), "Methanol");
    EXPECT_DOUBLE_EQ(alcohol.getLiquid().getDensity(), 0.791);
}

TEST_F(AlcoholTest, SetStrength)
{
    alcohol.setStrength(50.0);
    EXPECT_DOUBLE_EQ(alcohol.getStrength(), 50.0);
}
