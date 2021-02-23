#include "test.h"
#include "Sort.h"

#include <stdio.h>

void test_sort_algorithms(void)
{
    printf("\nInsertion Sort:\n");
    test_InsertionSort();

    printf("\nShell Sort:\n");
    test_ShellSort();
}

static void PrintElements(ElementType elements[], size_t N)
{
    for (int index = 0; index < N; ++index)
    {
        printf("% 4d    ", elements[index]);
    }
    printf("\n");
}

void test_InsertionSort(void)
{
    ElementType elements[] = {34, 8, 64, 51, 32, 21, -15, 83, 125, -306};
    printf("Raw data:\n");
    PrintElements(elements, sizeof(elements)/sizeof(ElementType));

    InsertionSort(elements, sizeof(elements)/sizeof(ElementType));

    printf("Sorted data:\n");
    PrintElements(elements, sizeof(elements)/sizeof(ElementType));
}

void test_ShellSort(void)
{
    ElementType elements[] = {1, 9, 2, 10, 3, 11, 4, 12, 5, 13, 6, 14, 7, 15, 8, 16};
    printf("Raw data:\n");
    PrintElements(elements, sizeof(elements)/sizeof(ElementType));

    ShellSort(elements, sizeof(elements)/sizeof(ElementType));

    printf("Sorted data:\n");
    PrintElements(elements, sizeof(elements)/sizeof(ElementType));
}