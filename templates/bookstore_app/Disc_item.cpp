#include "Disc_item.h"

Disc_item::Disc_item(const string& book, double sales_price, size_t qty, double disc_rate)
    : Item_base(book, sales_price), quantity(qty), discount(disc_rate)
{
}

Disc_item::Disc_item(const Disc_item& orig) : Item_base(orig)
{
    quantity = orig.quantity;
    discount = orig.discount;
}

Disc_item& Disc_item::operator=(const Disc_item &orig)
{
    if (this != &orig)
    {
        Item_base::operator=(orig);
        quantity = orig.quantity;
        discount = orig.discount;
    }
    return *this;
}

Disc_item::~Disc_item()
{
#if defined(DEBUG)
    cout << "Disc_item::~Disc_item() called." << endl;
#endif
}

pair<size_t, double> Disc_item::discount_policy() const
{
    return make_pair(quantity, discount);
}
