#include "returning_value_from_threads.h"

#include <iostream>
#include <thread>
#include <chrono>

void initializer(promise<int> *promiseObj)
{
    cout << "Inside the thread" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    promiseObj->set_value(36);
}

void return_values_from_threads(void)
{
    promise<int> promiseObj;
    future<int> futureObj = promiseObj.get_future();

    thread thd(initializer, &promiseObj);
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "the value returned from another thread is: " << futureObj.get() << endl;
    thd.join();
}