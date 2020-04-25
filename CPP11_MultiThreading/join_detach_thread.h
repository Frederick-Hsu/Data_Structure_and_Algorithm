#ifndef JOIN_DETACH_THREAD_H
#define JOIN_DETACH_THREAD_H

    class WorkerThread;

    class WorkerThread
    {
    public:
        void operator()();
    };

    void join_threads(void);
    void detach_threads(void);

#endif  /* JOIN_DETACH_THREAD_H */
