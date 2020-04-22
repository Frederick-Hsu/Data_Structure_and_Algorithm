/**************************************************************************************************
 * Project      : Multithreading
 * Description  : Have a good research on the multiple-thread programming in std C++11.
 * ================================================================================================
 * File name    :main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederique Hsu
 * Creation date: Tue.  21 April 2020
 * Copyright(C) 2020    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>
#include <thread>
#include "thread_creation.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::cout << "C++ standard no.: " << __cplusplus << std::endl;

#if 0       /* Creating a thread using Function Pointer */  
    thread threadObj(thread_function);
    for (int i = 0; i < 1000; ++i)
    {
        cout << "Display from MainThread" << endl;
    }
    threadObj.join();
#elif 0     /* Creating a thread using Functor objects */
    thread threadObj( (DisplayThread()) );
    for (int cnt = 0; cnt < 1000; ++cnt)
    {
        cout << "Display from Main Thread." << endl;
    }
    cout << "Waiting for thread to complete." << endl;
    threadObj.join();
    cout << "Exiting from Main Thread." << endl;
#elif 0       /* Create a thread using Lambda functions */
    thread threadObj([]{
        for (int i = 0; i < 1000; i++)
        {
            cout << "Lambda anonymous function is executing..." << endl;
        }
    });
    for (int index = 0; index < 1000; ++index)
    {
        cout << "Display from Main Thread." << endl;
    }
    threadObj.join();
#else       /* Differenting between threads */
    thread threadObj1(thread_function);
    thread threadObj2(thread_function);

    if (threadObj1.get_id() != threadObj2.get_id())
    {
        cout << "Both threads have different IDs." << endl;
    }
    cout << "From Main Thread::ID of thread1 = " << threadObj1.get_id() << endl;
    cout << "From Main Thread::ID of thread2 = " << threadObj2.get_id() << endl;

    threadObj1.join();
    threadObj2.join();
#endif

    cout << "Exit of main function" << endl;

    return 0;
}