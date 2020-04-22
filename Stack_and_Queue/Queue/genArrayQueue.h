/**************************************************************************************************
 * File name    : genArrayQueue.h
 * Description  : generic queue implemented as an array.
 * Creator      : Frederick Hsu
 * Creation date: Sat.  12 Oct. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#ifndef GEN_ARRAY_QUEUE_H
#define GEN_ARRAY_QUEUE_H

    #include <iostream>
    using namespace std;

    template<typename Type, int size = 10>
    class ArrayQueue
    {
    public:
        ArrayQueue();
        void enqueue(Type element);
        Type dequeue();
        bool isFull();
        bool isEmpty();
    private:
        int first;
        int last;
        Type storage[size];
    };

    /*=============================================================================================*/

    template<typename Type, int size> ArrayQueue<Type, size>::ArrayQueue()
    {
        first = last = -1;
    }

    template<typename Type, int size> void ArrayQueue<Type, size>::enqueue(Type element)
    {
        if (!isFull())
        {
            if ((first == size-1) || (last == -1))
            {
                storage[0] = element;
                last = 0;
                if (first == -1)
                {
                    first = 0;
                }
            }
            else
            {
                storage[++last] = element;
            }
        }
        else
        {
            cout << "Full queue." << endl;
        }
    }

    template<typename Type, int size> Type ArrayQueue<Type, size>::dequeue()
    {
        Type tmp = storage[first];
        if (first == last)
        {
            last = first = -1;
        }
        else if (first == size-1)
        {
            first = 0;
        }
        else
        {
            first++;
        }
        return tmp;
    }

    template<typename Type, int size> bool ArrayQueue<Type, size>::isFull()
    {
        return ((first == 0) && (last == size-1) || (first == last+1));
    }

    template<typename Type, int size> bool ArrayQueue<Type, size>::isEmpty()
    {
        return (first == -1);
    }

#endif  /* GEN_ARRAY_QUEUE_H */
