#include "chain.h"

#include <iostream>
using namespace std;

A::A() : m_data1(0), m_data2(0)
{
    cout << "execute A::A() default constructor" << endl;
}

A::A(int m, int n) : m_data1(m), m_data2(n)
{
    cout << "execute A::A(m, n) constructor" << endl;
}

A::~A()
{
    cout << "execute A::~A() destructor" << endl;
}

B::B() : A(), m_data3(0)
{
    cout << "execute B::B() default constructor" << endl;
}

B::B(int m, int n, int u) : A(m, n), m_data3(u)
{
    cout << "execute B::B(m, n, u) constructor" << endl;
}

B::~B()
{
    cout << "execute B::~B() destructor" << endl;
}

C::C() : B(), m_data1(0), m_data4(0)
{
    cout << "execute C::C() default constructor" << endl;
}

C::C(int m, int n, int u, int x, int y) : B(m, n, u), m_data1(x), m_data4(y)
{
    cout << "execute C::C(m, n, u, x, y) constructor" << endl;
}

C::~C()
{
    cout << "execute C::~C() destructor" << endl;
}

void A::vfunc1()
{
    cout << "execute \"virtual A::vfunc1()\" method" << endl;
}

void A::vfunc2()
{
    cout << "execute \"virtual A::vfunc2()\" method" << endl;
}

void B::vfunc1()
{
    cout << "execute \"virtual B::vfunc1() override\" method" << endl;
}

void C::vfunc1()
{
    cout << "execute \"virtual C::vfunc1() override\" method" << endl;
}


void validate_how_vptr_vtbl_work(void)
{
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(void*) = " << sizeof(void*) << endl;
    cout << "sizeof(A) = " << sizeof(A) << endl;
    cout << "sizeof(B) = " << sizeof(B) << endl;
    cout << "sizeof(C) = " << sizeof(C) << endl;

    A* aobjptr = new A();
    cout << "\n" << endl;

    B* bobjptr = new B;
    cout << "\n" << endl;

    C* cobjptr = new C();
    cout << "\n" << endl;

    cout << "sizeof(aobj) = " << sizeof(*aobjptr) << endl;
    cout << "sizeof(aobjptr) = " << sizeof(aobjptr) << endl;
    cout << "aobjptr = " << aobjptr << "\n" << endl;

    cout << "sizeof(bobj) = " << sizeof(*bobjptr) << endl;
    cout << "sizeof(bobjptr) = " << sizeof(bobjptr) << endl;
    cout << "bobjptr = " << bobjptr << "\n" << endl;

    cout << "sizeof(cobj) = " << sizeof(*cobjptr) << endl;
    cout << "sizeof(cobjptr) = " << sizeof(cobjptr) << endl;
    cout << "cobjptr = " << cobjptr << "\n" << endl;
    cout << "\n" << endl;

    aobjptr->vfunc1();
    cout << endl;

    bobjptr->vfunc1();
    bobjptr->vfunc2();
    cout << endl;

    cobjptr->vfunc1();
    cobjptr->vfunc2();
    cout << "\n" << endl;

    delete cobjptr;
    cout << endl;

    delete bobjptr;
    cout << endl;

    delete aobjptr;
}
