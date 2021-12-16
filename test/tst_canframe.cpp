#include <gtest/gtest.h>
#include "../src/canframe.hpp"
#include <stdio.h>

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

TEST(CanFrameTest, getDataBytes)
{    
    can_frame frame_struct;
    frame_struct.can_id = 0x001;
    frame_struct.can_dlc = 5;
    for(int i=0; i<CAN_MAX_DLC; ++i)
        frame_struct.data[i] = i+1;

    CanFrame frame_obj(frame_struct);
    auto data = frame_obj.getData();
    
    EXPECT_EQ(data.size(), frame_struct.can_dlc);
    for(int i=0; i<data.size(); ++i)
        EXPECT_EQ(data.at(i), frame_struct.data[i]);
}
