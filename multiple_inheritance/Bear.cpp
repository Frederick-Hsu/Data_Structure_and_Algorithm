#include "Bear.h"

Bear::Bear(std::string& name, bool isExisted, const std::string& animal_name) : ZooAnimal()
{
    this->name = name;
    bear_is_existed = isExisted;
    this->animal_name = animal_name;
}

Bear::Bear() : ZooAnimal(),
    name(""), bear_is_existed(false), animal_name("")
{
}