#include "SmallInt.h"

#include <exception>
#include <stdexcept>

SmallInt::SmallInt(int i) : val(static_cast<size_t>(i))
{
    if ((i < 0) || (i > 255))
    {
        throw std::out_of_range("Bad SmallInt initializer");
    }
}

SmallInt operator+(const SmallInt& a, const SmallInt& b)
{
    int num = static_cast<int>(a.val) + static_cast<int>(b.val);
    return SmallInt(num);
}

Integral::Integral(int i) : val(static_cast<size_t>(i))
{
}

Integral::operator SmallInt() const
{
    return (val % 256);
}
