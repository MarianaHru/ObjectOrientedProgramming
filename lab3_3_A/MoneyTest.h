#pragma once
#include <gtest/gtest.h>
#include "MoneyPublic.h"
#include "MoneyPrivate.h"

class MoneyTest : public ::testing::Test
{
protected:
    MoneyPublic a{10, 50};
    MoneyPublic b{5, 75};
    MoneyPrivate x{3, 10};
    MoneyPrivate y{2, 90};
};
