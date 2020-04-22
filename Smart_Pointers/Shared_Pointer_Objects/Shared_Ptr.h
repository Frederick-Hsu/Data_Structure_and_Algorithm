#ifndef SHARED_PTR_H
#define SHARED_PTR_H

    template<typename Type>
    class Shared_Ptr
    {
    public:
        explicit Shared_Ptr(Type* p = nullptr);
        Shared_Ptr(const Shared_Ptr& orig);
        Shared_Ptr& operator=(const Shared_Ptr& orig);
        ~Shared_Ptr();
    public:
        size_t use_count();
        Type& operator*();
        Type* operator->();
        const Type& operator*() const;
        const Type* operator->() const;
    private:
        size_t use;
        Type* ptr;
    };

    #include "Shared_Ptr.cpp"

    template<typename Type>
    Shared_Ptr<Type>::Shared_Ptr(Type* p) : ptr(p)
    {
        use = 1;
    }

    template<typename Type>
    Shared_Ptr<Type>::Shared_Ptr(const Shared_Ptr& orig) : use(orig.use), ptr(orig.ptr)
    {
        ++use;
    }

    template<typename Type>
    Shared_Ptr<Type>& Shared_Ptr<Type>::operator=(const Shared_Ptr& orig)
    {
        ++(orig.use);
        if (--use == 0)
        {
            delete ptr;
        }
        ptr = orig.ptr;
        use = orig.use;
        return *this;
    }

    template<typename Type>
    Shared_Ptr<Type>::~Shared_Ptr<Type>()
    {
        if (--use == 0)
        {
            delete ptr;
        }
    }

    template<typename Type>
    size_t Shared_Ptr<Type>::use_count()
    {
        return use;
    }


#endif  /* SHARED_PTR_H */
