#ifndef THREAD_RAII_H
#define THREAD_RAII_H

    #include <thread>
    using namespace std;

    class ThreadRAII;

    class ThreadRAII
    {
    public:
        ThreadRAII(thread& threadObj);
        ~ThreadRAII();
    public:
        thread& m_thread;
    };

    void thread_safe_fnct(void);
    void create_safe_thread(void);

#endif  /* THREAD_RAII_H */