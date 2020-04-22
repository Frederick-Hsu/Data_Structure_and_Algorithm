#ifndef HANDLE_H
#define HANDLE_H

    #include <cstddef>
    #include <stdexcept>
    #include <iostream>
    
    using namespace std;
    /* generic handle class :
     * Provides pointerlike behaviour. Although access through an unbound Handle
     * is checked and throw a runtime_error exception. The object to which the 
     * Handle points is deleted when the last Handle goes away.
     * Users should allocate new objects of type T and bind them to a Handle.
     * Once an object is bound to a Handle, the user must not delete that object.
     *
     */

    template<class Type> class Handle
    {
    public:
        Handle(Type *p = 0);    /* unbound handle */
        /* copy control: normal pointer behaviour, but last Handle deletes the object */
        Handle(const Handle& h);
        Handle& operator=(const Handle&);
        ~Handle();
    public:
        /* overloaded operators to support pointer behaviour */
        Type& operator*();
        Type* operator->();
        const Type& operator*() const;
        const Type* operator->() const;
    private:
        Type* ptr;      /* shared object */
        size_t *use;    /* count of how many Handles point to *ptr */
        void rem_ref();
    };

/*=================================================================================================*/

    template<class Type> Handle<Type>::Handle(Type *p)
    try : ptr(p), use(new size_t(1))
    {
    }
    catch (const std::bad_alloc& e)
    {
        // handle_out_of_memory(e);
        cout << e.what() << endl;
    }

    template<class Type> Handle<Type>::Handle(const Handle& h) : ptr(h.ptr), use(h.use)
    {
        ++(*use);
    }

    template<class Type> Handle<Type>::~Handle()
    {
        rem_ref();
    }

    template<class Type> void Handle<Type>::rem_ref()
    {
        if (--*use == 0)
        {
            delete ptr;
            delete use;
        }
    }

    template<class Type> inline Handle<Type>& Handle<Type>::operator=(const Handle& rhs)
    {
        ++(*(rhs.use));     /* protect against self-assignment */
        rem_ref();          /* decrement use count and delete pointers if needed */
        ptr = rhs.ptr;
        use = rhs.use;
        return *this;
    }

    template<class Type> inline Type& Handle<Type>::operator*()
    {
        if (ptr)
            return *ptr;
        throw std::runtime_error("dereference of unbound Handle.");
    }

    template<class Type> inline Type* Handle<Type>::operator->()
    {
        if (ptr)
            return ptr;
        throw std::runtime_error("access through unbound Handle.");
    }

    template<class Type> const Type& Handle<Type>::operator*() const
    {
        if (ptr)
            return *ptr;
        throw std::runtime_error("dereference of unbound Handle.");
    }

    template<class Type> const Type* Handle<Type>::operator->() const
    {
        if (ptr)
            return ptr;
        throw std::runtime_error("access through unbound Handle.");
    }

#endif  /* HANDLE_H */
