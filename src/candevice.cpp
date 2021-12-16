#include "candevice.hpp"
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <net/if.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

CanDevice::CanDevice(const char* interface)
{
    this->socketFd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    int index = retrieveInterfaceIndex(interface);
    sockaddr_can addr = getCanSockAddr(index);

    if (bind(socketFd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        // TODO: see when to use perror, should throw here and handle exception?
        close(socketFd); // maybe close is called in destructor after throw?
        perror("Bind error");
        // TODO:
        // throw!
    }
}

CanDevice::~CanDevice()
{
    close(this->socketFd);
}

int CanDevice::retrieveInterfaceIndex(const char* interface)
{
    ifreq if_request;
    strcpy(if_request.ifr_name, interface);
    ioctl(this->socketFd, SIOCGIFINDEX, &if_request);
    return if_request.ifr_ifindex;
}

sockaddr_can CanDevice::getCanSockAddr(int ifIndex)
{
    sockaddr_can addr;
    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifIndex;
    return addr;
}

CanFrame CanDevice::readFrame()
{
    int nbytes;
    can_frame frame;
    nbytes = read(this->socketFd, &frame, sizeof(can_frame));

    if (nbytes < 0)
    {
        perror("Read error");
        // TODO:
        // throw?
    }

    return CanFrame(frame);
}
