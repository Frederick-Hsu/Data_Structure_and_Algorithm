#ifndef PANDA_H
#define PANDA_H

    #include "Bear.h"
    #include "Endangered.h"

    class Panda : public Bear, public Endangered
    {
    public:
        Panda(std::string name, bool onExhibit = true);
        Panda();
        virtual ~Panda();
    public:
        void print(std::ostream& out);
        void highlight();
        void toes();
        void cuddle();
    };

#endif  /* PANDA_H */