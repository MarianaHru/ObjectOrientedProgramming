#include "gtest/gtest.h"
#include "Liquid.h"
#include "AlcoholPublic.h"
#include "AlcoholPrivate.h"
#include <sstream>

// Тести для класу Liquid
TEST(LiquidTest, DefaultConstructor)
{
    Liquid l;
    ASSERT_EQ(l.operator string(), "Name: , Density: 0.000000");
}

TEST(LiquidTest, ParameterizedConstructor)
{
    Liquid l("Water", 1.0);
    ASSERT_EQ(l.operator string(), "Name: Water, Density: 1.000000");
}

TEST(LiquidTest, ParameterizedConstructorNegativeDensity)
{
    Liquid l("Gas", -0.5);
    ASSERT_EQ(l.operator string(), "Name: Gas, Density: 0.000000");
}

TEST(LiquidTest, InitMethod)
{
    Liquid l;
    l.Init("Oil", 0.9);
    ASSERT_EQ(l.operator string(), "Name: Oil, Density: 0.900000");
}

TEST(LiquidTest, LiquidOutputOperator)
{
    Liquid l("Juice", 1.2);
    std::stringstream ss;
    ss << l;
    ASSERT_EQ(ss.str(), "Name: Juice, Density: 1.200000");
}

// Тести для класу AlcoholPublic
TEST(AlcoholPublicTest, DefaultConstructor)
{
    AlcoholPublic ap;
    ASSERT_EQ(ap.operator string(), "Name: , Density: 0.000000");
    ASSERT_EQ(ap.getStrength() > 0, false);
}

TEST(AlcoholPublicTest, ParameterizedConstructor)
{
    AlcoholPublic ap("Lemonade", 1.05, 10);
    ASSERT_EQ(ap.operator string(), "Name: Lemonade, Density: 1.050000");
    ASSERT_EQ(ap.getStrength() > 9, true);
    ASSERT_EQ(ap.getStrength() < 11, true);
}

TEST(AlcoholPublicTest, ParameterizedConstructorNegativeStrength)
{
    AlcoholPublic ap("Soda", 1.0, -2);
    ASSERT_EQ(ap.operator string(), "Name: Soda, Density: 1.000000");
    ASSERT_EQ(ap.getStrength() > 0, false);
}

TEST(AlcoholPublicTest, AssignmentOperator)
{
    AlcoholPublic ap1("Kvas", 1.02, 2);
    AlcoholPublic ap2;
    ap2 = ap1;
    ASSERT_EQ(ap2.operator string(), "Name: Kvas, Density: 1.020000");
    ASSERT_EQ(ap2.getStrength() > 1, true);
}

TEST(AlcoholPublicTest, PrefixIncrement)
{
    AlcoholPublic ap("Apple Juice", 1.04, 5);
    ++ap;
    ASSERT_EQ(ap.getStrength() > 5, true);
}

TEST(AlcoholPublicTest, PostfixIncrement)
{
    AlcoholPublic ap("Grape Juice", 1.06, 8);
    AlcoholPublic ap2 = ap++;
    ASSERT_EQ(ap2.getStrength() == 8, true);
    ASSERT_EQ(ap.getStrength() == 9, true);
    ASSERT_EQ(ap.getStrength() > 9, false);
}

TEST(AlcoholPublicTest, PrefixDecrement)
{
    AlcoholPublic ap("Orange Juice", 1.03, 3);
    --ap;
    ASSERT_EQ(ap.getStrength() < 3, true);
    ASSERT_EQ(ap.getStrength() > 1, true);
}

TEST(AlcoholPublicTest, PostfixDecrement)
{
    AlcoholPublic ap("Berry Juice", 1.07, 7);
    AlcoholPublic ap2 = ap--;
    ASSERT_EQ(ap2.getStrength() < 8, true);
    ASSERT_EQ(ap.getStrength() < 7, true);
    ASSERT_EQ(ap.getStrength() > 5, true);
}

