#include "AndQuery.h"
#include <algorithm>

namespace CPlusPlus_Primer
{
    AndQuery::AndQuery(Query left, Query right) : BinaryQuery(left, right, "&")
    {
    }

    set<Query_base::line_no> AndQuery::eval(const TextQuery& file) const
    {
        set<line_no> left = lhs.eval(file), right = rhs.eval(file);
        set<line_no> ret_lines;
        /* write intersection of two ranges to a destination iterator
         * destionation iterator in this call adds elements into ret.
         */
        set_intersection(left.begin(),
                         left.end(),
                         right.begin(),
                         right.end(),
                         inserter(ret_lines, ret_lines.begin()));
        return ret_lines;
    }
}
