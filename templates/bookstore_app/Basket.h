#ifndef BASKET_H
#define BASKET_H

    #include "Sales_item.h"
    #include <set>

    namespace BookStore_App
    {
        class Basket;
    }

    class Basket
    {
    public:
        typedef bool (*Comp)(const Sales_item&, const Sales_item&);
    public:
        typedef multiset<Sales_item, Comp> set_type;
        typedef set_type::size_type size_type;
        typedef set_type::const_iterator const_iter;
    public:
        Basket();
    private:
        multiset<Sales_item, Comp> items;
    public:
        void add_item(const Sales_item& item);
        size_type size(const Sales_item& item) const;
        double total() const;
    };

#endif  /* BASKET_H */
