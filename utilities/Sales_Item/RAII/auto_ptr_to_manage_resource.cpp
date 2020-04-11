#include "auto_ptr_to_manage_resource.h"

#include <memory>
#include <string>
#include <iostream>

using namespace std;

void access_auto_ptr_object(void)
{
    auto_ptr<string> dinosaur(new string("Brontosaurus"));
    /* normal pointer operations for dereference and arrow */
    string brontosaurus = *dinosaur;  /* initialize real_name as a copy of the object to which pname points */
    if (dinosaur->empty())
    {
        cout << "This string object is empty." << endl;
    }

    auto_ptr<string> ptr_dinosaur(new string("Stegosaurus"));
    /* after the copy, ptr_dinosaur is unbound */
    auto_ptr<string> ptr_dragon(ptr_dinosaur);  /* ownership transferred from ptr_dinosaur to ptr_dragon */
    auto_ptr<string> fly_dinosaur(new string("Pterodactyl"));
    /* object pointed to by fly_dinosaur is deleted, and ownership transferred from ptr_dragon to fly_dinosaur */
    fly_dinosaur = ptr_dragon;      /* after the assignment, ptr_dragon is unbound */

    if (ptr_dragon.get() == 0)
    {
        ptr_dragon.reset(new string("Dinosaur"));
    }
}
