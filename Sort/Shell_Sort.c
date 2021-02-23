#include "Sort.h"

void ShellSort(ElementType elements[], size_t N)
{
    int i, j, increment;
    ElementType tmp;

    for (increment = N/2; increment > 0; increment /= 2)
    {
        for (i = increment; i < N; i++)
        {
            tmp = elements[i];
            for (j = i; j >= increment; j -= increment)
            {
                if (tmp < elements[j-increment])
                    elements[j] = elements[j-increment];
                else
                    break;
            }
            elements[j] = tmp;
        }
    }
}