#ifndef WALLET_H
#define WALLET_H

    #include <mutex>
    using namespace std;

    class Wallet;

    class Wallet
    {
    public:
        Wallet();
        Wallet(int money);
        Wallet(const Wallet& other);
        Wallet& operator=(const Wallet& other);
    private:
        mutex mut;
        int m_Money;
    public:
        int getMoney() const;
        void addMoney(int money);
    };

#endif  /* WALLET_H */