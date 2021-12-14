#include "string.h"
#include "iostream"
#include "candevice.hpp"

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

int main()
{
    print("Starting CanViewer");
    CanDevice can_device("vcan0");

    while (true)
    {
        can_frame frame;
        frame = can_device.readFrame();
        print_can_frame(frame);
    }

    print("Shutting down... Goodbye!");
    return 0;
}
