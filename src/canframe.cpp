#include "canframe.hpp"

CanFrame::CanFrame()
{
    // TODO initialize can_frame
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
    return 0; // TODO
}

std::vector<unsigned char> CanFrame::getData()
{
    // TODO
    std::vector<unsigned char> empty_vector;
    empty_vector.clear();
    return empty_vector;
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
