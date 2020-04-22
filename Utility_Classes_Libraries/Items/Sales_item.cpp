#include "Sales_item.h"

#include <stdexcept>

namespace BookStore
{
    Sales_item::Sales_item() : p(0), use(new size_t(1))
    /* default constructor: unbound handle */
    {
    }

    Sales_item::Sales_item(const Sales_item& orig) : p(orig.p), use(orig.use)
    /* copy constructor control members to manage the use count and pointers */
    {
        ++*use;
    }

    Sales_item::~Sales_item()
    {
        decr_use();
    }

    const Item_base* Sales_item::operator->() const
    {
        if (p)
        {
            return p;
        }
        else
        {
            throw logic_error("unbound Sales_item*");
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
            throw logic_error("unbound Sales_item");
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
            throw logic_error("Unbound Sales_item*");
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
            throw logic_error("Unbound Sales_item");
        }
    }

    void Sales_item::decr_use()
    {
        if (--*use == 0)
        {
            delete p;
            delete use;
        }
    }

    Sales_item& Sales_item::operator=(const Sales_item &orig)
    {
        ++(*orig.use);
        decr_use();
        p = orig.p;
        use = orig.use;
        return *this;
    }

    Sales_item::Sales_item(const Item_base& item) : p(item.clone()), use(new size_t(1))
    {
    }
}
