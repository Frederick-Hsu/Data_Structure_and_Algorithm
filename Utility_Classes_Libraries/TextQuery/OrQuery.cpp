#include "OrQuery.h"

namespace CPlusPlus_Primer
{
    OrQuery::OrQuery(Query left, Query right) : BinaryQuery(left, right, "|")
    {
    }

    set<Query_base::line_no> OrQuery::eval(const TextQuery& file) const
    {
        /* virtual calls through the Query handle to get result sets for the operands */
        set<line_no> right = rhs.eval(file);
        set<line_no> ret_lines = lhs.eval(file);    /* destination to hold results */

        /* inserts the lines from right that are not already in ret_lines */
        ret_lines.insert(right.begin(), right.end());
        return ret_lines;
    }
}
