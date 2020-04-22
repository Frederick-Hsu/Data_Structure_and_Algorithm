#include "Disc_item.h"

namespace BookStore
{
    Disc_item::Disc_item(const string& book, double sales_price, size_t qty, double disc_rate) :
        Item_base(book, sales_price), quantity(qty), discount(disc_rate)
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
            Item_base::operator=(orig);     /* assign the base part */
            quantity = orig.quantity;
            discount = orig.discount;
        }
        return *this;
    }

    Disc_item::~Disc_item()
    {
        /* each destructor will be in charge of clean up its own members solely,
         * the derived's destructor will no need take charge of clean up base's members.
         */
    #ifdef NDEBUG
        cout << "Disc_item::~Disc_item() called." << endl;
    #endif
        // Item_base::~Item_base() will invoked automatically by compiler at last.
    }

    pair<size_t, double> Disc_item::discount_policy() const
    {
        return make_pair(quantity, discount);
    }
}
