#include "async_thread_handling.h"

#include <thread>
#include <chrono>
#include <iostream>
#include <future>

string fetchDataFromDB(string recvData)
{
    /* Make sure that this function will take 5 seconds to complete. */
    this_thread::sleep_for(chrono::seconds(5));
    /* Return stuff like creating DB connection and featching data */
    return ("DB_" + recvData);
}

string fetchDataFromFile(string recvData)
{
    this_thread::sleep_for(chrono::seconds(4));
    /* Do stuff like fetching data from File */
    return "File_" + recvData;
}

void execute_single_thread(void)
{
    /* Get start time point */
    chrono::system_clock::time_point start = chrono::system_clock::now();
    /* Fetch data from database */
    string dbData = fetchDataFromDB("Data");
    /* Fetch data from file */
    string fileData = fetchDataFromFile("Data");
    /* Get end time point */
    auto end = chrono::system_clock::now();
    auto diff = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "Total time elapsed " << diff << " seconds." << endl;
    /* Combine the data */
    string data = dbData + " :: " + fileData;
    cout << "The data = " << data << endl;
}

void async_execute_thread(void)
{
    chrono::system_clock::time_point start = chrono::system_clock::now();

    future<string> resultFromDB = async(launch::async, fetchDataFromDB, "Data");
    /* Fetch data from file */
    string fileData = fetchDataFromFile("Data");
    /* Fetch data from DB, will block till promise<string> data is available 
     * in the future<string> object 
     */
    string dbData = resultFromDB.get();
    
    auto end = chrono::system_clock::now();
    auto diff = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "Total time elapsed " << diff << " seconds." << endl;

    string data = fileData + " :: " + dbData;
    cout << "Data = " << data << endl;
}

string DataFetcher::operator()(string recvData)
{
    this_thread::sleep_for(chrono::seconds(5));
    return "File_" + recvData;
}

void async_with_functor_or_lambda_callback(void)
{
    chrono::system_clock::time_point start = chrono::system_clock::now();
    #if 0
        /* Calling std::async with functor */
        future<string> fileResult = async(DataFetcher(), "Data");
    #else
        /* calling std::async with lambda function */
        future<string> fileResult = async([](string recvData){
            this_thread::sleep_for(chrono::seconds(5));
            return "File_" + recvData;
        }, "Data");
    #endif
    string dbData = fetchDataFromDB("Data");
    string fileData = fileResult.get();

    auto end = chrono::system_clock::now();
    auto diff = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "Total time elapsed " << diff << " seconds." << endl;

    string data = fileData + " :: " + dbData;
    cout << "Data = " << data << endl;
}