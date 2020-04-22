#include "Query.h"
#include "Query_base.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

namespace CPlusPlus_Primer
{
    Query::Query(const Query& orig) : q(orig.q), use(orig.use)
    {
        ++(*use);
    }

    Query::~Query()
    {
        decr_use();
    }

    Query::Query(Query_base* query) : q(query), use(new size_t(1))
    {
    }

    void Query::decr_use()
    {
        if (--(*use) == 0)
        {
            delete q;
            delete use;
        }
    }

    set<TextQuery::line_no> Query::eval(const TextQuery &t) const
    {
        return q->eval(t);
    }

    ostream& Query::display(ostream &out) const
    {
        return q->display(out);
    }

    inline Query operator~(const Query& oper)
    {
        return (new NotQuery(oper));
    }

    inline Query operator&(const Query& lhs, const Query& rhs)
    {
        return (new AndQuery(lhs, rhs));
    }

    inline Query operator|(const Query& lhs, const Query& rhs)
    {
        return new OrQuery(lhs, rhs);
    }
}
