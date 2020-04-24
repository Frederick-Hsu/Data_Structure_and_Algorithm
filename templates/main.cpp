/**************************************************************************************************
 * Project name : templates
 * Description  : Study the generic programming techniques, how to utilize the templates in C++.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file will implements the main() entry function for current project.
 * Creator      : Frederique Hsu
 * Creation date: Sun.  29 March 2020
 * Copyright(C) 2020    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>

#include "testing.h"

int main(int argc, char* argv[])
{
    std::cout << "C++ standard no.: " << __cplusplus << std::endl;

    execute_test_items();
    return 0;
}
