#include "Bulk_item.h"

namespace BookStore
{
    Bulk_item::Bulk_item(const string& book, double sales_price, size_t qty, double disc_rate) :
        Disc_item(book, sales_price, qty, disc_rate)
    {
    }

    double Bulk_item::net_price(size_t cnt) const
    /* redefines base version so as to implement bulk purchase discount policy */
    {
        /* if specified number of items are purchased, use discounted price */
        if (cnt >= quantity)
        {
            return cnt * (1 - discount) * Disc_item::price;
        }
        else
        {
            return cnt * Disc_item::price;
        }
    }

    Bulk_item::~Bulk_item()
    {
    #ifdef NDEBUG
        cout << "Bulk_item::~Bulk_item() called." << endl;
    #endif
    }

    Bulk_item* Bulk_item::clone() const
    {
        return new Bulk_item(*this);
    }

    Bulk_item::Bulk_item(const Bulk_item& orig) : Disc_item(orig)
    {
    }
}
