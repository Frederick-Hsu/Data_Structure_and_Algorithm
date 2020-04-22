#ifndef QUERY_H
#define QUERY_H

    #include "TextQuery.h"

    #include <string>
    using namespace std;

namespace CPlusPlus_Primer
{
    class Query_base;

    /* handle class to manage the Query_base inheritance hierarchy */
    class Query
    {
        /* these operators need access to the Query_base* constructor */
        friend Query operator~(const Query&);
        friend Query operator|(const Query&, const Query&);
        friend Query operator&(const Query&, const Query&);
    public:
        Query(const string&);       /* build a new WordQuery */
        Query(const Query& orig);
        Query& operator=(const Query& orig);
        ~Query();
    public:
        /* interface functions: will call corresponding Query_base operations */
        set<TextQuery::line_no> eval(const TextQuery& t) const;
        ostream& display(ostream& out) const;
    private:
        Query(Query_base* query);
        Query_base* q;
        size_t* use;
    private:
        void decr_use();
    };

    inline ostream& operator<<(ostream& out, const Query& q)
    {
        return q.display(out);
    }
}

#endif  /* QUERY_H */
