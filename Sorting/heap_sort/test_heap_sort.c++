/*!
 *  \file       test_heap_sort.c++
 *  \brief
 *
 */


#include "test_heap_sort.h++"
#include "heap_sort.hpp"

UTester4HeapSort::UTester4HeapSort() : nums(25)
{
}

void UTester4HeapSort::SetUp()
{
    std::srand(std::time(NULL));

    std::cout << "The raw sequence is: " << std::endl;
    auto size = nums.size();
    for (auto index = 0U; index < size; ++index)
    {
        nums[index] = std::rand() % 301;
        std::cout << nums[index] << ((index != size-1) ? ", " : " ");
    }
    std::cout << "\n" << std::endl;
}

void UTester4HeapSort::PrintNumbers()
{
    auto size = nums.size();
    for (auto index = 0U; index < size; ++index)
    {
        std::cout << nums[index] << ((index != size-1) ? ", " : " ");
    }
    std::cout << "\n" << std::endl;
}

/*================================================================================================*/

TEST_F(UTester4HeapSort, CheckHeapSort)
{
    heapSort(nums);

    std::cout << "After Heap-Sort: " << std::endl;
    PrintNumbers();
}
