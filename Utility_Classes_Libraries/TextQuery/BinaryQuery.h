#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H

    #include "Query_base.h"
    #include "Query.h"

namespace CPlusPlus_Primer
{
    class BinaryQuery : public Query_base
    {
    protected:
        BinaryQuery(Query left, Query right, string op);
    protected:
        ostream& display(ostream& out) const;
    protected:
        const Query lhs;
        const Query rhs;        /* right- and left-hand operands */
        const string oper;      /* name of the operator */
    };
}

#endif  /* BINARY_QUERY_H */
