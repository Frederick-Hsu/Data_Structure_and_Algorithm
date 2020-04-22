#ifndef FUNCTION_TEMPLATE_H
#define FUNCTION_TEMPLATE_H

    #include <string>
    #include <cstring>
    #include <cstddef>
    #include <vector>

    using namespace std;

    template<typename Type> int compare(const Type&, const Type&);
    /* special version of compare to handle C-style character strings */
    template<> int compare<const char*>(const char* const& v1, const char* const& v2);

    // int *pfnct(const int&, const int&) = compare;

    /* overloaded versions of func; each takes a different function pointer type */
    void func(int(*) (const string&, const string&));
    void func(int(*) (const int&, const int&));
    // func(compare<int>);     /* OK: explicitly specify which version of compare */

    template<typename T, size_t N> void array_init(T (&parm)[N]);
    template<size_t N> void fibonacci_series(unsigned (&fib)[N]);
    template<size_t N> void fibonacci_series(vector<size_t> &fib);
    template<size_t N> void fibonacci_ratio_series(vector<long double> &fib_ratio);

/**************************************************************************************************/

    template<typename Type> int compare(const Type& v1, const Type& v2)
    {
        if (v1 < v2)
            return -1;
        if (v2 < v1)
            return 1;
        return 0;
    }

    template<> int compare<const char*>(const char* const& v1, const char* const& v2)
    {
        return strcmp(v1, v2);
    }

    template<typename T, size_t N> void array_init(T (&parm)[N])
    {
        for (size_t index = 0; index != N; ++index)
        {
            parm[index] = 0;
        }
    }

    template<size_t N> void fibonacci_series(unsigned (&fib)[N])
    {
        fib[0] = 1;
        fib[1] = 1;

        for (size_t index = 2; index < N; ++index)
        {
            fib[index] = fib[index-1] + fib[index-2];
        }
    }

    template<size_t N> void fibonacci_series(vector<size_t> &fib)
    {
        fib.push_back(1);
        fib.push_back(1);

        for (size_t index = 2; index < N; ++index)
        {
            fib.push_back(fib[index-1] + fib[index-2]);
        }
    }

    template<size_t N> void fibonacci_ratio_series(vector<long double> &fib_ratio)
    {
        vector<size_t> fib;
        fib.push_back(1);
        fib.push_back(1);

        for (size_t index = 2; index < N; ++index)
        {
            fib.push_back(fib[index-1] + fib[index-2]);
            fib_ratio.push_back(static_cast<long double>(fib[index-2]) / static_cast<long double>(fib[index-1]));
        }
        return;
    }

#endif  /* FUNCTION_TEMPLATE_H */
