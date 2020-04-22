#include "function_throw_exception.h"

#include <iostream>
#include <memory>
#include <vector>

double Base::f1(double val) throw()
{
    return val;
}

int Base::f2(int val) throw (logic_error)
{
    return val;
}

string Base::f3() throw (logic_error, runtime_error)
{
    return string("may throw logic_error or runtime_error");
}

string Derived::f3() throw()
{
    string error = "";
    try
    {
        error = "current exception: ";
        return error;
    }
    catch (logic_error& lerr)
    {
        cout << lerr.what() << endl;
    }
    catch (runtime_error& rerr)
    {
        cout << rerr.what() << endl;
    }
}

void compute(Base *pb) throw()  /* guarantees not to throw exceptions */
{
    try
    {
        /* may throw exception of type logic_error or runtime_error */
        pb->f3();
    }
    catch (logic_error& lerr)
    {
        cout << lerr.what() << endl;
    }
    catch (const runtime_error& rerr)
    {
        cout << rerr.what() << endl;
    }
}

template<unsigned capacity = 10>
void factorial(vector<size_t>& fact)
{
    fact.push_back(0);      /* Assume 0! = 0 */
    fact.push_back(1);      /* 1!= 1 */
    fact.push_back(2);      /* 2! = 2 * 1 */
                            /* 3! = 3 * 2! */
    for (unsigned index = 3; index <= capacity; ++index)
    {
        fact.push_back(index * fact[index-1]);      /* n! = n * (n-1)! */
    }
}
void recoup(int a) throw (runtime_error)
{
    auto_ptr<int> ap(new int(a));
    try
    {
        vector<size_t> factor;
        factorial<18>(factor);
        if (*ap > 18)
        {
            throw runtime_error("the index of factorial exceeds the max range.");
        }
        cout << "The factorial(" << a << ") = " << factor[static_cast<size_t>(*ap)] << endl;
    }
    catch (runtime_error& rerr)
    {
        cout << "One exception: \"" << rerr.what() << "\" raised." << endl;
    }
}


void (*pf2)(int) throw (runtime_error, logic_error) = recoup;   /* OK: recoup is more restrictive than pf2 */
// void (*pf3)(int) throw() = recoup;      /* Error: recoup is less restrictive than pf3 */
void (*pf4)(int) = recoup;      /* OK: recoup is more restrictive than pf4 */
