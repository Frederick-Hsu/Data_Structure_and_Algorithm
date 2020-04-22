/**************************************************************************************************
 * File name    : genQueue.h
 * Description  : generic queue implemented with doubly linked list.
 * Creator      : Frederick Hsu
 * Creation date: Sat.  12 Oct. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#ifndef GEN_QUEUE_H
#define GEN_QUEUE_H

    #include <list>
    using std::list;

    template<class Type>
    class Queue
    {
    public:
        Queue();
        void clear();
        bool isEmpty() const;
        Type& front();
        Type dequeue();
        void enqueue(const Type& element);
    private:
        list<Type> lst;
    };

    /*=============================================================================================*/

    template<class Type> Queue<Type>::Queue()
    {
    }

    template<class Type> void Queue<Type>::clear()
    {
        lst.clear();
    }

    template<class Type> bool Queue<Type>::isEmpty() const
    {
        return lst.empty();
    }

    template<class Type> Type& Queue<Type>::front()
    {
        return lst.front();
    }

    template<class Type> Type Queue<Type>::dequeue()
    {
        Type element = lst.front();
        lst.pop_front();
        return element;
    }

    template<class Type> void Queue<Type>::enqueue(const Type& element)
    {
        lst.push_back(element);
    }

#endif  /* GEN_QUEUE_H */
