#include <gtest/gtest.h>
#include "../src/canframe.hpp"

TEST(CanFrameTest, DefaultConstructor)
{
    CanFrame frame_obj;
    EXPECT_EQ(frame_obj.getCanId(), 0u);
    EXPECT_EQ(frame_obj.getDlc(), 0u);
    EXPECT_EQ(frame_obj.isExtendedFrameFormat(), false);
    
    for(auto byte : frame_obj.getData())
    {
        EXPECT_EQ(byte, 0u);
    }
}

TEST(CanFrameTest, FramConstructor)
{
    // TODO
    FAIL();
}

TEST(CanFrameTest, isExtendedFrameFormat)
{
    can_frame frame_struct;
    CanFrame frame_obj;
    frame_struct.can_id = CAN_EFF_FLAG;
    frame_obj = CanFrame(frame_struct);
    EXPECT_TRUE(frame_obj.isExtendedFrameFormat());

    frame_struct.can_id -= CAN_EFF_FLAG;
    frame_obj = CanFrame(frame_struct);
    EXPECT_FALSE(frame_obj.isExtendedFrameFormat());
}

TEST(CanFrameTest, getCanId)
{
    can_frame frame_struct;
    CanFrame frame_obj;

    // SFF IDs
    frame_struct.can_id = 0x001u;
    frame_obj = CanFrame(frame_struct);
    EXPECT_EQ(frame_obj.getCanId(), 0x001u);

    frame_struct.can_id = 0x7FFu;
    frame_obj = CanFrame(frame_struct);
    EXPECT_EQ(frame_obj.getCanId(), 0x7FFu);

    // Beyond SFF range
    frame_struct.can_id = 0xFFFu;
    frame_obj = CanFrame(frame_struct);
    EXPECT_EQ(frame_obj.getCanId(), 0x7FFu);

    // EFF IDs
    frame_struct.can_id = 0x001u + CAN_EFF_FLAG;
    frame_obj = CanFrame(frame_struct);
    EXPECT_EQ(frame_obj.getCanId(), 0x001u);

    frame_struct.can_id = 0x1FFFFFFFu + CAN_EFF_FLAG;
    frame_obj = CanFrame(frame_struct);
    EXPECT_EQ(frame_obj.getCanId(), 0x1FFFFFFFu);

    // Beyond EFF range
    frame_struct.can_id = 0x3FFFFFFFu + CAN_EFF_FLAG;
    frame_obj = CanFrame(frame_struct);
    EXPECT_EQ(frame_obj.getCanId(), 0x1FFFFFFFu);
}

TEST(CanFrameTest, getDlc)
{
    // TODO
    FAIL();
}

TEST(CanFrameTest, getData)
{
    // TODO
    FAIL();
}
