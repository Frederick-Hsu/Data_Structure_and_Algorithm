#ifndef LIST_H
#define LIST_H

    #include <iostream>
    using namespace std;

    template<class elemType> class ListItem;
    template<class elemType> class List;

    template<class elemType> ostream& operator<<(ostream& out, const List<elemType>& lst);
    template<class elemType> istream& operator>>(istream& in,        List<elemType>& lst);

    /*============================================================================================*/

    template<class elemType>
    class ListItem
    {
        friend class List<elemType>;
        friend ostream& operator<< <elemType>(ostream& out, const List<elemType>& lst);
        friend istream& operator>> <elemType>(istream& in,        List<elemType>& lst);
    private:
        ListItem(const elemType& elem);
        ~ListItem();
    private:
        elemType element;
        ListItem* next;
    };

    /*============================================================================================*/

    template<class elemType>
    class List
    {
        friend ostream& operator<< <elemType>(ostream& out, const List<elemType>& lst);
        friend istream& operator>> <elemType>(istream& in,        List<elemType>& lst);
    public:
        List();
        List(const List& lst);
        List& operator=(const List& orig);
        ~List();
    public:
        template<class Iter> List(Iter begin, Iter end);
        template<class Iter> void assign(Iter begin, Iter end);
    public:
        void insert(ListItem<elemType>* ptr, elemType value);
        void insert(unsigned atPos, elemType element);
        ListItem<elemType>* find(elemType value);
        void append(elemType element);
        bool isEmpty() const;
        void remove(unsigned atPos);
        unsigned count() const;
    private:
        ListItem<elemType>* front;
        ListItem<elemType>* end;
    private:
        void destroy();
    };

/*=================================================================================================*/

    template<class elemType> ListItem<elemType>::ListItem(const elemType& elem) : element(elem), next(0)
    {
    }

    template<class elemType> ListItem<elemType>::~ListItem()
    {
        next = 0;
    }

    template<class elemType> List<elemType>::List() : front(0), end(0)
    {
    }

    template<class elemType> List<elemType>::~List()
    {
        destroy();
    }

    template<class elemType> void List<elemType>::destroy()
    {
        while (front)
        {
            ListItem<elemType> *ptr = front->next;
            delete  front;
            front = ptr;
        }
    }

    template<class elemType> List<elemType>::List(const List& orig) : front(0), end(0)
    {
        ListItem<elemType> *ptr = orig.front;
        while (ptr)
        {
            append(ptr->element);
            ptr = ptr->next;
        }
    }

    template<class elemType> void List<elemType>::append(elemType element)
    {
        ListItem<elemType> *pNewNode = new ListItem<elemType>(element);
        if (isEmpty())
        {
            front = end = pNewNode;
        }
        else
        {
            end->next = pNewNode;
            end = pNewNode;
        }
    }

    template<class elemType> bool List<elemType>::isEmpty() const
    {
        if (front == 0)
            return true;
        else
            return false;
    }

    template<class elemType> ostream& operator<<(ostream& out, const List<elemType>& lst)
    {
        out << "[  ";
        ListItem<elemType> *ptr = lst.front;
        while (ptr)
        {
            if (ptr == lst.end)
            {
                out << ptr->element << "  ";
            }
            else
            {
                out << ptr->element << ",  ";
            }
            ptr = ptr->next;
        }
        out << "]";
        return out;
    }

    template<class elemType> istream& operator>>(istream& in, List<elemType>& lst)
    {
        elemType node_element;
        while (in >> node_element)
        {
            lst.append(node_element);
        }
        return in;
    }

    template<class elemType> List<elemType>& List<elemType>::operator=(const List& orig)
    {
        destroy();
        ListItem<elemType> *ptr = orig.front;
        while (ptr)
        {
            append(ptr->element);
            ptr = ptr->next;
        }
        return *this;
    }

    template<class elemType> ListItem<elemType>* List<elemType>::find(elemType value)
    {
        ListItem<elemType> *ptr = front;
        ListItem<elemType> *target = 0;
        while (ptr)
        {
            if (ptr->element == value)
            {
                target = new ListItem<elemType>(value);
                break;
            }
            ptr = ptr->next;
        }
        return target;
    }

    template<class elemType> void List<elemType>::insert(ListItem<elemType>* ptr, elemType value)
    {
        ListItem<elemType> *pnode = front;
        while (pnode)
        {
            if (pnode == ptr)
            {
                ListItem<elemType> *newnode = new ListItem<elemType>(value);
                newnode->next = pnode->next;
                pnode->next = newnode;
                break;
            }
            pnode = pnode->next;
        }
    }

    template<class elemType> void List<elemType>::insert(unsigned atPos, elemType element)
    {
        ListItem<elemType> *pnode = front;
        unsigned pos = 1;
        while (pnode)
        {
            if (pos == atPos)
            {
                ListItem<elemType> *newnode = new ListItem<elemType>(element);
                newnode->next = pnode->next;
                pnode->next = newnode;
                break;
            }
            ++pos;
            pnode = pnode->next;
        }
    }

    template<class elemType> void List<elemType>::remove(unsigned atPos)
    {
        ListItem<elemType> *pnode = front;
        unsigned pos = 1;
        while (pnode)
        {
            if ((pos+1) == atPos)
            {
                ListItem<elemType> *nodeToDelete = pnode->next;
                pnode->next = nodeToDelete->next;
                delete nodeToDelete;
                break;
            }
            ++pos;
            pnode = pnode->next;
        }
    }

    template<class elemType> unsigned List<elemType>::count() const
    {
        ListItem<elemType>* pnode = front;
        unsigned len = 0;
        while (pnode)
        {
            ++len;
            pnode = pnode->next;
        }
        return len;
    }

    template<class elemType> template<class Iter> List<elemType>::List(Iter begin, Iter end) : front(0), end(0)
    {
        for (Iter it = begin; it != end; ++it)
        {
            append(*it);
        }
    }

    template<class elemType> template<class Iter> void List<elemType>::assign(Iter begin, Iter end)
    {
        destroy();
        for (Iter it = begin; it != end; ++it)
        {
            append(*it);
        }
    }

#endif  /* LIST_H */
