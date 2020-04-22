/**************************************************************************************************
 * Project      : Event_Handling
 * Description  : We will discuss the need of Event Handling in multi-threads
 *              : Sometimes, a thread needs to wait for an event to happen like a condition to become
 *              : true, a task to be completed by another thread.
 * ================================================================================================
 * File name    : Main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Sat.  02 Nov. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>
#include <thread>
#include "Application.h"

int main(int argc, char* argv[])
{
    Application app;

    std::thread aliceThread(&Application::mainTask, &app);
    std::thread bobThread(&Application::loadData, &app);

    aliceThread.join();
    bobThread.join();

    return 0;
}
