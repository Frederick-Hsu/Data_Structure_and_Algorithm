#include "Auto_Ptr.h"

#include <memory>
#include <string>
#include <iostream>
using namespace std;

void safely_allocate_memory()
{
    auto_ptr<int> pi(new int(42));      /* allocate a new object */
    /* code that throws an exception that is not caught inside this current function,
     * auto_ptr freed automatically when function ends.
     */
    auto_ptr<string> ap(new string("Brontosaurus"));
    /* normal pointer operations for dereference and arrow */
    *ap = "TRex";       /* assign a new value too the object to which ap points */
    string s = *ap;     /* initialize s as a copy of the object to which ap points */
    if (ap->empty())    /* runs empty on the string to which ap points */
    {
        /* do something */
    }

    auto_ptr<string> dinosaur(new string("Stegosaurus"));
    auto_ptr<string> dragon(dinosaur);     /* ownership transferred from dinosaur to dragon */

    /* Error: Because the dinosaur object has transferred the ownership,
     *        dinosaur does not bind the pointer of string("Stegosaurus") object.
     *        Quite reversely, dragon was assigned to the pointer to string("Stegosaurus") object.
     *
    cout << "The origin object of dinosaur is: " << *dinosaur << endl;
     */
    cout << "The copied object of dinosaur, exactly dragon = " << *dragon << endl;

    auto_ptr<string> pterodactyl(new string("Pterodactyl"));
    /* object pointed to by pterodactyl is deleted and ownership transferred
     * from dragon to pterodactyl.
     */
    pterodactyl = dragon;       /* after assignment, dragon is unbound */
    cout << "The assigned object is: " << *pterodactyl << endl;
    // cout << "The original object is: " << *dragon << endl;       /* dragon no longer existed */
}

void test_auto_ptr_object()
{
    auto_ptr<int> p_auto;   /* p_auto doesn't refer to any object */
    // *p_auto = 1024;     /* Error: dereference auto_ptr that doesn't point to an object. */
#if 0
    if (p_auto)     /* Error: cannot use an auto_ptr as a condition */
#else
    if (p_auto.get() == 0)   /* revised test to guarantee p_auto refers to an object */
#endif
    {
        // p_auto = new int(256);   /* Error: cannot assign a pointer to an auto_ptr */
        p_auto.reset(new int(256)); /*        reset p_auto to a new object */
        cout << "Now the p_auto points to the value: " << *p_auto << endl;
    }
}
