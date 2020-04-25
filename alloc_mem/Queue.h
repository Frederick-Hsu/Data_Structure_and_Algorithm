#ifndef QUEUE_H
#define QUEUE_H

    #include "QueueItem.h"

    template<class Type> class Queue;

    template<class Type> class Queue
    {
        friend ostream& operator<< <Type>(ostream& out, const Queue<Type>& queue);
        friend istream& operator>> <Type>(istream& in,        Queue<Type>& queue);
    public:
        Queue();
        Queue(const Queue& other);
        Queue& operator=(const Queue& other);
        ~Queue();
    public:
        Type& front();
        const Type& front() const;
        void push(const Type& element);
        void pop();
        bool isEmpty() const;
    private:
        QueueItem<Type> *head;
        QueueItem<Type> *tail;
    private:
        void destroy();
        void copy_elements(const Queue& other);
    };

/*================================================================================================*/

    template<class Type> Queue<Type>::Queue() : head(0), tail(0)
    {
    }

    template<class Type> Queue<Type>::Queue(const Queue& other) : head(0), tail(0)
    {
        copy_elements(other);
    }

    template<class Type> Queue<Type>& Queue<Type>::operator=(const Queue& other)
    {
        destroy();
        QueueItem<Type> *pnode = other.head;
        while (pnode != 0)
        {
            push(pnode->item);
            pnode = pnode->next;
        }
        return *this;
    }

    template<class Type> Queue<Type>::~Queue()
    {
        destroy();
    }

    template<class Type> void Queue<Type>::destroy()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    template<class Type> void Queue<Type>::push(const Type& element)
    {
        QueueItem<Type> *pnode = new QueueItem<Type>(element);
        if (isEmpty())
        {
            head = tail = pnode;
        }
        else
        {
            tail->next = pnode;
            tail = pnode;
        }
    }

    template<class Type> void Queue<Type>::pop()
    {
        QueueItem<Type> *pnode = head;
        head = head->next;
        delete pnode;
    }

    template<class Type> bool Queue<Type>::isEmpty() const
    {
        return (head == 0);
    }

    template<class Type> void Queue<Type>::copy_elements(const Queue& other)
    {
        for (QueueItem<Type> *pnode = other.head; pnode == 0; pnode = pnode->next)
        {
            push(pnode->item);
        }
    }

    template<class Type> Type& Queue<Type>::front()
    {
        return head->item;
    }

    template<class Type> const Type& Queue<Type>::front() const
    {
        return head->item;
    }

    template<class Type> ostream& operator<<(ostream& out, const Queue<Type>& queue)
    {
        out << "[head-> ";
        QueueItem<Type> *pnode = queue.head;
        do
        {
            out << pnode->item << " ";
            pnode = pnode->next;
        }
        while (pnode != 0);
        out << "<-tail]";
        return out;
    }

    template<class Type> istream& operator>>(istream& in, Queue<Type>& queue)
    {
        Type element;
        while (in >> element)
        {
            queue.push(element);
        }
        return in;
    }

#endif  /* QUEUE_H */
