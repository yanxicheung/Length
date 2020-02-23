#include "gtest/gtest.h"
#include "Mile.h"

struct MileTest:testing::Test
{

};

TEST_F(MileTest,should_equal)
{
    ASSERT_TRUE(Mile(3) == Mile(3));
}

TEST_F(MileTest,should_not_equal)
{
    ASSERT_TRUE(Mile(3) != Mile(2));
    ASSERT_TRUE(Mile(3) != Mile(4));
}

