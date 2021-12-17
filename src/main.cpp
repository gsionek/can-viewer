#include <string.h>
#include <iostream>
#include <thread>
#include "candevice.hpp"
#include "canframe.hpp"

static bool isFinished = false;

void print(const char* message)
{
    std::cout << message << std::endl;
}

void startCanReader()
{
    CanDevice can_device("vcan0");

    while (!isFinished)
    {
        CanFrame frame;
        frame = can_device.readFrame();
        frame.print();
        // std::cout << frame << std::endl;
    }
}

int main()
{
    print("Starting CanViewer");

    std::thread worker(startCanReader);
    
    std::cin.get();
    isFinished = true;

    worker.join();    

    print("Shutting down... Goodbye!");
    return 0;
}
