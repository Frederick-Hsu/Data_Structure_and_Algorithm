#include "exceptions.h"
#include "Sales_item.h"
#include <iostream>

using namespace CPlusPlus_Primer;
using namespace std;

isbn_mismatch::isbn_mismatch(const string& s) : logic_error(s)
{
}

isbn_mismatch::isbn_mismatch(const string& s, const string& lhs, const string& rhs) :
    logic_error(s), left(lhs), right(rhs)
{
}

void verify_how_user_defined_exception_works(void)
{
    /* use hypothetical bookstore exceptions */
    Sales_item item1, item2, sum;
    while (cin >> item1 >> item2)   /* read the 2 transactions */
    {
        try
        {
            sum = item1 + item2;    /* calculate their sum */
        }
        catch (const isbn_mismatch& e)
        {
            cerr << e.what() << ": left isbn(" << e.left
                 << ") right isbn(" << e.right << ")"
                 << endl;
        }
    }
}
