/**************************************************************************************************
 * Project      : Pass_Arguments_To_Threads
 * Description  : Study how to pass arguments to the thread callback functions.
 * ================================================================================================
 * File name    : Main.cpp
 * Description  : This file will implement the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Sat.  02 Nov. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>
#include <thread>
#include <string>

using namespace std;

#include "CDummy.h"

#if 0
    void threadCallBack(int x, string str)
    {
        cout << "Passed number x = " << x << endl;
        cout << "Passed string str = " << str << endl;
    }
    /* Passing simple arguments to a std::thread in C++11
     * By default, all arguments are copied into the internal storage of new thread.
     */
    int main(int argc, char* argv[])
    {
        int number = 10;
        string mesg = "Sample string";

        std::thread thrdObj(threadCallBack, number, mesg);
        thrdObj.join();

        return 0;
    }
#elif 0
    /* Do not pass addresses of variables from local stack to thread's callback function.
     * Because it might be possible that local variable in main thread goes out of scope,
     * but the child thread is still trying to access it through its address.
     * In such scenario accessing invalid addresses can cause unexpected behaviour.
     */
    void newThreadCallback(int* ptr)
    {
        cout << "Inside thread: "" : ptr = " << ptr << endl;
        std::chrono::milliseconds dura(1000);
        std::this_thread::sleep_for(dura);
        *ptr = 2019;
    }

    void startNewThread()
    {
        int i = 10;
        cout << "Inside main thread : "" : i = " << i << endl;
        std::thread childThread(newThreadCallback, &i);
        childThread.detach();

        cout << "Inside main thread : "" : i = " << i << endl;
    }

    int main(int argc, char* argv[])
    {
        startNewThread();
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
        return 0;
    }
#elif 0
    /* Be careful while passing pointer to memory allocated on heap to thread.
     * because it might be possible that some thread deletes that memory 
     * before new thread tries to access it.
     * In such scenario accessing invalid address can cause unexpected behaviour.
     */
    void newThreadCallback(int* p)
    {
        cout << "Inside the child thread : "" : ptr = " << p << endl;
        std::chrono::milliseconds dura(1000);
        std::this_thread::sleep_for(dura);
        *p = 2019;
    }

    void launchNewThread()
    {
        int *pnum = new int();
        *pnum = 10;
        cout << "Inside the main thread : "" : *ptr = " << *pnum << endl;

        std::thread newThread(newThreadCallback, pnum);
        newThread.detach();

        delete pnum;
        pnum = NULL;
    }

    int main(int argc, char* argv[])
    {
        launchNewThread();
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
        return 0;
    }
#elif 0
    void threadCallback(int const& x)
    {
        int& y = const_cast<int&>(x);
        y++;
        cout << "Inside the child thread : x = " << x << endl;
    }

    int main(int argc, char* argv[])
    {
        int x = 9;
        cout << "Inside the main thread : Before new child thread starts, x = " << x << endl;
    #if defined (PASS_REF_TOTHREAD)
        std::thread thrdObj(threadCallback, x);     // Even if threadCallback accepts arguments as reference, but still changes done it
        thrdObj.join();                             // are not visible outside the thread.  Because x in the thread function threadCallback()
                                                    // is reference to the temporary value copied at the new thread's stack.
    #else
        std::thread thrdObj(threadCallback, std::ref(x));
        thrdObj.join();
    #endif
        cout << "Inside main thread : After child thread joins, x = " << x << endl;
        return 0;
    }
#elif 1
    /* Starting thread with static member function 
     * As static function are not associated with any object of class, so we can directly pass
     * the static member function of class as thread function without passing any pointer to object.
     */
    class Task
    {
    public:
        static void test(string command)
        {
            for (int i = 0; i < 20; ++i)
            {
                cout << command << " :: " << i << endl;
            }
        }
    };

    int main(int argc, char* argv[])
    {
        std::thread taskThread(&Task::test, "Task");
        taskThread.join();
        return 0;
    }
#else
    int main(int argc, char* argv[])
    {
        CDummy dummyObj;
        int x = 10;

        std::thread thrdObj(&CDummy::work, &dummyObj, x);
        thrdObj.join();

        cout << "Inside main thread : x = " << x << endl;
        return 0;
    }
#endif
