#include "event_handling.h"
#include "Application.h"

#include <thread>
using namespace std;

void handle_event(void)
{
    Application app;

    thread threadobj1(&Application::mainTask, &app);
    thread threadobj2(&Application::loadData, &app);

    threadobj2.join();
    threadobj1.join();
}