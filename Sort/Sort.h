#ifndef SORT_H
#define SORT_H

    #include <stddef.h>

    typedef int     ElementType;

    void InsertionSort(ElementType elements[], size_t N);
    void ShellSort(ElementType elements[], size_t N);
    void HeapSort(ElementType elements[], size_t N);

#endif  /* SORT_H */