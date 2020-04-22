#include "Item_base.h"
#include <cmath>

Item_base::Item_base(const string& book, double sales_price) : isbn(book), price(sales_price)
{
}

Item_base::Item_base(const Item_base& orig) : isbn(orig.isbn), price(orig.price)
{
}

Item_base& Item_base::operator=(const Item_base &orig)
{
    if (this != &orig)
    {
        isbn = orig.isbn;
        price = orig.price;
    }
    return *this;
}

string Item_base::book() const
{
    return isbn;
}

Item_base* Item_base::clone() const
{
    return (new Item_base(*this));
}

double Item_base::net_price(size_t n) const
{
    return (n * price);
}

Item_base::~Item_base()
{
#ifdef NDEBUG
    cout << "Item_base::~Item_base() called." << endl;
#endif
}

bool operator<(const Item_base& item_a, const Item_base& item_b)
{
    if (item_a.isbn == item_b.isbn)
    {
        return (fabs(item_a.price - item_b.price) < 0.01);
    }
    else
    {
        return (item_a.isbn < item_b.isbn);
    }
}
