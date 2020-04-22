#ifndef ITEM_BASE_H
#define ITEM_BASE_H

    #include <string>
    using namespace std;

    #include "handle_global.h"

    class HANDLESHARED_EXPORT Item_base
    {
        friend bool operator<(const Item_base& item_a, const Item_base& item_b);
    public:
        Item_base(const string& book = "", double sales_price = 0.00);
        Item_base(const Item_base& orig);
        Item_base& operator=(const Item_base& orig);
        virtual ~Item_base();
    public:
        string book() const;
        virtual double net_price(size_t n) const;
        virtual Item_base* clone() const;
    private:
        string isbn;    /* identifier for the item */
    protected:
        double price;   /* normal, undiscounted price */
    };

#endif  /* ITEM_BASE_H */
