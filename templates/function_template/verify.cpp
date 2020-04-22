#include "verify.h"
#include "template_overload.h"

#include <string>
#include <vector>


void instantiate_specialized_objects(void)
{
    some_template<int, std::string> foo(0, "zero");     /* use template */
    some_template<std::string, int> bar("partial", 100);    /* use partial specialization */
}

void determine_overloaded_fncts(void)
{
    comparison(1, 0);       /* call int comparison(const T&, const T&) */
    std::vector<int> ivec1(10), ivec2(20);
    comparison(ivec1.begin(), ivec1.end(), ivec2.begin());      /* call int comparison(U, U, V) */

    int iarray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    comparison(iarray, iarray + 8, ivec1.begin());          /* call int comparison(U, U, V) */

    const char const_arr1[] = "world", const_arr2[] = "hi";
    comparison(const_arr1, const_arr2);         /* call int comparison(const char* str1, const char* str2); */

    char str1[] = "love", str2[] = "peace";
    comparison(str1, str2);
}
