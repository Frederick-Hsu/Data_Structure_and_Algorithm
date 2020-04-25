#ifndef QUEUE_ITEM_H
#define QUEUE_ITEM_H

    #include "CachedObj.h"

    #include <iostream>
    using namespace std;

    template<class Type> class QueueItem;
    template<class Type> class Queue;

    template<class Type> ostream& operator<<(ostream& out, const Queue<Type>& queue);
    template<class Type> istream& operator>>(istream& in,        Queue<Type>& queue);

    template<class Type>
    class QueueItem : public CachedObj< QueueItem<Type> >
    {
        friend class Queue<Type>;
        friend ostream& operator<< <Type>(ostream& out, const Queue<Type>& queue);
        friend istream& operator>> <Type>(istream& in,        Queue<Type>& queue);
    private:
        QueueItem(const Type& t);
        ~QueueItem();
    private:
        Type item;
        QueueItem *next;
    };

    template<class Type> QueueItem<Type>::QueueItem(const Type& t) : item(t), next(0)
    {
    }

    template<class Type> QueueItem<Type>::~QueueItem<Type>()
    {
    }

#endif  /* QUEUE_ITEM_H */
