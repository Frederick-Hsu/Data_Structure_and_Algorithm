#include "Basket.h"

Basket::Basket() : items(compare)
{
}

void Basket::add_item(const Sales_item &item)
{
    items.insert(item);
}

Basket::size_type Basket::size(const Sales_item &item) const
{
    return items.count(item);
}

double Basket::total() const
{
    double sum = 0.00;
    for (const_iter iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter))
    {
        sum += (*iter)->net_price(items.count(*iter));
    }
    return sum;
}
