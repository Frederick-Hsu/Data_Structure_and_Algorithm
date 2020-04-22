#ifndef BEAR_H
#define BEAR_H

    #include "ZooAnimal.h"
    #include <string>

    class Bear : public ZooAnimal
    {
    public:
        Bear();
        Bear(std::string& name, bool isExisted = true, const std::string& animal_name = "Bear");
        virtual ~Bear();
    public:
        void print(std::ostream& out);
        void toes();
    private:
        std::string name;
        bool bear_is_existed;
        std::string animal_name;
    };

#endif  /* BEAR_H */