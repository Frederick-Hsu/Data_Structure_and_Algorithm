#include "utilizing_handle.h"
#include "Handle.h"

#include <iostream>

void how_generic_handle_works(void)
{
    std::cout << "\n" << std::endl;
    std::cout << "Explore how the generic handle template class object works..." << std::endl;
    {
        /* user allocates but must not delete the object to which the Handle is attached */
        Handle<int> hp(new int(35));
        {   /* new scope */
            Handle<int> hndl_ptr = hp;      /* copies pointer; use-count incremented */
            std::cout << *hp << " " << *hndl_ptr << std::endl;

            *hndl_ptr = 50;     /* changes value of shared underlying int */
        }   /* hndl_ptr goes out of the scope; use-count is decremented */
        std::cout << *hp << std::endl;
    }
    /* hp goes out of scope; its destructor deletes the int */
}