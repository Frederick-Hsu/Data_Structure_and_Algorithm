#ifndef ENDANGERED_H
#define ENDANGERED_H

    #include <iostream>

    class Endangered
    {
    public:
        typedef enum EXTENT
        {
            Critical,
            Normal
        } EXTENT;
    public:
        Endangered(EXTENT ext);
        virtual ~Endangered();
    public:
        void print(std::ostream& out);
        void highlight();
    private:
        EXTENT ext;
    };

#endif  /* ENDANGERED_H */