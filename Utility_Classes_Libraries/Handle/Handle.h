/**************************************************************************************************
 * File name    : Handle.h
 * Description  : Define a smart generic Handle class, it manages the pointer member clearly.
 * Creator      : Frederick Hsu
 * Creation date: Mon.  07 Oct. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#ifndef HANDLE_H
#define HANDLE_H

    #include <stdexcept>
    #include "handle_global.h"
    /* generic handle class:
     * Provides pointer-like behaviour, although access through an unbound Handle
     * is checked and throws a runtime_error exception.
     * The object to which the "Handle" points is deleted when last Handle goes away.
     * Users should allocate new objects of type T and bind them to a "Handle".
     * Once an object is bound to a "Handle", the user must not delete that object.
     */
    template<class T>
    class HANDLESHARED_EXPORT Handle
    {
    public:
        Handle(T *p = 0);   /* unbound handle */
        Handle(const Handle& h);
        Handle& operator=(const Handle& rhs);
        ~Handle();
    public:
        /* overloaded operators to support pointer behaviour */
        T& operator*();
        T* operator->();
        const T& operator*() const;
        const T* operator->() const;
    private:
        T* ptr;         /* shared object */
        size_t *use;    /* count how many Handles point to *ptr */
    private:
        void rem_ref();
    };

    void handle_out_of_memory(const std::bad_alloc& except);

    /*============================================================================================*/

    template<class T> Handle<T>::Handle(T *p)
    try : ptr(p), use(new size_t(1))
    {
    }
    catch (const std::bad_alloc& except)
    {
        handle_out_of_memory(except);
    }

    template<class T> Handle<T>::Handle(const Handle& h) : ptr(h.ptr), use(h.use)
    {
        ++(*use);
    }

    template<class T> Handle<T>::~Handle()
    {
        rem_ref();
    }

    template<class T> void Handle<T>::rem_ref()
    {
        if (--(*use) == 0)
        {
            delete ptr;
            delete use;
        }
    }

    template<class T> Handle<T>& Handle<T>::operator=(const Handle& rhs)
    {
        ++(*(rhs.use));     /* protect against selft-assignment */
        rem_ref();          /* decrement use count and delete pointers if needed */
        ptr = rhs.ptr;
        use = rhs.use;
        return *this;
    }

    template<class T> inline T& Handle<T>::operator*()
    {
        if (ptr)
        {
            return *ptr;
        }
        throw std::runtime_error("dereference of unbound Handle.");
    }

    template<class T> inline T* Handle<T>::operator->()
    {
        if (ptr)
        {
            return ptr;
        }
        throw std::runtime_error("access through unbound Handle.");
    }

    template<class T> inline const T& Handle<T>::operator*() const
    {
        if (ptr)
        {
            return *ptr;
        }
        throw std::runtime_error("dereference of unbound Handle.");
    }

    template<class T> inline const T* Handle<T>::operator->() const
    {
        if (ptr)
        {
            return ptr;
        }
        throw std::runtime_error("access through unbound Handle.");
    }


#endif  /* HANDLE_H */
