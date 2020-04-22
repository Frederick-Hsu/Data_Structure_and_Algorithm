/**************************************************************************************************
 * Project      : Join_Detach_Threads
 * Description  : We will discuss about joining and detaching of std::thread
 * ================================================================================================
 * File name    : Main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Fri.  01 Nov. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

#include "WorkerThread.h"
#include "ThreadRAII.h"

#if 0
    int main(int argc, char* argv[])
    {
        vector<std::thread> threadVec;
        for (int i = 0; i < 10; ++i)
        {
            threadVec.push_back(std::thread(WorkerThread()));
        }
        /* Now wait for all the worker thread to finish, i.e.
         * Call join() function on each thread object.
         */

        cout << "Wait for all the worker threads to finish." << endl;
        std::for_each(threadVec.begin(), threadVec.end(), std::mem_fn(&std::thread::join));

        cout << "Exiting from Main Thread." << endl;
        return 0;
    }
#elif 0
    /* Detaching threads using std::thread::detach() */
    int main(int argc, char* argv[])
    {
        std::thread aliceThreadObj((WorkerThread()));
        if (aliceThreadObj.joinable())
        {
            cout << "Detaching thread..." << endl;
            aliceThreadObj.detach();
        }
        if (aliceThreadObj.joinable())
        {
            cout << "Detached thread." << endl;
            /* Never call join() or detach() on std::thread object with no associated executing thread */
            aliceThreadObj.detach();
        }

        std::thread bobThreadObj((WorkerThread()));
        /* before calling join() or detach(), we should check whether the thread is join-able every time. */
        if (bobThreadObj.joinable())
        {
            cout << "Joining thread..." << endl;
            bobThreadObj.join();
        }
        if (bobThreadObj.joinable())
        {
            cout << "Joined thread." << endl;
            bobThreadObj.join();
        }
        return 0;
    }
#elif 0
    /* Never forget to call either join() or detach() on a thread object with associated executing thread */
    int main()
    {
        std::thread thrdObj((WorkerThread()));
        /* Program will terminate as we haven't called either join() or detach() with the std::thread object.
         * Hence std::thread's object destructor will terminate the program.
         */
        // thrdObj.detach();
        return 0;
    }
#else
    /* To prevent from forgetting call either join() or detach in case of exceptions,
     * we should use RESOURCE ACQUISITION IS INITIALIZATION (i.e. RAII)
     */
    void threadFnct()
    {
        for (int i = 0; i < 100; i++)
        {
            cout << "this threadFnct is executing..." << endl;
        }
    }

    int main(int argc, char* argv[])
    {
        std::thread thrdObj(threadFnct);
        ThreadRAII wrapperObj(thrdObj);     /* If we comment this line, then program will crash. */
        return 0;
    }
#endif
