#include "Window_Mgr.h"

Window_Mgr& Window_Mgr::relocate(Screen::index r, Screen::index c, Screen &s)
{
    s.height += r;
    s.width += c;
    return *this;
}
