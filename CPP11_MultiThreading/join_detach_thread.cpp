#include "join_detach_thread.h"

#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void WorkerThread::operator()()
{
    cout << "Worker Thread " << this_thread::get_id() << " is executing." << endl;
}

void join_threads(void)
{
    vector<thread> threadvec;
    for (int cnt = 0; cnt < 10; ++cnt)
    {
        threadvec.push_back(thread( WorkerThread() ));
    }
    /* Now wait for all the worker thread to finish 
     * i.e. call join() function on each thread object.
     */
    cout << "Wait for all the worker thread to finish." << endl;
    for (vector<thread>::iterator it = threadvec.begin(); it != threadvec.end(); ++it)
    {
        it->join();
    }
    cout << "Exiting from Main Thread." << endl;
}

void detach_threads(void)
{
    thread threadObj((WorkerThread()));
    if (threadObj.joinable())
    {
        cout << "Detaching thread." << endl;
        threadObj.detach();
    }
    if (threadObj.joinable())
    {
        cout << "Detaching thread once again." << endl;
        threadObj.detach();
    }

    thread threadObj2((WorkerThread()));
    if (threadObj2.joinable())
    {
        cout << "Joining thread." << endl;
        threadObj2.join();
    }
    if (threadObj2.joinable())
    {
        cout << "Joining thread once again." << endl;
        threadObj2.join();
    }
}