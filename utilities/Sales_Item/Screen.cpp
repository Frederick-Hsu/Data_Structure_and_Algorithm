#include "Screen.h"

Screen::Screen() : contents(""), cursor(0), height(0), width(0)
{
}

Screen::Screen(Screen::index ht, Screen::index wd) : height(ht), width(wd)
{
    cursor = ht * width + wd;
    contents = "";
}

char Screen::get() const
{
    return contents[cursor];
}

char Screen::get(index ht, index wd) const
/* inline declared in the class declaration; no need to repeat on the implementation */
{
    index row = ht * width;     /* compute the row location */
    return contents[row + wd];  /* offset by wd to fetch specified character */
}

inline Screen::index Screen::get_cursor() const
/* not declared as inline inside the class declaration,
 * but OK to make inline definition
 */
{
    return cursor;
}

Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen& Screen::move(index r, index c)
{
    index row = r * width;
    cursor = row + c;
    return *this;
}

void Screen::do_display(ostream &os) const
{
    ++access_ctr;
    os << contents;
}

Screen& Screen::display(ostream &os)
{
    do_display(os);
    return *this;
}

const Screen& Screen::display(ostream &os) const
{
    do_display(os);
    return *this;
}

void Screen::dummy_fcnt(index height)
/* bad practice: Names local to member functions shouldn't hide member names */
{
    cursor = width * this->height;      /* member height */
    cursor = width * Screen::height;    /* member height */
}

void Screen::setHeight(index var)
{
    height = verify(var);
}

Screen::index verify(Screen::index variable)
{
    return variable;
}
