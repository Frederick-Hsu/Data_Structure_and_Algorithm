#include "TokenValue.h"

#include <iostream>
using namespace std;

void instantiate_union_type_objs(void)
{
    TokenValue first_token = {'a'};     /* initialized TokenValue */
    TokenValue last_token;              /* uninitialized TokenValue object */
    TokenValue *ptr = new TokenValue;   /* pointer to a TokenValue object */

    last_token.cval = 'z';
    ptr->ival = 42;

    cout << "sizeof(first_token) = " << sizeof(first_token) << "bytes" << endl;
    cout << "sizeof(TokenValue) = " << sizeof(TokenValue) << "bytes" << endl;
    cout << "sizeof(illegal_members) = " << sizeof(illegal_members) << "bytes" << endl;
    cout << "sizeof(Queue<char>) = " << sizeof(Queue<char>) << "bytes" << endl;
    cout << "sizeof(Queue<long>) = " << sizeof(Queue<long>) << "bytes" << endl;
    cout << "sizeof(Queue<short> *) = " << sizeof(Queue<short> *) << "bytes" << endl;
}

void union_discriminant(void)
{
    Token token;
    switch (token.tok)
    {
    case Token::INT:
        token.val.ival = 42;
        break;
    case Token::CHAR:
        token.val.cval = 'a';
        break;
    case Token::DBL:
        token.val.dval = 0.618;
        break;
    }
}
