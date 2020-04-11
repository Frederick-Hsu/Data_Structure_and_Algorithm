#ifndef SCRREN_H
#define SCRREN_H

    #include <string>
    #include <iostream>
    using namespace std;

    class Window_Mgr;
    class Screen;   /* forward declaration */


    class Screen
    {
        friend class Window_Mgr;
    public:
        typedef string::size_type index;
    public:
        Screen();
        Screen(index ht, index wd);
    public:
        char get() const;
        /* explicitly declared as inline; will be defined outside the class declaration */
        inline char get(index ht, index wd) const;
        /* inline not specified in class declaration, but can be defined inline later */
        index get_cursor() const;

        Screen& move(index row, index column);
        Screen& set(char);
        Screen& set(index, index, index);
        Screen& display(ostream& os);
        const Screen& display(ostream& os) const;
        void dummy_fcnt(index height);
        void setHeight(index);
        /* bkground refers to the static member,
         * declared later in the class definition.
         */
        Screen& clear(char background = bkground);
    private:
        string contents;
        index cursor;
        index height;
        index width;
        mutable size_t access_ctr;      /* may change in a const members */
        static const char bkground = '#';
    private:
        inline void do_display(ostream& os) const;
    };

    Screen::index verify(Screen::index);

    class LinkScreen
    {
        Screen window;
        LinkScreen* next;
        LinkScreen* prev;
    };

#endif  /* SCRREN_H */
