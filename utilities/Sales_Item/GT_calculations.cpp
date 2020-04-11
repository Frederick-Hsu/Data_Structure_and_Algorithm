#include "GT_calculations.h"

GT_calculations::GT_calculations(size_t val) : bound(val)
{
}

bool GT_calculations::operator()(const string &str)
{
    return (str.size() >= bound);
}
