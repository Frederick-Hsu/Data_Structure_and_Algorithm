#include "thread_creation.h"

#include <iostream>
#include <thread>
using namespace std;

void thread_function()
{
    for (int i = 0; i < 1000; ++i)
    {
        cout << "thread function is executing..." << endl;
    }
    cout << "Inside Thread::ID = " << this_thread::get_id() << endl;
}

void DisplayThread::operator()()
{
    for (int i = 0; i < 1000; ++i)
    {
        cout << "Display Thread is executing..." << endl;
    }
}
