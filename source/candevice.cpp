#include "candevice.hpp"
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <net/if.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

CanDevice::CanDevice(const char* interface)
{
    this->socket_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    int index = retrieveInterfaceIndex(interface);
    sockaddr_can addr = getCanSockAddr(index);

    if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        // TODO: see when to use perror, should throw here and handle exception?
        close(socket_fd); // maybe close is called in destructor after throw?
        perror("Bind error");
        // TODO:
        // throw!
    }
}

CanDevice::~CanDevice()
{
    close(this->socket_fd);
}

int CanDevice::retrieveInterfaceIndex(const char* interface)
{
    ifreq if_request;
    strcpy(if_request.ifr_name, interface);
    ioctl(this->socket_fd, SIOCGIFINDEX, &if_request);
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

can_frame CanDevice::readFrame()
{
    int nbytes;
    can_frame frame;
    nbytes = read(this->socket_fd, &frame, sizeof(can_frame));

    if (nbytes < 0)
    {
        perror("Read error");
        // TODO:
        // throw
    }

    return frame;
}
