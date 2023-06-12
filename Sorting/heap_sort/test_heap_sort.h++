/*!
 *  \file       test_heap_sort.h++
 *  \brief
 *
 */


#include <gtest/gtest.h>

class UTester4HeapSort : public ::testing::Test
{
protected:
    std::vector<int> nums;
public:
    UTester4HeapSort();
    void SetUp() override;
    void PrintNumbers();
};
