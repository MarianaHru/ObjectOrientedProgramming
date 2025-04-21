#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>
#include "lab4_1.cpp"

TEST(LineTest, CalculateY)
{
    Line l(2.0, 3.0);
    EXPECT_DOUBLE_EQ(l.calculateY(1.5), 2.0 * 1.5 + 3.0);
}

TEST(EllipseTest, CalculateYValid)
{
    Ellipse e(5.0, 3.0);
    double expected = 3.0 * sqrt(1 - (1.5 * 1.5) / (5.0 * 5.0));
    EXPECT_NEAR(e.calculateY(1.5), expected, 1e-6);
}

TEST(EllipseTest, CalculateYInvalid)
{
    Ellipse e(2.0, 3.0);
    EXPECT_THROW(e.calculateY(3.0), std::domain_error);
}

TEST(HyperbolaTest, CalculateYValid)
{
    Hyperbola h(2.0, 4.0);
    double x = 2.0;
    double expectedY = 4.0 * sqrt((x * x) / (2.0 * 2.0) - 1);
    EXPECT_DOUBLE_EQ(h.calculateY(x), expectedY);
}

TEST(HyperbolaTest, CalculateYInvalid)
{
    Hyperbola h(3.0, 2.0);
    EXPECT_THROW(h.calculateY(1.0), std::domain_error);
}
