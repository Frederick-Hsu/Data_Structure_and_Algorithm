#include "Sales_item.h"

#if (APPROACH == GENERIC_HANDLE_APPROACH)
    Sales_item::Sales_item() : h()
    {
    }

    Sales_item::Sales_item(const Item_base& item) : h(item.clone())
    {
    }

    const Item_base& Sales_item::operator*() const
    {
        return *h;
    }

    const Item_base* Sales_item::operator->() const
    {
        return h.operator->();
    }
#elif (APPROACH == USE_COUNT_APPROACH)
    Sales_item::Sales_item() : p(0), use(new size_t(1))
    {
    }

    Sales_item::Sales_item(const Sales_item& orig) : p(orig.p), use(orig.use)
    {
        ++(*use);
    }

    Sales_item::~Sales_item()
    {
        decr_use();
    }

    Sales_item::Sales_item(const Item_base& item) : p(item.clone()), use(new size_t(1))
    {
    }

    Sales_item& Sales_item::operator=(const Sales_item& orig)
    {
        ++(*orig.use);
        decr_use();
        p = orig.p;
        use = orig.use;
        return *this;
    }

    void Sales_item::decr_use()
    {
        if (--*use == 0)
        {
            delete p;
            delete use;
        }
    }

    const Item_base* Sales_item::operator->() const
    {
        if (p)
        {
            return p;
        }
        else
        {
            throw logic_error("unbound Sales_item* ");
        }
    }

    const Item_base& Sales_item::operator*() const
    {
        if (p)
        {
            return *p;
        }
        else
        {
            throw logic_error("unbound Sales_item& ");
        }
    }

    Item_base* Sales_item::operator->()
    {
        if (p)
        {
            return p;
        }
        else
        {
            throw logic_error("unbound Sales_item* ");
        }
    }

    Item_base& Sales_item::operator*()
    {
        if (p)
        {
            return *p;
        }
        else
        {
            throw logic_error("unbound Sales_item& ");
        }
    }
#endif
