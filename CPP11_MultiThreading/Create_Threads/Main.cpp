/**************************************************************************************************
 * Project      : Create_Threads
 * Description  : We will discuss how to create threads in C++11 using std::thread.
 * ================================================================================================
 * File name    : Main.cpp
 * Description  : This file will implement the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Fri.  01 Nov. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <thread>
#include <iostream>

using namespace std;

#if 0
    /* Creating a thread using Function Pointer */
    void work_thread()
    {
        for (int i = 0; i < 100; ++i)
        {
            std::cout << "work_thread function is executing..." << std::endl;
        }
    }

    int main(int argc, char* argv[])
    {
        std::thread work(work_thread);
        for (int n = 0; n < 100; ++n)
        {
            std::cout << "Display form main thread" << std::endl;
        }
        work.join();

        std::cout << "Exit from main() function." << std::endl;
        return 0;
    }
#elif 0
    /* Creating a thread using Function Objects */
    class DisplayThread
    {
    public:
        void operator()()
        {
            for (int i = 0; i < 100; i++)
            {
                cout << "Display Thread is executing..." << endl;
            }
        }
    };

    int main(int argc, char* argv[])
    {
        std::thread dispThread( (DisplayThread()) );
        for (int n = 0; n < 100; ++n)
        {
            cout << "Display from MainThread." << endl;
        }

        cout << "Waiting for thread to complete" << endl;
        dispThread.join();
        cout << "Exiting from Main Thread" << endl;
        return 0;
    }
#elif 1
    /* Creating a thread using Lambda functions */
    int main(int argc, char* argv[])
    {
        int x = 9;
        std::thread thrdObj([] {
            for (int i = 0; i < 100; i++)
            {
                cout << "The lambda-dunction thread is executing..." << endl;
            }
            });

        for (int n = 0; n < 100; ++n)
        {
            cout << "Display from Main Thread" << endl;
        }
        thrdObj.join();
        cout << "Exiting from Main Thread." << endl;
        return 0;
    }
#else
    /* Differentiating between threads */
    void threadFnct()
    {
        cout << "Inside Thread :: ID = " << std::this_thread::get_id() << endl;
    }

    int main(int argc, char* argv[])
    {
        std::thread aliceThread(threadFnct);
        std::thread bobThread(threadFnct);

        if (aliceThread.get_id() != bobThread.get_id())
        {
            cout << "Both threads have different thread-IDs" << endl;
        }
        cout << "From Main Thread :: ID of aliceThread = " << aliceThread.get_id() << endl;
        cout << "From Main Thread :: ID of bobThread = " << bobThread.get_id() << endl;

        aliceThread.join();
        bobThread.join();

        cout << "The Main Thread ID = " << std::this_thread::get_id() << endl;
        return 0;
    }
#endif