#ifndef SALES_ITEM_H
#define SALES_ITEM_H

    #include <string>
    #include <iostream>

    using namespace std;

namespace CPlusPlus_Primer
{
    class Sales_item;

    class Sales_item
    {
        friend istream& operator>>(istream& in, Sales_item& item);
        friend ostream& operator<<(ostream& out, const Sales_item& item);
        friend bool operator==(const Sales_item& lhs, const Sales_item& rhs);
    public:
        Sales_item();
        explicit Sales_item(const string& book);
        Sales_item(const string& book, int cnt, double price);
        explicit Sales_item(istream& in);
        Sales_item(const Sales_item& orig);    /* copy constructor */
        Sales_item& operator=(const Sales_item& other);     /* assign constructor */
        Sales_item& operator=(const string& isbn);
        virtual ~Sales_item();
    public:
        Sales_item& operator+=(const Sales_item& item);
        bool same_isbn(const Sales_item& other) const;
        inline double avg_price() const;
        string book() const;
    private:
        string isbn;
        unsigned units_sold;
        double revenue;
    };

    Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs);
    bool operator!=(const Sales_item& lhs, const Sales_item& rhs);
}

#endif  /* SALES_ITEM_H */
