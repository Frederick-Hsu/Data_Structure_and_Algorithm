#include "race_conditions.h"
#include "Wallet.h"

#include <vector>
#include <iostream>
#include <thread>
using namespace std;

int testMultiThreadedWallet(void)
{
    Wallet walletobj;
    vector<thread> walletThreads;
    for (int cnt = 0; cnt < 5; ++cnt)
    {
        walletThreads.push_back(thread(&Wallet::addMoney, &walletobj, 1000));
    }
    for (vector<thread>::iterator it = walletThreads.begin(); it != walletThreads.end(); ++it)
    {
        it->join();
    }
    return walletobj.getMoney();
}

void verifyMultiThreadConflict(void)
{
    int val = 0;
    for (int loop = 0; loop < 100; ++loop)
    {
        val = testMultiThreadedWallet();
        if (val != 5000)
        {
            cout << "Error at loop count = " << loop << ", Money in Wallet = " << val << endl;
        }
    }
}