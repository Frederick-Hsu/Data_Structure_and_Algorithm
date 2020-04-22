#ifndef QUEUE_H
#define QUEUE_H

    #include <iostream>

    #define DEFINE_NESTED_CLASS_INNER   1
    #define DEFINE_NESTED_CLASS_OUTER   2
    #define NESTED_CLASS_DEFINITION     DEFINE_NESTED_CLASS_INNER

    template<class Type> class Queue;

#if (NESTED_CLASS_DEFINITION == DEFINE_NESTED_CLASS_INNER)
    template<class Type> class Queue
    {
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
        struct QueueItem
        {
            QueueItem(const Type& t);
            Type item;
            QueueItem *next;
            static int static_mem;
        };
    private:
        QueueItem *head;
        QueueItem *tail;
    private:
        void destroy();
        void copy_elements(const Queue& other);
    };

    template<class Type> Queue<Type>::QueueItem::QueueItem(const Type& t) : item(t), next(0)
    {
    }

    template<class Type> int Queue<Type>::QueueItem::static_mem = 1024;
#elif (NESTED_CLASS_DEFINITION == DEFINE_NESTED_CLASS_OUTER)
    template<class Type> class Queue
    {
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
        struct QueueItem;   /* forward declaration of nested type QueueItem */
        QueueItem *head;
        QueueItem* tail;
    private:
        void destroy();
        void copy_elements(const Queue& other);
    };

    template<class Type> struct Queue<Type>::QueueItem
    {
        QueueItem(const Type& t) : item(t), next(0) {}
        Type item;
        QueueItem *next;
        static int static_mem;
    };

    template<class Type> int Queue<Type>::QueueItem::static_mem = 1024;
#endif

    template<class Type> void Queue<Type>::pop()
    {
        QueueItem* pnode = head;
        head = head->next;
        delete pnode;
    }

    template<class Type> Queue<Type>::Queue() : head(0), tail(0) {}

    template<class Type> Queue<Type>::Queue(const Queue& queue) : head(0), tail(0)
    {
        copy_elements(queue);
    }

    template<class Type> Queue<Type>& Queue<Type>::operator=(const Queue& other)
    {
        destroy();
        Queue<Type>::QueueItem *pnode = other.head;
        while (pnode)
        {
            push(pnode->item);
            pnode = pnode->next;
        }
        return *this;
    }

    template<class Type> Queue<Type>::~Queue<Type>()
    {
        destroy();
    }

    template<class Type> void Queue<Type>::push(const Type& element)
    {
        Queue<Type>::QueueItem *pnode = new Queue<Type>::QueueItem(element);
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

    template<class Type> bool Queue<Type>::isEmpty() const
    {
        return (head == 0);
    }

    template<class Type> Type& Queue<Type>::front()
    {
        return head->item;
    }

    template<class Type> const Type& Queue<Type>::front() const
    {
        return head->item;
    }

    template<class Type> void Queue<Type>::destroy()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    template<class Type> void Queue<Type>::copy_elements(const Queue& other)
    {
        Queue<Type>::QueueItem *pnode = other.head;
        do
        {
            push(pnode->item);
            pnode = pnode->next;
        }
        while (pnode != 0);
    }
/*================================================================================================*/

#endif  /* QUEUE_H */
