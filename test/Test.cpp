#include "gtest/gtest.h"
#include "Length.h"
struct MileTest:testing::Test
{

};

TEST_F(MileTest,should_equal)
{
    ASSERT_TRUE(Length(3,YARDS_PER_MILE) == Length(3,YARDS_PER_MILE));
}

TEST_F(MileTest,should_not_equal)
{
    ASSERT_TRUE(Length(3,YARDS_PER_MILE) != Length(2,YARDS_PER_MILE));
    ASSERT_TRUE(Length(3,YARDS_PER_MILE) != Length(4,YARDS_PER_MILE));
}

//////////////////////////////////////
struct YardTest:testing::Test
{

};

TEST_F(YardTest,should_equal)
{
    ASSERT_TRUE(Length(3,YARDS_PER_YARD) == Length(3,YARDS_PER_YARD));
    ASSERT_TRUE(Length(1,YARDS_PER_MILE) == Length(1760,YARDS_PER_YARD));
    ASSERT_TRUE(Length(1760,YARDS_PER_YARD) == Length(1,YARDS_PER_MILE));
}

TEST_F(YardTest,should_not_equal)
{
    ASSERT_TRUE(Length(3,YARDS_PER_YARD) != Length(4,YARDS_PER_YARD));
    ASSERT_TRUE(Length(1,YARDS_PER_MILE) != Length(1761,YARDS_PER_YARD));
    ASSERT_TRUE(Length(1761,YARDS_PER_YARD) != Length(1,YARDS_PER_MILE));
}

