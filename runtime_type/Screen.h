#ifndef SCREEN_H
#define SCREEN_H

    #include <string>

    class Screen;

    class Screen
    {
    public:
        typedef std::string::size_type index;
    public:
        char get() const;
        char get(index ht, index wd) const;

        /* cursor movement functions */
        Screen& home();
        Screen& forward();
        Screen& back();
        Screen& up();
        Screen& down();
    public:
        /* Action is pointer that can be assigned any of the cursor movement function members */
        typedef Screen& (Screen::*Action)();
        static Action Menu[];       /* function table */
        /* specify whichdirection to move */
        enum Directions {HOME, FORWARD, BACK, UP, DOWN};
        Screen& move(Directions);
    private:
        std::string contents;
        index cursor;
        index height;
        index width;
    };

    char (Screen::*pmf)() const = &Screen::get;
    typedef char (Screen::*Action)(Screen::index, Screen::index) const;     /* Action is a type name */
    Action get = &Screen::get;

    /* action takes a reference to a Screen and a pointer to Screen member function */
    Screen& action(Screen&, Action = &Screen::get);


    void verify_how_class_member_pointer_works(void);
    void access_member_function_pointers_table(void);

#endif  /* SCREEN_H */
