#include "canframe.hpp"

CanFrame::CanFrame()
{
    this->canId = 0u;
    this->dlc = 0u;
    this->data.clear();
}

CanFrame::CanFrame(const can_frame& frame)
{
    // TODO
}

CanFrame::~CanFrame()
{

}

unsigned int CanFrame::getCanId()
{
    return 0; // TODO
}

unsigned char CanFrame::getDlc()
{
    return 0; // TODO
}

std::vector<unsigned char> CanFrame::getData()
{
    return data; // TODO
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

std::ostream& operator<<(std::ostream os, const CanFrame& frame)
{
    // os << "0x"
}
