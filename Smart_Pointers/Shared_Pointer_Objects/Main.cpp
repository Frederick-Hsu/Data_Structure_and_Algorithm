/**************************************************************************************************
 * Project      : Shared_Pointer_Objects
 * Description  : This project will discuss how the shared_ptr<Type> works.
 * ================================================================================================
 * File name    : Main.cpp
 * Description  : This file will implement the main(0 entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Wed.  06 Nov. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>
#include <memory>
using namespace std;

#include "Shared_Ptr.h"

#if 0
    int main(int argc, char* argv[])
    {
        /* Creating a shared_ptr<> through make_shared<> */
        std::shared_ptr<int> p1 = std::make_shared<int>();
        Shared_Ptr<int> alice_shared_ptr(new int(5));
        Shared_Ptr<int> bob_shared_ptr = alice_shared_ptr;

        *p1 = 78;
        cout << "p1 = " << *p1 << endl;

        /* Show the reference count */
        cout << "p1's reference count = " << p1.use_count() << endl;

        /* Second shared_ptr<> object will also point to the same pointer internally
         * It will make the reference count to 2
         */
        std::shared_ptr<int> p2(p1);
        /* Shows the reference count */
        cout << "p2's reference count = " << p2.use_count() << endl;
        cout << "p1's reference count = " << p1.use_count() << endl;

        /* Compare between smart pointers */
        if (p1 == p2)
        {
            cout << "p1 and p2 are pointing to the same pointer\n";
        }
        cout << "Reset p1" << endl;
        p1.reset();
        /* Reset the shared_ptr, in this case it will not point to any Pointer internally.
         * Hency its reference count will become to 0.
         */
        cout << "p1's reference count = " << p1.use_count() << endl;

        /* Reset the shared_ptr, in this case it will point to a new Pointer internally,
         * Hency, its reference count will become to 1.
         */
        p1.reset(new int(10));
        cout << "p1's reference count = " << p1.use_count() << endl;

        /* Assigning nullptr will de-attach the associated pointer and make it to point to NULL */
        p1 = nullptr;
        cout << "p1's reference count = " << p1.use_count() << endl;
        if (!p1)
        {
            cout << "p1 is NULL" << endl;
        }

        return 0;
    }
#else
    struct Sample
    {
        Sample()
        {
            cout << "Sample::Sample() constructor" << endl;
        }
        ~Sample()
        {
            cout << "Sample::~Sample() Destructor" << endl;
        }
    };

    void deleter(Sample* x)
    {
        cout << "Deleter function called." << endl;
        delete[] x;
    }

    int main(int argc, char* argv[])
    {
        std::shared_ptr<Sample> threePoints(new Sample[3], deleter);
        return 0;
    }
#endif