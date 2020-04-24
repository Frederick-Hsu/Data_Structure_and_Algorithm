#include "Foo.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

Foo::Foo() : id(0)
{
    cout << "default ctor.this = " << this << ", id = " << id << endl;
}

Foo::Foo(int i) : id(i)
{
    cout << "ctor.this = " << this << ", id = " << id << endl;
#if defined (TEST_PLACEMENT_NEW_THROW_EXCEPTION)
    throw bad_alloc();
#endif
}

Foo::~Foo()
{
    cout << "dtor.this = " << this << ", id = " << id << endl;
}

void* Foo::operator new(size_t size)
{
    cout << "void* Foo::operator new(size_t size), sizeof(size) = " << size << endl;
    Foo* p = static_cast<Foo*>(malloc(size));
    cout << "p = " << p << endl;
    return p;
}

void Foo::operator delete(void* pdead, size_t size)
{
    cout << "pdead = " << pdead << endl
         << "void Foo::operator delete(void* p, size_t size), sizeof(size) = " << size << endl;
    free(pdead);
}

void* Foo::operator new[](size_t size)
{
    cout << "void* Foo::operator new[](size_t size), sizeof(size) = " << size << endl;
    Foo* p = static_cast<Foo*>(malloc(size));
    cout << "p = " << p << endl;
    return p;
}

void Foo::operator delete[](void* pdead, size_t size)
{
    cout << "pdead = " << pdead << endl
         << "void* Foo::operator delete[](void* p, size_t size), sizeof(size) = " << size << endl;
    free(pdead);
}

void* Foo::operator new(size_t, void* start)
{
    cout << "Foo::operator new(size_t, void*)" << endl;
    return start;
}

void Foo::operator delete(void*, void*)
{
    cout << "Foo::operator delete(void*, void*)" << endl;
}

void* Foo::operator new(size_t size, long extra)
{
    cout << "Foo::operator new(size_t, long)" << endl;
    return static_cast<Foo*>(malloc(size + static_cast<size_t>(extra)));
}

void Foo::operator delete(void*, long)
{
    cout << "Foo::operator delete(void*, long)" << endl;
}

void* Foo::operator new(size_t size, long extra, char)
{
    cout << "Foo::operator new(size_t, long, char)" << endl;
    Foo* ptr = static_cast<Foo*>(malloc(size + static_cast<size_t>(extra)));
    return ptr;
}

void Foo::operator delete(void*, long, char)
{
    cout << "Foo::operator delete(void*, long, char)" << endl;
}

void investigate_how_operator_new_delete_work(void)
{
    cout << "sizeof(size_t) = " << sizeof(size_t) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(string) = " << sizeof(string) << endl;
    cout << "sizeof(void*) = " << sizeof(void*) << endl;
    cout << "sizeof(Foo) = " << sizeof(Foo) << endl;
    cout << "sizeof(Foo*) = " << sizeof(Foo*) << "\n" << endl;

#if 1
    Foo* ptr_obj = new Foo(7);
    cout << "sizeof(ptr_obj) = " << sizeof(ptr_obj) << endl;
    delete ptr_obj;

    cout << "\n" << endl;

    Foo* ptr_obj_array = new Foo[5];
    cout << "sizeof(ptr_obj_array) = " << sizeof(ptr_obj_array) << endl;
    delete[] ptr_obj_array;
#else
    Foo* ptr_obj = ::new Foo(7);
    ::delete ptr_obj;

    cout << "\n" << endl;

    Foo* ptr_obj_array = ::new Foo[5];
    ::delete[] ptr_obj_array;
#endif
}

void investigate_how_placement_new_work(void)
{
#if defined (TEST_PLACEMENT_NEW_THROW_EXCEPTION)
    Foo start;
    Foo *p1 = new Foo;
    Foo *p2 = new (&start) Foo;
    Foo *p3 = new (100) Foo;
    Foo *p4 = new (100, 'a') Foo;
    Foo *p5 = new (100) Foo(1);
    Foo *p6 = new (100, 'a') Foo(1);
    Foo *p7 = new (&start) Foo(1);
    Foo *p8 = new Foo(1);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
    delete p7;
    delete p8;
#endif
}
