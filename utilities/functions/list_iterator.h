#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

    template<class T> struct __list_node
    {
        T data;
        __list_node* next;
        __list_node* prev;
        __list_node(T item) : data(item), next(0), prev(0) {}
    };

    template<class T, class Ref, class Ptr>
    struct __list_iterator
    {
        typedef __list_iterator<T, Ref, Ptr> self;
        typedef Ptr pointer;
        typedef Ref reference;
        typedef __list_node<T>* link_type;

        link_type node;

        bool operator==(const self& x) const;
        bool operator!=(const self& x) const;
        reference operator*() const;
        pointer operator->() const;
        self& operator++();
        self operator++(int);
        self& operator--();
        self operator--(int);
    };

    template<class T, class Ref, class Ptr>
    bool __list_iterator<T, Ref, Ptr>::operator==(const self& x) const
    {
        return (node == x);
    }

    template<class T, class Ref, class Ptr>
    bool __list_iterator<T, Ref, Ptr>::operator!=(const self& x) const
    {
        return (node != x);
    }

    template<class T, class Ref, class Ptr>
    typename __list_iterator<T, Ref, Ptr>::reference __list_iterator<T, Ref, Ptr>::operator*() const
    {
        return (*node).data;
    }

    template<class T, class Ref, class Ptr>
    typename __list_iterator<T, Ref, Ptr>::pointer __list_iterator<T, Ref, Ptr>::operator->() const
    {
        return &(operator*());
    }

    template<class T, class Ref, class Ptr>
    typename __list_iterator<T, Ref, Ptr>::self& __list_iterator<T, Ref, Ptr>::operator++()
    {
        node = static_cast<link_type>((*node).next); // (link_type)((*node).next);
        return *this;
    }

    template<class T, class Ref, class Ptr>
    typename __list_iterator<T, Ref, Ptr>::self __list_iterator<T, Ref, Ptr>::operator++(int)
    {
        self tmp = *this;
        ++*this;
        return tmp;
    }

    template<class T, class Ref, class Ptr>
    typename __list_iterator<T, Ref, Ptr>::self& __list_iterator<T, Ref, Ptr>::operator--()
    {
        node = static_cast<link_type>((*node).prev);
        return *this;
    }

    template<class T, class Ref, class Ptr>
    typename __list_iterator<T, Ref, Ptr>::self __list_iterator<T, Ref, Ptr>::operator--(int)
    {
        self tmp = *this;
        --* this;
        return tmp;
    }


#endif  /* LIST_ITERATOR_H */
