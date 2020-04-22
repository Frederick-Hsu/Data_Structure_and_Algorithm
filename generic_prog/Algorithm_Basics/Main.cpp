/**************************************************************************************************
 * Project      : Algorithm_Basics
 * Description  : Introduction to the basics of generic algorithms, based on the container.
 * ================================================================================================
 * File name    : Main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Wed.  04 Sep. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/


#include <cstdio>
#include "testing.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
#if 1
    execute_test_cases();
#else
    unsigned hexnumber;
    cin >> hex >> hexnumber;
    cout << "The number is " << hexnumber << endl;
#endif
    return std::getchar();
}