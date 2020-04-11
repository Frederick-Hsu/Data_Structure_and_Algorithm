#ifndef IOSTREAM_H
#define IOSTREAM_H

    #include "istream.h"
    #include "ostream.h"

    namespace CPP_Primer
    {
        class iostream;
    }

    class iostream : public istream, public ostream
    {
    public:
    };

#endif  /* IOSTREAM_H */
