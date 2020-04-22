#include "Wallet.h"

#define MUTEX_LOCK_UNLOCK   1
#define MUTEX_LOCK_GUARD    2

#define LOCK_MECHANISM      MUTEX_LOCK_GUARD

Wallet::Wallet() : m_Money(0) {}
Wallet::Wallet(int money) : m_Money(money) {}
Wallet::Wallet(const Wallet& other) : m_Money(other.m_Money) {}
Wallet& Wallet::operator=(const Wallet& other)
{
    m_Money = other.m_Money;
    return *this;
}
int Wallet::getMoney() const
{
    return m_Money;
}
void Wallet::addMoney(int money)
{
    #if (LOCK_MECHANISM == MUTEX_LOCK_UNLOCK)
        mut.lock();
        for (int i = 0; i < money; ++i)
        {
            m_Money++;
        }
        mut.unlock();
    #elif (LOCK_MECHANISM == MUTEX_LOCK_GUARD)
        lock_guard<mutex> lockGuard(mut);
        /* In constructor it locks the mutex */
        for (int i = 0; i < money; ++i)
        {
            /* If some exception occurs at this point, then destructor of lockGuard will
             * be called due to stack unwinding.
             */
            m_Money++;
        }
        /* Once function exits, then destructor of lockGuard object will be called automatically,
         * In destructor, it unlocks the mutex. 
         */
    #endif
}