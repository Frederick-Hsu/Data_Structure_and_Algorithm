#include <iostream>
#include "chain.h"
#include "Foo.h"

using namespace std;

void execute_test_items(void);

int main()
{
    cout << "C++ standard no.: " << __cplusplus << endl;

    execute_test_items();
    return 0;
}

void execute_test_items(void)
{
    validate_how_vptr_vtbl_work();

#if !defined (TEST_PLACEMENT_NEW_THROW_EXCEPTION)
    cout << "\n" << endl;
    investigate_how_operator_new_delete_work();
#else
    cout << "\n" << endl;
    try
    {
        investigate_how_placement_new_work();
    }
    catch (bad_alloc& e)
    {
        cout << "The exception reason is: " << e.what() << endl;
    }

#endif
}
