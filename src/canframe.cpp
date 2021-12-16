#include "canframe.hpp"
#include <string.h>

CanFrame::CanFrame()
{
    memset(&this->frame, 0, sizeof(can_frame));
}

CanFrame::CanFrame(const can_frame& frame)
{
    this->frame = frame;
}

CanFrame::~CanFrame()
{

}

unsigned int CanFrame::getCanId()
{
    unsigned int id = isExtendedFrameFormat() ? this->getExtendedFormatId()
                                              : this->getStandardFormatId();
    return id;
}

unsigned char CanFrame::getDlc()
{
    return this->frame.can_dlc;
}

std::vector<unsigned char> CanFrame::getData()
{
    std::vector<unsigned char> data(this->frame.data,
                                    this->frame.data + this->frame.can_dlc);
    return data;
}

bool CanFrame::isExtendedFrameFormat()
{
    return (frame.can_id & CAN_EFF_FLAG);
}

void CanFrame::setCanId(/*...*/)
{
    // TODO
}

void CanFrame::setData(/*...*/)
{
    // TODO
}

std::ostream& operator<<(std::ostream os, const CanFrame& frame)
{
    // os << "0x"
    return os;
}

unsigned int CanFrame::getExtendedFormatId()
{
    return (this->frame.can_id & CAN_EFF_MASK);
}
unsigned int CanFrame::getStandardFormatId()
{
    return (this->frame.can_id & CAN_SFF_MASK);
}
