#ifndef WALLET_H
#define WALLET_H

    #include <mutex>

    class Wallet
    {
    private:
        int m_Money;
    public:
        Wallet();
        int getMoney() const;
        void addMoney(int money);
    private:
        std::mutex mtx;
    };

    int testMultiThreadedWallet();

#endif  /* WALLET_H */
