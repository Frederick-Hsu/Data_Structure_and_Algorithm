/**************************************************************************************************
 * Project      : Data_Sharing_and_Race_Conditions
 * Description  : Study how the threads share data with each other and how to manage the race conditions.
 * ================================================================================================
 * File name    : Main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Sat.  02 Nov. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>
#include <thread>

using namespace std;

#include "Wallet.h"

int main(int argc, char* argv[])
{
    int money = 0;

    for (int n = 0; n < 1000; ++n)
    {
        if ((money = testMultiThreadedWallet()) != 5000)
        {
            cout << "Error at count = " << n << ", Money in wallet = " << money << endl;
        }
    }
    return 0;
}
