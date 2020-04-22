#include "exceptions.h"

isbn_mismatch::isbn_mismatch(const string& s) : logic_error(s)
{
}

isbn_mismatch::isbn_mismatch(const string& s, const string& lhs, const string& rhs) :
    logic_error(s), left(lhs), right(rhs)
{
}
