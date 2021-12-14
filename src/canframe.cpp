#include "canframe.hpp"

CanFrame::CanFrame()
{
    this->frame.can_id
}


CanFrame::CanFrame(const can_frame& frame)
{
    this->frame = frame;
}

CanFrame::~CanFrame()
{

}

int CanFrame::getCanId()
{
    return 0; // TODO
}

int CanFrame::getDlc()
{
    return 0; // TODO
}

int CanFrame::getData()
{
    return 0; // TODO
}

bool CanFrame::isExtendedFrameFormat()
{
    return false; // TODO
}

void CanFrame::setCanId(/*...*/)
{
    // TODO
}

void CanFrame::setData(/*...*/)
{
    // TODO
}
