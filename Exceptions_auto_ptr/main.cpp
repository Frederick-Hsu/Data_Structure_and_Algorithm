#include "Auto_Ptr.h"
#include <iostream>
#include "function_throw_exception.h"

using namespace std;

void (*pf1)(int) throw (runtime_error) = recoup;    /* OK: recoup is as restrictive as pf1 */

int main()
{
    safely_allocate_memory();
    test_auto_ptr_object();

    pf1(15);
    getchar();
    return 0;
}
