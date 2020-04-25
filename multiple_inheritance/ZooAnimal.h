#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H

    #include <iostream>

    class ZooAnimal
    {
    public:
        ZooAnimal();
        virtual ~ZooAnimal();
    public:
        void print(std::ostream& out);
    };

#endif  /* ZOO_ANIMAL_H */