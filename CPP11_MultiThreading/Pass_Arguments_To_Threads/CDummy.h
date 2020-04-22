#ifndef CDUMMY_H
#define CDUMMY_H

    class CDummy
    {
    public:
        CDummy();
        CDummy(const CDummy& orig);
        ~CDummy();
        void work(int x);
    };

#endif  /* CDUMMY_H */
