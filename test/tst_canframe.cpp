#include <gtest/gtest.h>
#include "../src/canframe.hpp"

TEST(CanDeviceTest, getCanId)
{

}

TEST(CanDeviceTest, getDlc)
{

}

TEST(CanDeviceTest, getData)
{

}

TEST(CanDeviceTest, isExtendedFrameFormat)
{
    can_frame frame_struct;
    CanFrame frame_obj;
    frame_struct.can_id = 1 << 31;
    frame_obj = CanFrame(frame_struct);
    EXPECT_TRUE(frame_obj.isExtendedFrameFormat());

    frame_struct.can_id = 0;
    frame_obj = CanFrame(frame_struct);
    EXPECT_FALSE(frame_obj.isExtendedFrameFormat());
}
