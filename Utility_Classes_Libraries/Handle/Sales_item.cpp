#include "Sales_item.h"

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
