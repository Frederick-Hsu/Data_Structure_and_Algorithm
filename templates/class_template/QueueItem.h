#ifndef QUEUE_ITEM_H
#define QUEUE_ITEM_H

    #include <iostream>

    /* declaration that Queue is a template needed for friend declaration in QueueItem */
    template<class Type> class Queue;
    template<class Type> class QueueItem;

    /* function template declaration must precede friend declaration in QueueItem */
    template<class Type> std::ostream& operator<<(std::ostream& os, const Queue<Type>& queue);
    template<class Type> std::istream& operator>>(std::istream& is,       Queue<Type>& queue);

/*================================================================================================*/

    template<class Type>
    class QueueItem
    {
        friend class Queue<Type>;
        /* needs access to item and next */
        friend std::ostream& operator<< <Type>(std::ostream& os, const Queue<Type>& queue);
        friend std::istream& operator>> <Type>(std::istream& is,       Queue<Type>& queue);
    private:    /* private class, no public section */
        QueueItem(const Type& t);
    private:
        Type item;          /* value stored in this element */
        QueueItem *next;    /* pointer to next element in the Queue */
    };

/*================================================================================================*/

    template<class Type> QueueItem<Type>::QueueItem(const Type& t) : item(t), next(0)
    {
    }


#endif  /* QUEUE_ITEM_H */
