#include "Application.h"
#include <thread>
#include <iostream>
#include <functional>

using namespace std;

#if (HANDLE_EVENT_MECHANISM == HANDLE_EVENT_BY_POLL)
    Application::Application() : m_bDataLoadedFlag(false)
    {
    }

    void Application::loadData()
    {
        /* Make this thread sleep for 1 second */
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "Loading data from XML." << endl;

        /* Lock the mutex variable: m_protect */
        std::lock_guard<std::mutex> guard(m_protect);
        /* Set the flag to true, it means data is loaded */
        m_bDataLoadedFlag = true;
    }

    void Application::mainTask()
    {
        cout << "Do some handshaking..." << endl;

        /* Acquire the lock */
        m_protect.lock();
        while (m_bDataLoadedFlag == true)   /* Check whether the flag is set to true or not */
        {
            m_protect.unlock();     /* release the lock */
            std::this_thread::sleep_for(std::chrono::milliseconds(100));   /* sleep for 100 msec */
            m_protect.lock();
        }
        m_protect.unlock();

        cout << "Do processing on loaded data." << endl;
    }
#elif (HANDLE_EVENT_MECHANISM == HANDLE_EVENT_BY_NOTIFY)
    Application::Application() : m_bDataLoadedFlag(false)
    {
    }

    void Application::loadData()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "Loading data from XML." << endl;

        /* Lock the mutext variable : m_protext */
        std::lock_guard<std::mutex> guard(m_protect);
        // std::lock_guard<std::mutex> adoptGuard(m_protect, std::adopt_lock);
        /* Set the flag to true, it means data is loaded. */
        m_bDataLoadedFlag = true;
        /* Notify the condition variable */
        m_condvar.notify_one();
    }

    bool Application::isDataLoaded()
    {
        return m_bDataLoadedFlag;
    }

    void Application::mainTask()
    {
        cout << "Do some handshaking..." << endl;
        /* Acquire the lock */
        std::unique_lock<std::mutex> uniqLocker(m_protect);     /* MUST use the unique_lock */
        /*
        std::unique_lock<std::mutex> adopt_locker(m_protect, std::adopt_lock);
        std::unique_lock<std::mutex> defer_locker(m_protect, std::defer_lock);
        std::unique_lock<std::mutex> try_locker(m_protect, std::try_to_lock);
         */

        /* Start waiting for the Condition Variable to get signaled.
         * wait() will internally release the lock and make the thread blocked.
         * As soon as condition variable get signaled, resume the thread and
         * again acquire the lock. Then check whether condition is met ot not?
         * If condition is met, then continue, else again go in wait.
         */
        m_condvar.wait(uniqLocker, std::bind(&Application::isDataLoaded, this));

        cout << "Do processing on loaded data." << endl;
    }
#endif
