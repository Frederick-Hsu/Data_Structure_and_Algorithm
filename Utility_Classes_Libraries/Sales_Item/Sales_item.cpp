#include "Sales_item.h"
#include "exceptions.h"
#include <cmath>

namespace CPlusPlus_Primer
{
    string make_plural(size_t number, const string& word, const string& ending)
    /* copy constructor used to copy the return value;
     * parameters are references, so they aren't copied.
     */
    {
        if (number > 1)
            return (word + ending);
        else
        {
            /* here called the "string::string(const string& orig)" copy constructor */
            return word;
        }
    }

    bool Sales_item::same_isbn(const Sales_item &other) const
    {
        return (isbn == other.isbn);
    }

    double Sales_item::avg_price() const
    {
        if (units_sold)
            return (revenue/units_sold);
        else
            return 0;
    }

    #if 1
    Sales_item::Sales_item() : units_sold(0), revenue(0.00)
    #else
    Sales_item::Sales_item() : isbn(10, '9'), units_sold(0), revenue(0.00)
    #endif
    {
    }

    Sales_item::~Sales_item()
    {
    #if defined (NDEBUG)
        cout << "called Sales_item::~Sales_item() destructor." << endl;
    #endif
    }

    Sales_item::Sales_item(const string& book) : isbn(book), units_sold(0), revenue(0.0)
    {
    }

    Sales_item::Sales_item(istream& in)
    {
        in >> *this;
    }

    Sales_item::Sales_item(const Sales_item& orig) : isbn(orig.isbn),
                                                     units_sold(orig.units_sold),
                                                     revenue(orig.revenue)
    {
    }

    Sales_item::Sales_item(const string& book, int cnt, double price) :
        isbn(book), units_sold(static_cast<unsigned>(cnt)), revenue(cnt * price)
    {
    }

    Sales_item& Sales_item::operator=(const Sales_item &other)
    {
        isbn = other.isbn;
        units_sold = other.units_sold;
        revenue = other.revenue;
        return *this;
    }

    Sales_item& Sales_item::operator=(const string &isbn)
    {
        this->isbn = isbn;
        units_sold = 0;
        revenue = 0.00;
        return *this;
    }

    ostream& operator<<(ostream& out, const Sales_item& item)
    {
        out << item.isbn << "\t" << item.units_sold << "\t"
            << item.revenue << "\t" << item.avg_price();
        return out;
    }

    istream& operator>>(istream& in, Sales_item& item)
    {
        double price;
        cout << "Enter the ISBN: ";
        in >> item.isbn;

        cout << "how many units sold: ";
        in >> item.units_sold;

        cout << "and the unit price: ";
        in >> price;
        /* check that the inputs succeeded */
        if (in)
            item.revenue = item.units_sold * price;
        else
        {
            item = Sales_item();    /* input failed: reset object to default state */
        }
        return in;
    }

    Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
    /* assume that both objects refer to the same isbn. */
    {
        if (!lhs.same_isbn(rhs))
        {
            #if 1
            /* throws exception if both objects do not refer to the same ISBN */
            throw runtime_error("Data must refer to the same ISBN.");
            #else
            throw isbn_mismatch("isbn mismatch", lhs.book(), rhs.book());
            #endif
        }
        Sales_item item(lhs);   /* copy lhs into a local object that we'll return */
        item += rhs;            /* add in the contents of rhs */
        return item;
    }

    Sales_item& Sales_item::operator+=(const Sales_item &item)
    {
        if (same_isbn(item))
        {
            isbn = item.isbn;
            units_sold += item.units_sold;
            revenue += item.revenue;
        }
        return *this;
    }

    string Sales_item::book() const
    {
        return  isbn;
    }

    inline bool operator==(const Sales_item& lhs, const Sales_item& rhs)
    {
        return ( (lhs.units_sold == rhs.units_sold) &&
                 (fabs(lhs.revenue - rhs.revenue) <= 0.005) &&
                 lhs.same_isbn(rhs) );
    }

    inline bool operator!=(const Sales_item& lhs, const Sales_item& rhs)
    {
        return !(lhs == rhs);
    }
}
