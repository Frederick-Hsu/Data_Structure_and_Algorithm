#include "NotQuery.h"

namespace CPlusPlus_Primer
{
NotQuery::NotQuery(Query q) : query(q)
{
}

ostream& NotQuery::display(ostream &out) const
/* use the Query output operator, which calls Query::display()
 * that function makes a virtual call to Query_base::display()
 */
{
    return (out << "~(" << query << ")");
}

set<TextQuery::line_no> NotQuery::eval(const TextQuery& file) const
{
    set<line_no> has_val = query.eval(file);
    set<line_no> ret_lines;
    /* for each line in the input file, check whether that line is in has_val
     * if not, add that line number into ret_lines
     */
    for (TextQuery::line_no n = 0; n != file.size(); ++n)
    {
        if (has_val.find(n) == has_val.end())
        {
            ret_lines.insert(n);
        }
    }
    return ret_lines;
}
}
