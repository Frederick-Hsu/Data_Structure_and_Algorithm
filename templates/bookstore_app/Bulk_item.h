#ifndef BULK_ITEM_H
#define BULK_ITEM_H

    #include "Disc_item.h"

    namespace BookStore_App
    {
        class Bulk_item;
    }

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
        double net_price(size_t) const;
        Bulk_item* clone() const;
    };


#endif  /* BULK_ITEM_H */
