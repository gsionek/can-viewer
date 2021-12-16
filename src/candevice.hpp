#ifndef CANDEVICE_H
#define CANDEVICE_H
#include <linux/can.h>
#include "canframe.hpp"

class CanDevice
{
public:
    CanDevice(const char* interface);
    ~CanDevice();
    CanFrame readFrame();

private:
    int socketFd;
    int retrieveInterfaceIndex(const char* interface);
    sockaddr_can getCanSockAddr(int ifIndex);
};

#endif //CANDEVICE_H