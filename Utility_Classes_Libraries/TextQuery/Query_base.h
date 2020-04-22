#ifndef QUERY_BASE_H
#define QUERY_BASE_H

    #include "TextQuery.h"

    #include <iostream>
    using namespace std;

namespace CPlusPlus_Primer
{
    class Query_base
    {
        friend class Query;
    public:
    protected:
        typedef TextQuery::line_no line_no;
        virtual ~Query_base();
    private:
        /* eval returns the |set| of lines that this Query matches */
        virtual set<line_no> eval(const TextQuery&) const = 0;
        /* display prints the query */
        virtual ostream& display(ostream& = cout) const = 0;
    };
}


#endif  /* QUERY_BASE_H */
