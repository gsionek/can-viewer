#ifndef CANFRAME_H
#define CANFRAME_H
#include "linux/can.h"
#include <iostream>
#include <vector>

class CanFrame
{
public:
    CanFrame();
    CanFrame(const can_frame& frame);
    ~CanFrame();
    unsigned int getCanId() const;
    unsigned char getDlc() const;
    std::vector<unsigned char> getData() const;
    bool isExtendedFrameFormat() const;

    void setCanId(/*...*/);
    void setData(/*...*/);

    friend std::ostream& operator<<(std::ostream& os, const CanFrame& frame);
private:
    can_frame frame;

    unsigned int getExtendedFormatId() const;
    unsigned int getStandardFormatId() const;
};

#endif //CANFRAME_H
