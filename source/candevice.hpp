#ifndef CANDEVICE_H
#define CANDEVICE_H
#include <linux/can.h>

class CanDevice
{
public:
    CanDevice(const char* interface);
    ~CanDevice();
    can_frame readFrame();

private:
    int socketFd;
    int retrieveInterfaceIndex(const char* interface);
    sockaddr_can getCanSockAddr(int ifIndex);
};

#endif //CANDEVICE_H