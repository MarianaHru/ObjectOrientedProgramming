#include "Money.h"
#include "gtest/gtest.h"

TEST(MoneyTest, Constructor)
{
    Money m1;
    EXPECT_EQ(m1.GetHryvna(), 0);
    EXPECT_EQ(m1.GetKopek(), 0);

    Money m2(10, 50);
    EXPECT_EQ(m2.GetHryvna(), 10);
    EXPECT_EQ(m2.GetKopek(), 50);

    Money m3(m2);
    EXPECT_EQ(m3.GetHryvna(), 10);
    EXPECT_EQ(m3.GetKopek(), 50);
}

TEST(MoneyTest, SetKopek)
{
    Money m;
    EXPECT_TRUE(m.SetKopek(99));
    EXPECT_EQ(m.GetKopek(), 99);
    EXPECT_FALSE(m.SetKopek(100));
    EXPECT_EQ(m.GetKopek(), 99);
}

// TEST(MoneyTest, ToStringFromString)
// {
//     Money m(123, 45);
//     string s = m.toString();
//     EXPECT_EQ(s, "123,45 UAH");

//     Money m2;
//     m2.fromString(s);
//     EXPECT_EQ(m2.GetHryvna(), 123);
//     EXPECT_EQ(m2.GetKopek(), 45);
// }

TEST(MoneyTest, ToStringFromString)
{
    Money m(123, 45);
    string s = m.toString();
    EXPECT_EQ(s, "123,45 UAH");

    Money m2;
    m2.fromString(s);
    EXPECT_EQ(m2.GetHryvna(), 123);
    EXPECT_EQ(m2.GetKopek(), 45);
}

TEST(MoneyTest, Addition)
{
    Money m1(1, 50);
    Money m2(2, 75);
    Money sum = m1 + m2;
    EXPECT_EQ(sum.GetHryvna(), 4);
    EXPECT_EQ(sum.GetKopek(), 25);
}

// TEST(MoneyTest, Division)
// {
//     Money m1(10, 0);
//     Money m2(2, 0);
//     double div = m1 / m2;
//     EXPECT_DOUBLE_EQ(div, 5.0);

//     Money m3(10, 0);
//     Money div2 = m3 / 2.0;
//     EXPECT_EQ(div2.GetHryvna(), 5);
//   EXPECT_EQ(div
