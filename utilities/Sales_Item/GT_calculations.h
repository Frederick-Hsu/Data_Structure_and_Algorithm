#ifndef GT_CALCULATIONS_H
#define GT_CALCULATIONS_H

    #include <stddef.h>
    #include <string>
    using namespace std;

    class GT_calculations
    {
    public:
        GT_calculations(size_t val = 0);
        bool operator()(const string& str);
    private:
        string::size_type bound;
    };

#endif  /* GT_CALCULATIONS_H */
