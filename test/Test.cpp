#include "gtest/gtest.h"
#include "Mile.h"
#include "Yard.h"
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

//////////////////////////////////////
struct YardTest:testing::Test
{

};

TEST_F(YardTest,should_equal)
{
    ASSERT_TRUE(Yard(3) == Yard(3));
    ASSERT_TRUE(Mile(1) == Yard(1760));
    ASSERT_TRUE(Yard(1760) == Mile(1));
}

TEST_F(YardTest,should_not_equal)
{
    ASSERT_TRUE(Yard(3) != Yard(4));
    ASSERT_TRUE(Mile(1) != Yard(1761));
    ASSERT_TRUE(Yard(1761) != Mile(1));
}

