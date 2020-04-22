#include "tasks.h"
#include <thread>
#include <chrono>

using std::string;

std::string fetchDataFromDB(std::string recvdData)
{
    /* Make sure that function takes 3 seconds to complete. */
    std::this_thread::sleep_for(std::chrono::seconds(3));

    /* Do something like creating DB connection and fetching data */
    return "DB_" + recvdData;
}

std::string fetchDataFromFile(std::string recvdData)
{
    /* Make sure that function takes 5 seconds to complete. */
    std::this_thread::sleep_for(std::chrono::seconds(5));

    /* Do stuff like fetching data file */
    return "File_" + recvdData;
}
