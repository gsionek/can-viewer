#ifndef CANDEVICE_H
#define CANDEVICE_H
#include <linux/can.h>

class CanDevice
{
private:
    int socket_fd;
    int retrieveInterfaceIndex(const char* interface);
    sockaddr_can getCanSockAddr(int ifIndex);

public:
    CanDevice(const char* interface);
    ~CanDevice();
    can_frame readFrame();

};

#endif //CANDEVICE_H