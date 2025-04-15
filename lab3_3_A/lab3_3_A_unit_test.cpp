#include "MoneyTest.h"

TEST_F(MoneyTest, AdditionPublic)
{
    MoneyPublic result = a + b;
    EXPECT_EQ(result.GetHryvna(), 16);
    EXPECT_EQ(result.GetKopek(), 25);
}

TEST_F(MoneyTest, DivisionPublicByNumber)
{
    MoneyPublic result = a / 2;
    EXPECT_EQ(result.GetHryvna(), 5);
    EXPECT_EQ(result.GetKopek(), 25);
}

TEST_F(MoneyTest, DivisionPublicByObject)
{
    double result = a / b;
    EXPECT_NEAR(result, 1.826, 0.001); // Виправлено точне очікуване значення
}

TEST_F(MoneyTest, IncrementDecrementPublic)
{
    MoneyPublic temp = a;
    ++temp;
    EXPECT_EQ(temp.GetHryvna(), 10);
    EXPECT_EQ(temp.GetKopek(), 51);

    --temp;
    EXPECT_EQ(temp.GetHryvna(), 10);
    EXPECT_EQ(temp.GetKopek(), 50);
}

TEST_F(MoneyTest, AdditionPrivate)
{
    MoneyPrivate result = x + y;
    Money base = result.toBase();
    EXPECT_EQ(base.GetHryvna(), 6);
    EXPECT_EQ(base.GetKopek(), 0);
}

TEST_F(MoneyTest, DivisionPrivateByNumber)
{
    MoneyPrivate result = x / 2;
    Money base = result.toBase();
    EXPECT_EQ(base.GetHryvna(), 1);
    EXPECT_EQ(base.GetKopek(), 55);
}

TEST_F(MoneyTest, DivisionPrivateByObject)
{
    double result = x / y;
    EXPECT_NEAR(result, 1.07, 0.01);
}
