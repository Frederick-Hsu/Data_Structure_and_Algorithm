#include "Application.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <functional>
using namespace std;

Application::Application()
{
    m_bDataLoaded = false;
}

void Application::loadData()
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Loading data from XML" << endl;

    lock_guard<mutex> guard(m_mutex);
    m_bDataLoaded = true;
    m_condvar.notify_one();
}

bool Application::isDataLoaded()
{
    return m_bDataLoaded;
}

void Application::mainTask()
{
    cout << "Do some handshaking..." << endl;
    unique_lock<mutex> mlock(m_mutex);
    m_condvar.wait(mlock, bind(&Application::isDataLoaded, this));
    cout << "Do processing on loaded data..." << endl;
}