#include "Basket.h"

namespace BookStore
{
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
        double sum = 0.00;      /* holds the running total */
        /* find each set of items with the same isbn and calculate the
         * net price for that quantity of items.
         * iter refers to first copy of each book in the set.
         * upper_bound refers to next element with a different isbn.
         */
        for (const_iter iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter))
        {
            /* we know there's at least one element with this key in the Basket
             * virtual call to net_price(n) applies appropriate discounts, if any.
             */
            sum += (*iter)->net_price(items.count(*iter));
        }
        return sum;
    }
}
