#include "testing.h"
#include "zoo.h"


void instantiate_virtual_inheritance_objects(void)
{
    Bear winnie("ppoh");        /* Bear constructor initializes ZooAnimal */
    Raccoon meeko("meeko");     /* Raccoon constructor initializes ZooAnimal */
    Panda yolo("yolo");         /* Panda constructor initializes ZooAnimal */
}
