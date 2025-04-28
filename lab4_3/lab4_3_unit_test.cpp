#include <gtest/gtest.h>
#include "Decimal.h"
#include "BitString.h"
#include <sstream>

// ------------------- Decimal Tests -------------------

TEST(DecimalTest, ConstructorAndPrint)
{
    Decimal d(4, 2);
    testing::internal::CaptureStdout();
    d.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2222\n");
}

TEST(DecimalTest, AddDecimal)
{
    Decimal d1(3, 3);
    Decimal d2(3, 4);
    d1.add(d2);
    testing::internal::CaptureStdout();
    d1.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "777\n");
}

TEST(DecimalTest, AddDecimalWithCarry)
{
    Decimal d1(3);
    Decimal d2(3);
    d1[0] = 9;
    d1[1] = 9;
    d1[2] = 9;
    d2[0] = 1;
    d2[1] = 0;
    d2[2] = 0;
    d1.add(d2);
    testing::internal::CaptureStdout();
    d1.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "000\n");
}

TEST(DecimalTest, ComparisonOperators)
{
    Decimal d1(3);
    Decimal d2(3);
    d1[2] = 1;
    d2[2] = 2;

    EXPECT_TRUE(d1 < d2);
    EXPECT_FALSE(d1 == d2);

    d1[2] = 2;
    EXPECT_TRUE(d1 == d2);
}

// ------------------- BitString Tests -------------------

TEST(BitStringTest, ConstructorAndPrint)
{
    BitString b(5, 1);
    testing::internal::CaptureStdout();
    b.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "11111\n");
}
TEST(BitStringTest, BitwiseXor)
{
    BitString b1(4, 1);
    BitString b2(4, 0);
    b2[1] = '1';
    b2[2] = '1';

    BitString result = b1 ^ b2;

    testing::internal::CaptureStdout();
    result.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1001\n");
}

TEST(BitStringTest, ShiftLeftRight)
{
    BitString b(5);
    b[0] = '1';
    b[1] = '0';
    b[2] = '1';
    b[3] = '1';
    b[4] = '0';

    b.shift_left(2);
    testing::internal::CaptureStdout();
    b.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "11000\n");

    b.shift_right(3);
    testing::internal::CaptureStdout();
    b.print();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "00011\n");
}
