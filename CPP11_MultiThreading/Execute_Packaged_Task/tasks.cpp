#include "tasks.h"

using std::string;

std::string getDataFromDB(std::string token)
{
    string data = "Data fetched from DB by Filter :: " + token;
    return data;
}