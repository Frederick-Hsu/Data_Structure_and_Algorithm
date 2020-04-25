#ifndef SCREEN_H
#define SCREEN_H

    #include "CachedObj.h"
    #include <string>

    template<int hi, int wd> class Screen;

    template<int hi, int wd> class Screen : public CachedObj<Screen<hi, wd> >
    {
    public:
        Screen();
    private:
        std::string screen;
        std::string::size_type cursor;
        std::string::size_type height;
        std::string::size_type width;
    };

    template<int hi, int wd> Screen<hi, wd>::Screen()
        : screen(hi * wd, '#'), cursor(0), height(hi), width(wd)
    {
    }

#endif  /* SCREEN_H */
