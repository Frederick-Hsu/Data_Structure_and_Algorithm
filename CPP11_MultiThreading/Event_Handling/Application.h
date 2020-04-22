#ifndef APPLICATION_H
#define APPLICATION_H

    #include <mutex>
    #include <condition_variable>

    #define HANDLE_EVENT_BY_POLL        1
    #define HANDLE_EVENT_BY_NOTIFY      2
    #define HANDLE_EVENT_MECHANISM      HANDLE_EVENT_BY_NOTIFY

#if (HANDLE_EVENT_MECHANISM == HANDLE_EVENT_BY_POLL)
    class Application
    {
    private:
        std::mutex m_protect;
        bool m_bDataLoadedFlag;
    public:
        Application();
        void loadData();
        void mainTask();
    };
#elif (HANDLE_EVENT_MECHANISM == HANDLE_EVENT_BY_NOTIFY)
    class Application
    {
    private:
        std::mutex m_protect;
        std::condition_variable m_condvar;
        bool m_bDataLoadedFlag;
    public:
        Application();
        void loadData();
        bool isDataLoaded();
        void mainTask();
    };
#endif

#endif  /* APPLICATION_H */
