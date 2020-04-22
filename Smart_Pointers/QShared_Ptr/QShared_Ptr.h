#ifndef QSHARED_PTR_H
#define QSHARED_PTR_H

    template<typename Type>
    class QShared_Ptr
    {
    public:
        explicit QShared_Ptr(Type* p = nullptr);
        QShared_Ptr(const QShared_Ptr& orig);
        QShared_Ptr& operator=(const QShared_Ptr& orig);
        ~QShared_Ptr();
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

    #include "QShared_Ptr.cpp"



#endif  /* QSHARED_PTR_H */
