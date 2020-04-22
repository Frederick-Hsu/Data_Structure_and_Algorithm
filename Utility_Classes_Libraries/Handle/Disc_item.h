#ifndef DISC_ITEM_H
#define DISC_ITEM_H

    #include "handle_global.h"
    #include "Item_base.h"

    class HANDLESHARED_EXPORT Disc_item : public Item_base
    {
    public:
        Disc_item(const string& book = "",
                  double sales_price = 0.00,
                  size_t qty = 0,
                  double disc_rate = 0.00);
        Disc_item(const Disc_item& orig);
        Disc_item& operator=(const Disc_item& orig);
        ~Disc_item();
    public:
        pair<size_t, double> discount_policy() const;
        double net_price(size_t) const = 0;     /* pure virtual function */
    protected:
        size_t quantity;    /* purchase size for discount to apply */
        double discount;    /* fractional discount to apply */
    };

#endif  /* DISC_ITEM_H */
