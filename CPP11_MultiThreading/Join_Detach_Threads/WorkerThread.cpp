#include "WorkerThread.h"

#include <iostream>
#include <thread>

using namespace std;

void WorkerThread::operator()()
{
    cout << "Worker Thread " << std::this_thread::get_id() << " is executing..." << endl;
}