#ifndef SHARED_PTR_H
#define SHARED_PTR_H

    template<class Type> class __shared_ptr;
    template<typename _Tp> class shared_ptr;

    template<typename _Tp>
    class shared_ptr : public __shared_ptr<_Tp>
    {
    public:
        template<typename _Tp1> explicit shared_ptr(_Tp1 ptr) :
            __shared_ptr<_Tp>(ptr)
        {
        }
    };

#endif  /* SHARED_PTR_H */
