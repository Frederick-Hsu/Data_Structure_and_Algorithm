#ifndef SALES_ITEM_H
#define SALES_ITEM_H

    #include <cstddef>
    #include "Item_base.h"

namespace BookStore
{
    class Sales_item    /* use counted handle class for the Item_base hierarchy */
    {
    public:
        Sales_item();
        explicit Sales_item(const Item_base& item);
        Sales_item(const Sales_item& orig);
        Sales_item& operator=(const Sales_item& orig);
        ~Sales_item();
    public:
        const Item_base* operator->() const;    /* arrow operator */
        const Item_base& operator*() const;     /* dereference operator */
        Item_base* operator->();
        Item_base& operator*();
    private:
        Item_base* p;   /* pointer to shared item */
        size_t* use;    /* pointer to shared use count */
    private:
        void decr_use();
    };

    inline bool compare(const Sales_item& lhs, const Sales_item& rhs)
    {
        return ((lhs->book()) < (rhs->book()));
    }

    /* type of the comparison function used to order the multiset */
    typedef bool (*Comp)(const Sales_item&, const Sales_item&);
}

#endif  /* SALES_ITEM_H */
