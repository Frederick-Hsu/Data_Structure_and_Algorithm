#ifndef WORD_QUERY_H
#define WORD_QUERY_H

    #include "Query_base.h"

namespace CPlusPlus_Primer
{
    class WordQuery : public Query_base
    {
        friend class Query;
    private:
        WordQuery(const string& s);
        set<line_no> eval(const TextQuery& t) const;
        ostream& display(ostream& out) const;
    private:
        string query_word;      /* word for which to search */
    };
}

#endif  /* WORD_QUERY_H */
