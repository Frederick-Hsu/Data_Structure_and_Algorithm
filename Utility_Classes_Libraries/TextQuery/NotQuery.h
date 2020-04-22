#ifndef NOT_QUERY_H
#define NOT_QUERY_H

    #include "Query_base.h"
    #include "Query.h"

namespace CPlusPlus_Primer
{
    class NotQuery : public Query_base
    {
        friend Query operator~(const Query&);
    private:
        NotQuery(Query q);
    private:
        set<line_no> eval(const TextQuery& file) const;
        ostream& display(ostream& out) const;
    private:
        const Query query;
    };
}

#endif  /* NOT_QUERY_H */
