#include "misc.h"

#include <string>

void instantiate_template_friend_objects(void)
{
    Bar<int> bi(100);       /* Foo3<int> and templ_fnct3<int> are friends */
    Bar<std::string> bs("example");     /* Foo3<string>, templ_fnct3<string> are friends */
}

void access_class_template_static_member(void)
{
    Foo1<int> foobj, myFoobj;
    std::size_t cnt = Foo1<int>::count();   /* instantiate Foo1<int>::count() */
    cnt = foobj.count();                    /* OK: uses Foo1<int>::count() */
    cnt = myFoobj.count();                  /* OK: uses Foo1<int>::count() */
    // cnt = Foo1::count();                 /* Error: which template instantiation */
}