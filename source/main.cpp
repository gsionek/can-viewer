#include "string.h"
#include "linux/can.h"
#include "iostream"
#include "sys/socket.h"
#include "sys/ioctl.h"
#include "net/if.h"
#include "unistd.h"

// https://www.beyondlogic.org/example-c-socketcan-code/

void print(const char* message)
{
    std::cout << message << std::endl;
}

void print_can_frame(can_frame frame)
{
    // TODO: make function for determining can_id (can be 11-bit SFF or 29-bit EFF)
    int can_id = frame.can_id & 0x1FFFFFFF;

    printf("0x%03X [%d] ", can_id, frame.can_dlc);
    
    for (int i = 0; i < frame.can_dlc; ++i)
        printf("%02X ", frame.data[i]);

    printf("\n");    
}

// C++20 solution: Not supported yet by GCC
// std::ostream& operator<<(std::ostream& stream, const can_frame& frame)
// {
//     int can_id = frame.can_id & 0x1FFFFFFF;
//     stream << std::format("0x{:03X} [{:d}]", can_id, frame.can_dlc); // frame.can_dlc << "hello" << std::endl;
//     for (int i = 0; i < frame.can_dlc; ++i)
//         stream << std::format("{:02X}", frame.data[i]);
//     return stream;
// }

int main()
{
    print("Starting CanViewer");

    int s;
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);

    ifreq if_request;
    strcpy(if_request.ifr_name, "vcan0");
    ioctl(s, SIOCGIFINDEX, &if_request);

    sockaddr_can addr;
    memset(&addr, 0, sizeof(addr)); // set all to 0!
    addr.can_family = AF_CAN;
    addr.can_ifindex = if_request.ifr_ifindex;

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        // TODO: see when to use perror, should throw here and handle exception?
        close(s);
        perror("Bind error");
        return 1;
    }

    can_frame frame;
    int nbytes;

    while (true)
    {
        nbytes = read(s, &frame, sizeof(can_frame));

        if (nbytes < 0)
        {
            perror("Read error");
            return 1;
        }

        print_can_frame(frame);

        // std::cout << frame << std::endl;
    }

    // print("Sending CAN frame");
    // can_frame frame;
    // frame.can_id = 0x808100;
    // frame.can_dlc = 6;
    // sprintf(frame.data, "Hello");
    // static_cast<__u8>(0x1234ab);

    if(close(s) < 0)
    {
        perror("Close error");
        return 1;
    }

    print("Shutting down... Goodbye!");

    return 0;
}