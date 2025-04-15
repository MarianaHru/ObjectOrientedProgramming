#include "gtest/gtest.h"
#include "test_pair.h"
#include "test_money.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}