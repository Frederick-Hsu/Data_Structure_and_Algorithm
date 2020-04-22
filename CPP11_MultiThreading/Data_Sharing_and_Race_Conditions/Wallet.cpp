#include "Wallet.h"
#include <vector>
#include <thread>

using namespace std;

Wallet::Wallet() : m_Money(0)
{
}

int Wallet::getMoney() const
{
    return m_Money;
}

void Wallet::addMoney(int money)
{
#if 0       /* Demonstrate race condition scenario on the shared data */
    for (int i = 0; i < money; ++i)
    {
        m_Money++;
    }
#elif defined (USE_LOCK_GUARD)
    mtx.lock();
    for (int i = 0; i < money; ++i)
    {
        m_Money++;
    }
    mtx.unlock();
#else
    std::lock_guard<std::mutex> lockGuard(mtx);
    for (int i = 0; i < money; ++i)
    {
        m_Money++;
    }
#endif
}

int testMultiThreadedWallet()
{
    Wallet commonWallet;

    std::vector<std::thread> threads;
    for (int i = 0; i < 5; i++)
    {
        threads.push_back(std::thread(&Wallet::addMoney, &commonWallet, 1000));
    }

    for (int i = 0; i < 5; i++)
    {
        threads.at(i).join();
    }
    return commonWallet.getMoney();
}
