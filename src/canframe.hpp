#ifndef CANFRAME_H
#define CANFRAME_H
#include "linux/can.h"

class CanFrame
{
public:
    CanFrame();
    CanFrame(const can_frame& frame);
    ~CanFrame();
    int getCanId();
    int getDlc();
    int getData();
    bool isExtendedFrameFormat();

    void setCanId(/*...*/);
    void setData(/*...*/);

private:
    can_frame frame;
};

#endif //CANFRAME_H