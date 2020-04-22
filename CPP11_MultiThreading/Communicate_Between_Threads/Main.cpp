/**************************************************************************************************
 * Project      : Communicate_Between_Threads
 * Description  : Exchange the data, or return the result from threads, by using std::promise and 
 *              : std::future mechanism.
 * ================================================================================================
 * File name    : Main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Sun.  03 Nov. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>
#include <thread>
#include <future>

using namespace std;

void initializer(std::promise<int> *promObj)
{
    cout << "Inside thread" << endl;
    promObj->set_value(35);
}

int main(int argc, char* argv[])
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();

    std::thread workThread(initializer, &promiseObj);
    cout << futureObj.get() << endl;
    workThread.join();

    return 0;
}
