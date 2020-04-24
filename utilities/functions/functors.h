#ifndef FUNCTOR_H
#define FUNCTOR_H

    #include "unary_binary_functions.h"

    template<class T> struct plus : binary_function<T, T, T>
    {
        T operator()(const T& x, const T& y) const;
    };

    template<class T> struct minus : binary_function<T, T, T>
    {
        T operator()(const T& x, const T& y) const;
    };

    template<class T> struct equal_to : public binary_function<T, T, bool>
    {
        bool operator()(const T& x, const T& y) const;
    };

    template<class T> struct less : public binary_function<T, T, bool>
    {
        bool operator()(const T&x, const T& y) const;
    };

/*================================================================================================*/

    template<class T> T plus<T>::operator()(const T& x, const T& y) const
    {
        return (x + y);
    }

    template<class T> T minus<T>::operator()(const T& x, const T& y) const
    {
        return (x - y);
    }

    template<class T> bool equal_to<T>::operator()(const T& x, const T& y) const
    {
        return (x == y);
    }

    template<class T> bool less<T>::operator()(const T& x, const T& y) const
    {
        return (x < y);
    }

#endif  /* FUNCTOR_H */
