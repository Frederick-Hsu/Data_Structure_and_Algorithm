#include "WordQuery.h"

namespace CPlusPlus_Primer
{
    WordQuery::WordQuery(const string& s) : query_word(s)
    {
    }

    set<Query_base::line_no> WordQuery::eval(const TextQuery& t) const
    {
        return t.run_query(query_word);
    }

    ostream& WordQuery::display(ostream& out) const
    {
        return (out << query_word);
    }
}
