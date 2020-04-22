#ifndef SCREEN_H
#define SCREEN_H

    #include <string>

    template<int hi, int wd>
    class Screen
    {
    public:
        /* template nontype parameters used to initialize data members */
        Screen() : screen(hi * wd, '#'), cursor(0), height(hi), width(wd) {}
    private:
        std::string             screen;
        std::string::size_type  cursor;
        std::string::size_type  height,     width;
    };

#endif  /* SCREEN_H */