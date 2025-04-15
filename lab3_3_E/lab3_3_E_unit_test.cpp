#include "Object.h"
#include <gtest/gtest.h>

TEST(ObjectTest, CountIncrementsAndDecrements)
{

    EXPECT_EQ(Object::getCount(), 0u);

    {
        Object obj1;
        EXPECT_EQ(Object::getCount(), 1u);

        Object obj2;
        EXPECT_EQ(Object::getCount(), 2u);

        {
            Object obj3;
            EXPECT_EQ(Object::getCount(), 3u);
        }

        EXPECT_EQ(Object::getCount(), 2u);
    }

    EXPECT_EQ(Object::getCount(), 0u);
}
