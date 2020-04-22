#ifndef ITEM_BASE_H
#define ITEM_BASE_H

    #include <string>
    #include <iostream>

    using namespace std;

    namespace BookStore_App
    {
        class Item_base;
    }

    class Item_base
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

    void print_total(ostream& os, const Item_base& item, size_t n);
    void get_price(Item_base object, const Item_base* pointer, const Item_base& reference);

#endif  /* ITEM_BASE_H */
