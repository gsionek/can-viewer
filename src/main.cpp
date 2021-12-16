#include <string.h>
#include <iostream>
#include "candevice.hpp"
#include "canframe.hpp"

void print(const char* message)
{
    std::cout << message << std::endl;
}

int main()
{
    print("Starting CanViewer");
    CanDevice can_device("vcan0");

    while (true)
    {
        CanFrame frame;
        frame = can_device.readFrame();
        frame.print();
        // std::cout << frame << std::endl;
    }

    print("Shutting down... Goodbye!");
    return 0;
}
