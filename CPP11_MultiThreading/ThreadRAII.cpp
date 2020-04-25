#include "ThreadRAII.h"

#include <iostream>

ThreadRAII::ThreadRAII(thread& threadObj) : m_thread(threadObj)
{
    cout << "called ThreadRAII::ThreadRAII() ctor." << endl;
}

ThreadRAII::~ThreadRAII()
{
    /* Check whether thread is joinable, then detach the thread */
    if (m_thread.joinable())
    {
        m_thread.detach();
        cout << "current thread had been detached now." << endl;
    }
    cout << "called ThreadRAII::~ThreadRAII() dtor" << endl;
}

void thread_safe_fnct(void)
{
    for (int index = 0; index < 100; ++index)
    {
        cout << "thread_safe_fnct is executing..." << endl;
    }
}

void create_safe_thread(void)
{
    thread threadObj(thread_safe_fnct);
    ThreadRAII wrapperObj(threadObj);
}