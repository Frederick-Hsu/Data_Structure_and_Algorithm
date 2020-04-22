/**************************************************************************************************
 * Project      : Execute_Packaged_Tasks
 * Description  : Study the C++11 std::packaged_task feature and its usage.
 * ================================================================================================
 * File name    : Main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederique Hsu
 * Creation date: Sun.  03 Nov. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>
#include <thread>
#include <future>
#include <string>
using namespace std;

#include "tasks.h"

#if 0       /* Using packaged_task<> with function to create asynchronous tasks */
    int main(int argc, char* argv[])
    {
        /* create a packaged_task<> that encapsulated the callback, i.e. a function */
        std::packaged_task<string(string)> task(getDataFromDB);

        /* Fetch the associated future<> from packaged_task<> object. */
        std::future<string> result = task.get_future();

        /* Pass the packaged_task to thread to run asynchronously */
        std::thread taskThread(std::move(task), "SQL script");
        /* Join the thread, its blocking and returns when thread is finished. */
        taskThread.join();

        /* Fetch the result of packaged_task<>, i.e. value returned from getDataFromDB() */
        string data = result.get();

        cout << data << endl;
        return 0;
    }
#elif 0     /* Creating packaged_task with Lambda function */
    int main(int argc, char* argv[])
    {
        std::packaged_task<string(string)> task([](string token) {
            string data = "Data from " + token;
            return data;
            });
        std::future<string> result = task.get_future();

        std::thread taskThread(std::move(task), "User file");
        taskThread.join();

        string data = result.get();
        cout << data << endl;
        return 0;
    }
#else       /* Creating packaged_task with Function object */
    struct DBDataFetcher
    {
        string operator()(string token)
        {
            /* Do some stuff in the thread callback function */
            string data = "Data from " + token;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            return data;
        }
    };

    int main(int argc, char* argv[])
    {
        std::packaged_task<string(string)> task((DBDataFetcher()));
        std::future<string> result = task.get_future();

        std::thread taskThread(std::move(task), "PostgreSQL database.");
        taskThread.join();

        string data = result.get();
        cout << data << endl;
        return 0;
    }
#endif
