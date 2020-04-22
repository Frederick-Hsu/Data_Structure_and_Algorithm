/**************************************************************************************************
 * Project name	: Stacks
 * Description	: This project will delve the data structure of stack, and its operations.
 * ================================================================================================
 * File name	: Main.cpp
 * Description	: This file implements the main() entry function for current project.
 * Creator		: Frederick Hsu
 * Creation date: Sun.	05 Aug. 2019
 * Copyright(C)	2019	All rights reserved.
 *
 **************************************************************************************************/

#include "testing.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    test_HugeNumber_Calculation();

#if 0
    string hugenumber_sum = addHugeNumbers("18274364583929273748459595684373", "8129498165026350236");
    cout << hugenumber_sum << endl;

    if (hugenumber_sum == "18274364583937403246624622034609")
    {
        cout << "This huge numbers adding algorithm through stack is correct." << endl;
    }
#endif
    getchar();
	return 0;
}
