#include "ThreadRAII.h"

#include <iostream>
using namespace std;

ThreadRAII::ThreadRAII(thread& thrdObj) : m_thread(thrdObj)
{
    cout << "Starting a new thread..." << endl;
}

ThreadRAII::~ThreadRAII()
{
    /* check whether thread is joinable, then detach the thread */
    if (m_thread.joinable())
    {
        m_thread.detach();
    }
    cout << "Detached the thread." << endl;
}
