#include "pass_args_to_threads.h"
#include "Dummy.h"

#include <iostream>
#include <thread>
#include <chrono>

void threadCallback(int x, string str)
{
    cout << "Passed argument number = " << x << endl;
    cout << "Passed argument string = " << str << endl;
}

void pass_simple_arguments_to_threads(void)
{
    int x = 10;
    string str = "C++ multiple threading";

    thread threadObj(threadCallback, x, str);
    threadObj.join();
}

void newThreadCallback(int* ptr)
{
    cout << "Inside the thread: ptr = " << ptr << endl;
    chrono::milliseconds duration(1000);
    this_thread::sleep_for(duration);
    *ptr = 19;    /* Assign a new value for the pointer */
}

void startNewThread(void)
{
    int* p = new int(10);
    cout << "Inside the Main Thread: *p = " << *p << endl;
    thread thd(newThreadCallback, p);
    thd.detach();

    delete p;
    p = NULL;
}

void not_pass_pointer_argument_to_threads(void)
{
    startNewThread();
    chrono::milliseconds dura(2000);
    this_thread::sleep_for(dura);
}

void refThreadCallback(const int& x)
{
    int& y = const_cast<int&>(x);
    y++;
    cout << "Inside the thread: x = " << x << endl;
}

void pass_reference_arguments_to_threads(void)
{
    int x = 9;
    cout << "In Main Thread: Before thread start, x = " << x << endl;
    thread threadObj(refThreadCallback, ref(x));
    threadObj.join();

    cout << "In Main Thread: After thread join, x = " << x << endl;
}

void pass_memberFunction_arguments_to_threads(void)
{
    Dummy dmy;
    int x = 10;
    thread threadObj(&Dummy::memberFnct, &dmy, x);
    threadObj.join();
}