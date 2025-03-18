
#pragma once
#include "Alcohol.h"
#include <gtest/gtest.h>

class AlcoholTest : public ::testing::Test
{
protected:
    Alcohol::Liquid liquid;
    Alcohol alcohol;

    void SetUp() override
    {
        liquid.Init("Ethanol", 0.789);
        alcohol.Init(liquid, 40.0);
    }
};