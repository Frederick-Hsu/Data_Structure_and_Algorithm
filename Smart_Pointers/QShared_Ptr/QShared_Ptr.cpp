#include <stdexcept>

template<typename Type>
QShared_Ptr<Type>::QShared_Ptr(Type* p) : ptr(p)
{
    use = 1;
}

template<typename Type>
QShared_Ptr<Type>::~QShared_Ptr<Type>()
{
    if (--use == 0)
    {
        delete ptr;
    }
}

template<typename Type>
QShared_Ptr<Type>::QShared_Ptr(const QShared_Ptr& orig) : use(orig.use), ptr(orig.ptr)
{
    ++use;
}

template<typename Type>
QShared_Ptr<Type>& QShared_Ptr<Type>::operator=(const QShared_Ptr& orig)
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
Type& QShared_Ptr<Type>::operator*()
{
    if (ptr)
    {
        return *ptr;
    }
    throw std::runtime_error("dereference of unbound shared pointer.");
}
