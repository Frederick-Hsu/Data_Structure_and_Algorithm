#include "Bulk_item.h"

Bulk_item::Bulk_item(const string& book, double sales_price, size_t qty, double disc_rate)
    : Disc_item(book, sales_price, qty, disc_rate)
{
}

Bulk_item::Bulk_item(const Bulk_item& orig) : Disc_item(orig)
{
}

double Bulk_item::net_price(size_t cnt) const
{
    if (cnt >= quantity)
    {
        return (cnt * (1 - discount) * Disc_item::price);
    }
    else
    {
        return (cnt * Disc_item::price);
    }
}

Bulk_item::~Bulk_item()
{
#if defined (DEBUG)
    cout << "Bulk_item::~Bulk_item() called." << endl;
#endif
}

Bulk_item* Bulk_item::clone() const
{
    return (new Bulk_item(*this));
}
