#ifndef TEMPLATE_FUNCTOR_H
#define TEMPLATE_FUNCTOR_H

    #include "unary_binary_functions.h"

    template<class T1, class T2> struct Pair;
    template<class T> struct identity;
    template<class Pair> struct select1st;
    template<class Pair> struct select2nd;

    template<class T1, class T2>
    struct Pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;
        Pair();
        Pair(const T1& a, const T2& b);
        template<class U1, class U2> Pair(const Pair<U1, U2>& pair_item);
    };

    template<class T> struct identity : public unary_function<T, T>
    {
        const T& operator()(const T& x) const;
    };

    template<class Pair>
    struct select1st : public unary_function<Pair, typename Pair::first_type>
    {
        const typename Pair::first_type& operator()(const Pair& x) const;
    };

    template<class Pair>
    struct select2nd : public unary_function<Pair, typename Pair::second_type>
    {
        const typename Pair::second_type& operator()(const Pair& x) const;
    };

/*================================================================================================*/

    template<class T1, class T2> Pair<T1, T2>::Pair() : first(T1()), second(T2())
    {
    }

    template<class T1, class T2> Pair<T1, T2>::Pair(const T1& a, const T2& b) : first(a), second(b)
    {
    }

    template<class T1, class T2> template<class U1, class U2>
    Pair<T1, T2>::Pair(const Pair<U1, U2>& pair_item) : first(pair_item.first), second(pair_item.second)
    {
    }

    template<class T> const T& identity<T>::operator()(const T& x) const
    {
        return x;
    }

    template<class Pair> const typename Pair::second_type& select2nd<Pair>::operator()(const Pair& x) const
    {
        return x.second;
    }

    template<class Pair> const typename Pair::first_type& select1st<Pair>::operator()(const Pair& x) const
    {
        return x.first;
    }

#endif  /* TEMPLATE_FUNCTOR_H */