TEST(AlcoholPublicTest, ComparisonOperators)
{
    AlcoholPublic ap1("Drink A", 1.01, 15);
    AlcoholPublic ap2("Drink A", 1.01, 15);
    AlcoholPublic ap3("Drink B", 1.02, 10);

    ASSERT_TRUE(ap1 == ap2);
    ASSERT_FALSE(ap1 != ap2);
    ASSERT_TRUE(ap1 > ap3);
    ASSERT_TRUE(ap3 < ap1);
    ASSERT_TRUE(ap1 >= ap2);
    ASSERT_TRUE(ap1 >= ap3);
    ASSERT_TRUE(ap1 <= ap2);
    ASSERT_TRUE(ap3 <= ap1);
}

// Тести для класу AlcoholPrivate
TEST(AlcoholPrivateTest, DefaultConstructor)
{
    AlcoholPrivate apr;
    ASSERT_EQ(apr.operator string(), "Name: , Density: 0.000000");
    ASSERT_EQ(apr.getStrength() > 0, false);
}

TEST(AlcoholPrivateTest, ParameterizedConstructor)
{
    AlcoholPrivate apr("Special Drink", 0.99, 12);
    ASSERT_EQ(apr.operator string(), "Name: Special Drink, Density: 0.990000");
    ASSERT_EQ(apr.getStrength() > 11, true);
    ASSERT_EQ(apr.getStrength() < 13, true);
}

TEST(AlcoholPrivateTest, ParameterizedConstructorNegativeStrength)
{
    AlcoholPrivate apr("Secret Mix", 1.08, -1);
    ASSERT_EQ(apr.operator string(), "Name: Secret Mix, Density: 1.080000");
    ASSERT_EQ(apr.getStrength() > 0, false);
}

TEST(AlcoholPrivateTest, PrefixIncrement)
{
    AlcoholPrivate apr("Test Drink 1", 1.04, 7);
    ++apr;
    ASSERT_EQ(apr.getStrength() > 7, true);
}

TEST(AlcoholPrivateTest, PostfixIncrement)
{
    AlcoholPrivate apr("Test Drink 2", 1.05, 9);
    AlcoholPrivate apr2 = apr++;
    ASSERT_EQ(apr2.getStrength() == 9, true);
    ASSERT_EQ(apr.getStrength() == 10, true);
    ASSERT_EQ(apr.getStrength() > 10, false);
}

TEST(AlcoholPrivateTest, PrefixDecrement)
{
    AlcoholPrivate apr("Test Drink 3", 1.03, 4);
    --apr;
    ASSERT_EQ(apr.getStrength() < 4, true);
    ASSERT_EQ(apr.getStrength() > 2, true);
}

TEST(AlcoholPrivateTest, PostfixDecrement)
{
    AlcoholPrivate apr("Test Drink 4", 1.06, 6);
    AlcoholPrivate apr2 = apr--;
    ASSERT_EQ(apr2.getStrength() < 7, true);
    ASSERT_EQ(apr.getStrength() < 6, true);
    ASSERT_EQ(apr.getStrength() > 4, true);
}

TEST(AlcoholPrivateTest, ComparisonOperators)
{
    AlcoholPrivate apr1("Private A", 0.95, 18);
    AlcoholPrivate apr2("Private A", 0.95, 18);
    AlcoholPrivate apr3("Private B", 0.96, 10);

    ASSERT_TRUE(apr1 == apr2);
    ASSERT_FALSE(apr1 != apr2);
    ASSERT_TRUE(apr1 > apr3);
    ASSERT_TRUE(apr3 < apr1);
    ASSERT_TRUE(apr1 >= apr2);
    ASSERT_TRUE(apr1 >= apr3);
    ASSERT_TRUE(apr1 <= apr2);
    ASSERT_TRUE(apr3 <= apr1);
}

TEST(AlcoholPrivateTest, OutputOperator)
{
    AlcoholPrivate apr("Private Mix", 1.01, 22);
    std::stringstream ss;
    ss << apr;
    ASSERT_EQ(ss.str(), "Name: Private Mix, Density: 1.010000, Strength: 22");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}