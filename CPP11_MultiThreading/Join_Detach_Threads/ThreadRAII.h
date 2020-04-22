#ifndef THREAD_RAII_H
#define THREAD_RAII_H

    #include <thread>

    class ThreadRAII
    {
    public:
        ThreadRAII(std::thread& thrdObj);
        ~ThreadRAII();
    private:
        std::thread& m_thread;
    };

#endif  /* THREAD_RAII_H */
