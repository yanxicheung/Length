#include "gtest/gtest.h"
#include "Volume.h"
#include "VolumeUnit.h"
struct VolumeTest:testing::Test
{

};

TEST_F(VolumeTest,should_equal)
{
    ASSERT_TRUE(Volume(1,OZ) == Volume(1,OZ));
    ASSERT_TRUE(Volume(1,TBSP) == Volume(3,TSP));
    ASSERT_TRUE(Volume(1,OZ) == Volume(2,TBSP));
}
