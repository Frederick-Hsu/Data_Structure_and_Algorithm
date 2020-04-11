#include "misc.h"

Record::Record() : byte_count(0)
{
}

Record::Record(Record::size s) : byte_count(s)
{
}

Record::Record(std::string s) : byte_count(0), name(s)
{
}

Record::size Record::get_count() const
{
    return byte_count;
}

std::string Record::get_name() const
{
    return name;
}

/*============================================================================================*/

/* constructor for 'ConstRef' must explicitly
 * intialize the const member 'constNum'.
 */
ConstRef::ConstRef(int num) : number(num), constNum(num), refNum(num)
{
#if false
    number = num;
    /* cannot assign to non-static data member 'constNum' with
     * const-qualified type 'const int'.
     */
    constNum = num;
    refNum = num;
#endif
}

/*============================================================================================*/

double Account::interestRate = initialRate();

void Account::applyInterest()
{
    amount += amount * interestRate;
}

double Account::rate()
{
    return interestRate;
}

void Account::rate(double newRate)
{
    interestRate = newRate;
}

/*============================================================================================*/

NoName::NoName() : pstring(new std::string), i(0), d(0.00)
{
}

NoName::~NoName()
{
    pstring->clear();
    delete pstring;
}

NoName::NoName(const NoName& orig) : i(orig.i), d(orig.d)
{
    std::string str = std::string(orig.pstring->data());
    pstring = new std::string(str);
}

/*============================================================================================*/

int& Foo::operator[](const std::size_t index)
{
    return data[index];
}

const int& Foo::operator[](const std::size_t index) const
{
    return data[index];
}
