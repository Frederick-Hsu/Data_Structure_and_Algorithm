#include "Screen.h"

Screen::Action Screen::Menu[] = {&Screen::home,
                                 &Screen::forward,
                                 &Screen::back,
                                 &Screen::up,
                                 &Screen::down};

char Screen::get() const
{
    return (contents.c_str())[0];
}

char Screen::get(Screen::index ht, Screen::index wd) const
{
    return contents.c_str()[ht * wd];
}

Screen& action(Screen& other, Action)
{
    Screen* newScreen = new Screen(other);
    return *newScreen;
}

Screen& Screen::move(Directions cm)
{
    (this->*Menu[cm])();
    return *this;
}

Screen& Screen::home()
{
    cursor = 0;
    height = 0;
    width = 0;
    contents[height * width] = 'H';
    return *this;
}

Screen& Screen::forward()
{
    width += 1;
    contents[height * width] = 'F';
    return *this;
}

Screen& Screen::back()
{
    width -= 1;
    contents[height * width] = 'B';
    return *this;
}

Screen& Screen::up()
{
    height += 1;
    contents[height * width] = 'U';
    return *this;
}

Screen& Screen::down()
{
    height -= 1;
    contents[height * width] = 'D';
    return *this;
}



void verify_how_class_member_pointer_works(void)
{
    /* demonstrate how to use the pointer of member function */
    Screen myScreen;
    char c1 = myScreen.get();       /* call Screen::get() on myScreen */
    char c2 = (myScreen.*pmf)();    /* equivalent to call Screen::get() */

    Screen *pscreen = &myScreen;
    c1 = pscreen->get();            /* call Screen::get() on object to which pscreen points */
    c2 = (pscreen->*pmf)();         /* equivalent call to Screen::get() */

    char (Screen::*pmf2)(Screen::index, Screen::index) const;
    pmf2 = &Screen::get;

    c1 = myScreen.get(0, 0);
    c2 = (myScreen.*pmf2)(0, 0);
}

#if 0
void use_data_member_pointers(void)
{
    Screen::index Screen::*pindex = &Screen::width;
    Screen myScreen;

    /* equivalent ways to fetch width member of myScreen */
    Screen::index idx1 = myScreen.width;    /* directly */
    Screen::index idx2 = myScreen.*pindex;  /* dereference to get width */

    Screen *pscreen = &myScreen;
    idx1 = pscreen->width;
    idx2 = pscreen->*pindex;
}
#endif

void access_member_function_pointers_table(void)
{
    Screen myScreen;
    myScreen.move(Screen::HOME);
    myScreen.move(Screen::DOWN);
}
