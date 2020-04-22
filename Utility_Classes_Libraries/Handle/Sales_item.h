#ifndef SALES_ITEM_H
#define SALES_ITEM_H

    #include "handle_global.h"
    #include "Handle.h"
    #include "Item_base.h"

    class HANDLESHARED_EXPORT Sales_item
    {
    public:
        Sales_item();       /* default constructor: unbound handle */
        Sales_item(const Item_base& item);      /* copy item and attach handle to the copy */
    public:
        /* no copy control members: synthesized versions work well,
         * member access operators: forward their work to the Handle class.
         */
        const Item_base& operator*() const;
        const Item_base* operator->() const;
    private:
        Handle<Item_base> h;    /* use-counted handle */
    };

    inline bool compare(const Sales_item& lhs, const Sales_item& rhs)
    {
        return ((lhs->book()) < (rhs->book()));
    }

#endif  /* SALES_ITEM_H */
