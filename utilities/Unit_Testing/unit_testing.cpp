#include "unit_testing.h"
#include "../Sales_Item/Sales_item.h"
#include "../Sales_Item/Screen.h"

#include <fstream>
#include <vector>

void execute_test_cases(void)
{
    // instantiateObjects();
    // callConstructor();
    freeObjects();
}

#include <iostream>
using namespace std;

void instantiateObjects()
{
    cout << "sizeof(string) = " << sizeof(string("")) << "bytes" << endl;
    cout << "sizeof(unsigned) = " << sizeof(unsigned) << "bytes" << endl;
    cout << "sizeof(double) = " << sizeof(double) << "bytes" << endl;
    cout << "sizeof(void*) = " << sizeof(void*) << "bytes" << endl;
    cout << "sizeof(Sales_item*) = " << sizeof(Sales_item*) << "bytes" << endl;
    Sales_item item;    /* Never use item() to call the default constructor */
    cout << "The size of object item: " << sizeof(Sales_item) << "bytes" << endl;
}

void const_overload()
{
    Screen myScreen(5, 3);
    const Screen blank(5, 3);
    /* called non-const version of "Screen& display(ostream& os)" */
    myScreen.set('#').display(cout);
    /* called const version of "const Screen& display(ostream& os) const" */
    blank.display(cout);
}

void callConstructor()
{
    Sales_item empty = Sales_item();
    Sales_item Primer_3rd_Ed("0-201-82470-1");
    // Sales_item Primer_4th_ed(cin);
    Sales_item Primer_2nd_ed("0-201-54848-8");

    string null_book = "9-999-99999-9";
    Primer_2nd_ed.same_isbn(Sales_item(null_book));
    Sales_item* pItem = new Sales_item("978-7-5612-1135-9");
    pItem->same_isbn(Sales_item(cin));
    delete pItem;
}

void copyControl()
{
#if 0
    std::ifstream file1("filename");    /* OK: direct initialization */
    std::ifstream file2 = "filename";   /* Error: copy constructor is private */
#endif
    /* The below initialization is okay only if the
     * Sales_item(const string&) constructor is not explicit
     *
    Sales_item item = string("978-7-5123-4477-8");
     */
    Sales_item item = Sales_item(string("978-7-5123-4477-8"));
    Sales_item primer_eds[] = { Sales_item(string("978-7-302-37688-2")),
                                Sales_item(string("978-7-121-28108-2")),
                                Sales_item(string("978-7-03-019483-1")),
                                Sales_item() };
}

void freeObjects()
{
    Sales_item* pItem = new Sales_item();
    {
        Sales_item item(*pItem);
        delete pItem;
    }

    Sales_item *p = new Sales_item[10];      /* dynamically allocated */
    vector<Sales_item> vec(p, p+10);        /* local object */

    delete [] p;
}
