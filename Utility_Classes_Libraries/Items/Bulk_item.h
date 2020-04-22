#ifndef BULK_ITEM_H
#define BULK_ITEM_H

    #include "Disc_item.h"

namespace BookStore
{
    class Bulk_item;

    /* discount kicks in when a specified number of copies of same book are
     * sold, the discount is expressed as a fraction used to reduce the normal price.
     */
    class Bulk_item : public Disc_item
    {
    public:
        Bulk_item(const string& book = "",
                  double sales_price = 0.00,
                  size_t qty = 0,
                  double disc_rate = 0.00);
        Bulk_item(const Bulk_item& orig);
        ~Bulk_item();
    public:
        double net_price(size_t n) const;
        Bulk_item* clone() const;
    private:
    };
}

#endif  /* BULK_ITEM_H */
