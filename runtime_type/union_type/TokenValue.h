#ifndef TOKEN_VALUE_H
#define TOKEN_VALUE_H

    #include "../nested_type/Queue.h"

    union TokenValue
    {
        char cval;
        int ival;
        double dval;
    };

    union illegal_members
    {
        Queue<int> fib_que;
        static int is;
        // int &refi;       /* a union may not have reference type */
        Queue<int> *prime_numbers_que;
    };

    class Token
    {
    public:
        /* indicates which kind of value is in val */
        enum TokenKind {INT, CHAR, DBL};
        TokenKind tok;
        union       /* unnamed union */
        {
            char cval;
            int ival;
            double dval;
        } val;      /* member val is a union of the 3 listed types */
    };

    void instantiate_union_type_objs(void);
    void union_discriminant(void);

#endif  /* TOKEN_VALUE_H */
