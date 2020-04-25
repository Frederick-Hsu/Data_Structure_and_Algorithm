#include "exception_error_handling.h"

out_of_stock::out_of_stock(const string& s) : std::runtime_error(s)
{
}

isbn_mismatch::isbn_mismatch(const string& s) : std::logic_error(s)
{
}

isbn_mismatch::isbn_mismatch(const string& s, const string& lhs, const string& rhs)
    : std::logic_error(s), left(lhs), right(rhs)
{
}

isbn_mismatch::~isbn_mismatch() throw()
{
}
