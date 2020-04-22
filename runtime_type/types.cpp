#include "types.h"

#include <typeinfo>
#include <iostream>
using namespace std;

Base::Base()
{
}

Base::~Base()
{
}

Derived::Derived() : Base()
{
}

Derived::~Derived()
{
}

bool Base::equal(const Base &rhs) const
{
    return (typeid(*this) == typeid(rhs));
}

bool Derived::equal(const Base &rhs) const
{
    if (const Derived *dptr = dynamic_cast<const Derived *>(&rhs))
    {
        return (typeid(*this) == typeid(*dptr));
    }
    else
    {
        return false;
    }
}

bool operator==(const Base& lhs, const Base& rhs)
{
    return ((typeid(lhs) == typeid(rhs)) && (lhs.equal(rhs)));
}

void display_type_name(void)
{
    int num_obj = 100;
    cout << "Display the type_name of class or object: " << endl;
    cout << typeid(num_obj).name() << endl
         << typeid(8.16).name() << endl
         << typeid(std::string).name() << endl
         << typeid(Base).name() << endl
         << typeid(Derived).name() << endl;
    
    cout << "Display the size of class or object: " << endl;
    cout << sizeof(Base) << endl
         << sizeof(Derived) << endl
         << sizeof(std::string) << endl
         << sizeof(bool) << endl;
}
