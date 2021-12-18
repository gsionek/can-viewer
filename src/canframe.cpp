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

unsigned int CanFrame::getCanId() const
{
    unsigned int id = this->isExtendedFrameFormat() ? this->getExtendedFormatId()
                                                    : this->getStandardFormatId();
    return id;
}

unsigned int CanFrame::getDlc() const
{
    return this->frame.can_dlc;
}

std::vector<unsigned char> CanFrame::getData() const
{
    std::vector<unsigned char> data(this->frame.data,
                                    this->frame.data + this->frame.can_dlc);
    return data;
}

bool CanFrame::isExtendedFrameFormat() const
{
    return (this->frame.can_id & CAN_EFF_FLAG);
}

void CanFrame::print() const
{
    if(this->isExtendedFrameFormat())
        printf("0x%08X", this->getCanId());
    else
        printf("0x%03X", this->getCanId());

    printf(" [%d] ", this->getDlc());

    for(auto d: this->getData())
        printf("%02X ", d);

    printf("\n");
}

void CanFrame::setCanId(/*...*/)
{
    // TODO
}

void CanFrame::setData(/*...*/)
{
    // TODO
}

std::ostream& operator<<(std::ostream& os, const CanFrame& frame)
{
    // TODO
}

unsigned int CanFrame::getExtendedFormatId() const
{
    return (this->frame.can_id & CAN_EFF_MASK);
}

unsigned int CanFrame::getStandardFormatId() const
{
    return (this->frame.can_id & CAN_SFF_MASK);
}
