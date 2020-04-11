#ifndef ZOO_H
#define ZOO_H

    #include <string>
    using namespace std;

    namespace CPP_Primer
    {
        class ZoonAnimal;
        class Bear;
        class Raccoon;
        class Endangered;
        class Panda;
        class ToyAnimal;
        class TeddyBear;
        class Character;
        class BookCharacter;
    }

    class ZooAnimal     /* virtual base class */
    {
    public:
        ZooAnimal(string name, bool onExhibit, string category);
    private:
        string animal_name;
        bool animal_is_on_exhibit;
        string animal_category;
    };

    class Bear : virtual public ZooAnimal       /* virtual inheritance */
    {
    public:
        Bear(string name, bool onExhibit = false);
    private:
    };

    class Raccoon : public virtual ZooAnimal
    {
    public:
        Raccoon(string name, bool onExhibit = false);
    private:
    };

    class Endangered
    {
    public:
        typedef enum EXTENT
        {
            Critical,
            Normal
        } EXTENT_t;
        Endangered(EXTENT_t ext);
    private:
        EXTENT_t extent;
    };

    class Panda : public Bear, public Raccoon, public Endangered    /* concrete derived class */
    {
    public:
        Panda(string name, bool onExhibit = true);
    private:
        bool sleeping_flag;
    };

    class Character
    {
    public:
    };

    class BookCharacter : public Character
    {
    public:
    };

    class ToyAnimal
    {
    public:
    };

    class TeddyBear : public BookCharacter, public Bear, virtual public ToyAnimal
    {
    public:
    };

#endif  /* ZOO_H */
