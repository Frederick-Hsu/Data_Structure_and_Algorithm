#ifndef APPLICATION_H
#define APPLICATION_H

    #include <mutex>
    #include <condition_variable>
    using namespace std;

    class Application;

    class Application
    {
    public:
        Application();
        void loadData();
        bool isDataLoaded();
        void mainTask();
    private:
        mutex m_mutex;
        bool m_bDataLoaded;
        condition_variable m_condvar;
    };

#endif  /* APPLICATION_H */