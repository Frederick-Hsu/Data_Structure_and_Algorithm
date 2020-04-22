#ifndef TEMPLATE_OVERLOAD_H
#define TEMPLATE_OVERLOAD_H

    #include <cstring>

    template<class T, class U> class some_template;
    template<class T>          class some_template<T, int>;

    template<class T, class U> class some_template
    {
    public:
        some_template(T number, U count);
    private:
        T num;
        U cnt;
    };

    /* partial specialization: fixed U as int, and allows T to vary */
    template<class T> class some_template<T, int>
    {
    public:
        some_template(T number, int size);
    private:
        T num;
        int byte_size;
    };


    template<class T, class U> some_template<T, U>::some_template(T number, U count)
        : num(number), cnt(count)
    {
    }

    template<class T> some_template<T, int>::some_template(T number, int size)
        : num(number), byte_size(size)
    {
    }

/*=================================================================================================*/

    /* compare two objects */
    template<typename T>       int comparison(const T&, const T&);
    /* compares elements in two sequences */
    template<class U, class V> int comparison(U, U, V);
    /* plain functions to handle C-style character strings */
                               int comparison(const char*, const char*);


    template<typename T> int comparison(const T& a, const T& b)
    {
        if (a < b)  return 1;
        if (b < a)  return -1;
        return 0;
    }

    template<class U, class T> int comparison(U seq1_begin, U seq1_end, T seq2_begin)
    {
        int accumulate = 0;
        T it = seq2_begin;
        for (U iter = seq1_begin; iter != seq1_end; ++iter)
        {
            if (*iter < *it)
            {
                accumulate += 1;
            }
            else if (*it < *iter)
            {
                accumulate += -1;
            }
            else
            {
                accumulate += 0;
            }
            ++it;
        }
        return accumulate;
    }

    int comparison(const char* str1, const char* str2)
    {
        return std::strcmp(str1, str2);
    }
#endif  /* TEMPLATE_OVERLOAD_H */
