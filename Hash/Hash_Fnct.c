#include "Hash_Fnct.h"

Index Hash(const char* key, int TableSize)
{
    unsigned int hashValue = 0;

    while (*key != '\0')
    {
        hashValue += *key++;
    }
    return (hashValue % TableSize);
}