#pragma once
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include <gtest/gtest.h>

TEST(CircleTest, Initialization)
{
    Circle c;
    EXPECT_TRUE(c.Init(5.0, 0.0, 0.0));
    EXPECT_EQ(c.GetRadius(), 5.0);
    EXPECT_EQ(c.GetX(), 0.0);
    EXPECT_EQ(c.GetY(), 0.0);
}

TEST(CircleTest, InvalidRadius)
{
    Circle c;
    EXPECT_FALSE(c.SetRadius(-3.0));
}

TEST(CircleTest, Move)
{
    Circle c;
    c.Init(5.0, 0.0, 0.0);
    c.Move(3.0, 4.0);
    EXPECT_EQ(c.GetX(), 3.0);
    EXPECT_EQ(c.GetY(), 4.0);
}

TEST(CircleTest, Resize)
{
    Circle c;
    c.Init(5.0, 0.0, 0.0);
    c.Resize(2.0);
    EXPECT_EQ(c.GetRadius(), 7.0);
}

TEST(SquareTest, Initialization)
{
    Square s;
    EXPECT_TRUE(s.Init(4.0, 1.0, 1.0, 45.0));
    EXPECT_EQ(s.GetLength(), 4.0);
    EXPECT_EQ(s.GetX(), 1.0);
    EXPECT_EQ(s.GetY(), 1.0);
    EXPECT_EQ(s.getRotation(), 45.0);
}

TEST(SquareTest, Move)
{
    Square s;
    s.Init(4.0, 1.0, 1.0, 0.0);
    s.Move(2.0, 3.0);
    EXPECT_EQ(s.GetX(), 3.0);
    EXPECT_EQ(s.GetY(), 4.0);
}

TEST(SquareTest, Resize)
{
    Square s;
    s.Init(4.0, 1.0, 1.0, 0.0);
    s.Resize(2.0);
    EXPECT_EQ(s.GetLength(), 6.0);
}

TEST(RectangleTest, Initialization)
{
    Rectangle r;
    EXPECT_TRUE(r.Init(6.0, 3.0, 2.0, 2.0, 30.0));
    EXPECT_EQ(r.GetLength(), 6.0);
    EXPECT_EQ(r.GetHeight(), 3.0);
    EXPECT_EQ(r.GetX(), 2.0);
    EXPECT_EQ(r.GetY(), 2.0);
    EXPECT_EQ(r.getRotation(), 30.0);
}

TEST(RectangleTest, Move)
{
    Rectangle r;
    r.Init(6.0, 3.0, 2.0, 2.0, 0.0);
    r.Move(3.0, 2.0);
    EXPECT_EQ(r.GetX(), 5.0);
    EXPECT_EQ(r.GetY(), 4.0);
}

TEST(RectangleTest, Resize)
{
    Rectangle r;
    r.Init(6.0, 3.0, 2.0, 2.0, 0.0);
    r.Resize(2.0, 1.0);
    EXPECT_EQ(r.GetLength(), 8.0);
    EXPECT_EQ(r.GetHeight(), 4.0);
}
