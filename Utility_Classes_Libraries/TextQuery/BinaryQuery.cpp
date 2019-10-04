#include "BinaryQuery.h"

BinaryQuery::BinaryQuery(Query left, Query right, string op) : lhs(left), rhs(right), oper(op)
{
}

ostream& BinaryQuery::display(ostream &out) const
{
    return (out << "(" << lhs << " " << oper << " " << rhs << ")");
}
