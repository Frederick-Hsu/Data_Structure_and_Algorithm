/*!
 *  \file       test_map.c++
 *  \brief
 *
 */


#include <gtest/gtest.h>

#include <map>

TEST(UTester4Map, CheckMapQuery)
{
    std::map<std::string, double> salaries;

    salaries["Pat"] = 7'5000.00;
    std::cout << salaries["Pat"] << std::endl;
    std::cout << salaries["Jan"] << std::endl;

    std::map<std::string, double>::const_iterator iter;
    iter = salaries.find("Chris");
    if (iter == salaries.end())
    {
        std::cout << "Not an employee of this company" << std::endl;
    }
    else
    {
        std::cout << iter->second << std::endl;
    }
}
