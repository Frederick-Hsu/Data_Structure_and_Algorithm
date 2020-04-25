#include "create_async_packaged_task.h"

#include <future>
#include <thread>
#include <iostream>

string getDataFromDB(string token)
{
    string data = "Data fetch from DB by filter::" + token;
    return data;
}

void execute_async_packaged_task(void)
{
    /* Create a packaged_task<> to encapsulate the callback, i.e. function */
    packaged_task<string(string)> task(getDataFromDB);
    /* Fetch the associated future<> from packaged_task<> */
    future<string> result = task.get_future();

    /* Pass the packaged_task to thread to run asynchronously */
    thread thd(std::move(task), "Arg");
    /* Join the thread, it will block and return when thread is finished. */
    thd.join();

    /* Fetch the result from packaged_task<>, i.e. value returned by getDataFromDB */
    string data = result.get();
    cout << "Data = " << data << endl;
}