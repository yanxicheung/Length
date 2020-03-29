#include "gtest/gtest.h"
#include "Length.h"
#include "LengthUnit.h"
struct MileTest:testing::Test
{

};

TEST_F(MileTest,should_equal)
{
    ASSERT_TRUE(Length(3,MILE) == Length(3,MILE));
}

TEST_F(MileTest,should_not_equal)
{
    ASSERT_TRUE(Length(3,MILE) != Length(2,MILE));
    ASSERT_TRUE(Length(3,MILE) != Length(4,MILE));
}

//////////////////////////////////////
struct YardTest:testing::Test
{

};

TEST_F(YardTest,should_equal)
{
    ASSERT_TRUE(Length(3,YARD) == Length(3,YARD));
    ASSERT_TRUE(Length(1,MILE) == Length(1760,YARD));
    ASSERT_TRUE(Length(1760,YARD) == Length(1,MILE));
}

TEST_F(YardTest,should_not_equal)
{
    ASSERT_TRUE(Length(3,YARD) != Length(4,YARD));
    ASSERT_TRUE(Length(1,MILE) != Length(1761,YARD));
    ASSERT_TRUE(Length(1761,YARD) != Length(1,MILE));
}
////////////////////////////////////

struct FeetInchTest:testing::Test
{

};

TEST_F(FeetInchTest,should_equal)
{
    ASSERT_TRUE(Length(1,YARD) == Length(3,FEET));
    ASSERT_TRUE(Length(1,FEET) == Length(12,INCH));
}



struct LengthAddTest:testing::Test
{

};

TEST_F(LengthAddTest,should_equal)
{
    ASSERT_TRUE(Length(13,INCH) + Length(11,INCH) == Length(2,FEET));
    ASSERT_TRUE(Length(3,FEET) + Length(2,YARD) == Length(3,YARD));
}
