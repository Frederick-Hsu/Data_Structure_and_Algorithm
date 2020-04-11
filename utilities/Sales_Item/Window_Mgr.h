#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

    #include "Screen.h"

    class Window_Mgr
    {
    public:
        Window_Mgr& relocate(Screen::index r, Screen::index c, Screen& s);
    };

#endif  /* WINDOW_MGR_H */
