#include "Sort.h"

void InsertionSort(ElementType elements[], size_t N)
{
    ElementType tmp;
    int index;
    for (int pass = 1; pass < N; ++pass)
    {
        tmp = elements[pass];
        for (index = pass; (index > 0) && (elements[index-1] > tmp); --index)
        {
            elements[index] = elements[index-1];
        }
        elements[index] = tmp;
    }
}