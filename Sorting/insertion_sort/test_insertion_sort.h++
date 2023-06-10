/*!
 *  \file       test_insertion_sort.h++
 *  \brief
 *
 */


#include <gtest/gtest.h>
#include <vector>

class UTester4InsertionSort : public ::testing::Test
{
protected:
    std::vector<int> nums;
public:
    UTester4InsertionSort();

    void SetUp() override;
    void print_numbers();
};
