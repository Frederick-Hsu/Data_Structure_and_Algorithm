#include "zoo.h"

ZooAnimal::ZooAnimal(string name, bool onExhibit, string category) : animal_name(name),
    animal_is_on_exhibit(onExhibit), animal_category(category)
{
}

Bear::Bear(string name, bool onExhibit) : ZooAnimal(name, onExhibit, "Bear")
{
}

Raccoon::Raccoon(string name, bool onExhibit) : ZooAnimal(name, onExhibit, "Raccoon")
{
}

Endangered::Endangered(EXTENT_t ext) : extent(ext)
{
}

Panda::Panda(string name, bool onExhibit) : ZooAnimal(name, onExhibit, "Panda"),
                                            Bear(name, onExhibit),
                                            Raccoon(name, onExhibit),
                                            Endangered(Endangered::Critical),
                                            sleeping_flag(false)
{
}
