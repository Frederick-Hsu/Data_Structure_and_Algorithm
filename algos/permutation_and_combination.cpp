#include "permutation_and_combination.h"

#include <cstdio>
using namespace std;

void permutation(char* pStr, char* pBegin)      /* The permutation without repeation */
{
    assert(pStr && pBegin);
    if (*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for (char* pCh = pBegin, *pCh != '\0', ++pCh)
        {
            swap(*pBegin, *pCh);
            permutation(pStr, pBegin + 1);
            swap(*pBegin, *pCh);
        }
    }
}