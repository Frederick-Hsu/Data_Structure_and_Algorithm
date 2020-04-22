/**************************************************************************************************
 * Project      : Execute_Async_Thread
 * Description  : Study how to execute tasks/threads asynchronously with std::async and 
 *              : std::packaged_task.
 * ================================================================================================
 * File name    : Main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederique Hsu
 * Creation date: Sun.  03 Nov. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std;

#include "tasks.h"

int main(int argc, char* argv[])
{
    /* Get start timestamp */
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
#if 0
    /* Fetch data from DB */
    string dbData = fetchDataFromDB("Data");
    /* Fetch data from File */
    string fileData = fetchDataFromFile("Data");
#else
    // std::future<string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");
    std::future<string> resultFromDB = std::async(std::launch::async | std::launch::deferred,
                                                  fetchDataFromDB,
                                                  "Data");
    /* Fetch data from File */
    string fileData = fetchDataFromFile("Data");

    /* Fetch data from DB
     * will block till data is available in future<string> object.
     */
    string dbData = resultFromDB.get();
#endif
    /* Get end timestamp */
    auto end = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    cout << "Total time taken = " << diff << "seconds" << endl;

    /* Combine the data */
    string data = dbData + " :: " + fileData;
    cout << "Data = " << data << endl;

    return 0;
}
