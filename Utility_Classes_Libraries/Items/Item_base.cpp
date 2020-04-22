#include "Item_base.h"
#include <cmath>

namespace BookStore
{
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
    /* returns total sales price for a specified number of items,
     * derived classes will override and apply different discount algorithms.
     */
    {
        return (n * price);
    }

    Item_base::~Item_base()
    {
    #ifdef NDEBUG
        cout << "Item_base::~Item_base() called." << endl;
    #endif
    }

    void print_total(ostream& os, const Item_base& item, size_t n)
    /* calculate and print price for given number of copies, applying any discounts */
    {
        os << "ISBN: " << item.book() << "\tnumber sold: " << n
           << "\ttotal price: "
              /* virtual call: which version of net_price to call is resolved at run time. */
           << item.net_price(n)
           << endl;
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

    void get_price(Item_base object, const Item_base* pointer, const Item_base& reference)
    {
        /* which version of net_price is called is determined at run time. */
        cout << pointer->net_price(1) << endl;
        cout << reference.net_price(1) << endl;

        /* always invokes Item_base::net_price() version */
        cout << object.net_price(1) << endl;
    }
}
