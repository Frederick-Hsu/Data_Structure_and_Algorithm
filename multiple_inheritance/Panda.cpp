#include "Panda.h"

/* explicitly initialize both base classes */
Panda::Panda(std::string name, bool onExhibit) : Bear(name, onExhibit, "Panda"), 
                                                 Endangered(Endangered::Critical)
{
}

/* implicitly use Bear default constructor to initialize the Bear subobject */
Panda::Panda() : Endangered(Endangered::Critical)
{
}