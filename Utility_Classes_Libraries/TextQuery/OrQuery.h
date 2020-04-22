#ifndef OR_QUERY_H
#define OR_QUERY_H

    #include "BinaryQuery.h"

namespace CPlusPlus_Primer
{
    class OrQuery : public BinaryQuery
    {
        friend Query operator|(const Query&, const Query&);
    private:
        OrQuery(Query left, Query right);
        set<line_no> eval(const TextQuery& file) const;
    };
}

#endif  /* OR_QUERY_H */
