#ifndef SALES_ITEM_H
#define SALES_ITEM_H

    #include "../generic_handle/Handle.h"
    #include "Item_base.h"

    #define USE_COUNT_APPROACH          1
    #define GENERIC_HANDLE_APPROACH     2
    #define APPROACH                    GENERIC_HANDLE_APPROACH

    class Item_base;
    namespace BookStore_App
    {
        class Sales_item;
    }

#if (APPROACH == GENERIC_HANDLE_APPROACH)
    class Sales_item
    {
    public:
        Sales_item();   /* default constructor: unbound handle */
        Sales_item(const Item_base& item);  /* copy item and attach handle to the copy */
    public:
        const Item_base& operator*() const;
        const Item_base* operator->() const;
    private:
        Handle<Item_base> h;    /* use-counted handle */
    };
#elif (APPROACH == USE_COUNT_APPROACH)
    class Sales_item
    {
    public:
        Sales_item();
        explicit Sales_item(const Item_base& item);
        Sales_item(const Sales_item& orig);
        Sales_item& operator=(const Sales_item& orig);
        ~Sales_item();
    public:
        const Item_base* operator->() const;
        const Item_base& operator*() const;
        Item_base* operator->();
        Item_base& operator*();
    private:
        Item_base* p;
        size_t* use;
    private:
        void decr_use();
    };
#endif

    inline bool compare(const Sales_item& lhs, const Sales_item& rhs)
    {
        return ( (lhs->book()) < (rhs->book()) );
    }

    // typedef bool (*Comp)(const Sales_item&, const Sales_item&);

#endif  /* SALES_ITEM_H */
