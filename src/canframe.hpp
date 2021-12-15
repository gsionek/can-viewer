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
    unsigned int getCanId();
    unsigned char getDlc();
    std::vector<unsigned char> getData();
    bool isExtendedFrameFormat();

    void setCanId(/*...*/);
    void setData(/*...*/);

    friend std::ostream& operator<<(std::ostream& os, const CanFrame& frame);
private:
    unsigned int canId;
    unsigned char dlc;
    std::vector<unsigned char> data;
};

#endif //CANFRAME_H
