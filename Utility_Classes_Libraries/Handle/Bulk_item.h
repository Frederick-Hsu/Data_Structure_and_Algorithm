#ifndef BULK_ITEM_H
#define BULK_ITEM_H

    #include "handle_global.h"
    #include "Disc_item.h"

    class Bulk_item;

    class HANDLESHARED_EXPORT Bulk_item : public Disc_item
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

#endif  /* BULK_ITEM_H */
