/*!
 *  \file       test_insertion_sort.c++
 *  \brief      Make the unit test for insertion sort algorithm.
 *
 *
 */


#include "test_insertion_sort.h++"
#include "insertion_sort.hpp"

#include <ctime>

/*================================================================================================*/

UTester4InsertionSort::UTester4InsertionSort() : nums(20)
/*!
 *  \warning    此时对nums初始化，千万不要使用nums{20}.
 *              因为构造函数的成员对象初始化，对于容器类对象，若使用{} intializer-list表示只给容器对象赋一个
 *              初值，容器中只含有一个元素，而不是设置容器中包含多少个元素。
 */
{
}

void UTester4InsertionSort::SetUp()
{
    std::srand(std::time(NULL));

    std::cout << "The raw random numbers: " << std::endl;
    for (auto index = 0U; index < nums.size(); ++index)
    {
        nums[index] = rand() % 500;
        std::cout << nums[index] << ((index == nums.size()-1) ? " " : ", ");
    }
    std::cout << "\n" << std::endl;
}

void UTester4InsertionSort::print_numbers()
{
    for (size_t index = 0; index < nums.size(); ++index)
    {
        std::cout << nums[index] << ((index == nums.size()-1) ? " " : ", ");
    }
    std::cout << "\n" << std::endl;
}

/*================================================================================================*/

TEST_F(UTester4InsertionSort, CheckInsertionSort)
{
    insertionSort(nums);

    std::cout << "After insertion-sort: " << std::endl;
    print_numbers();
}

TEST_F(UTester4InsertionSort, CheckSTLInsertionSort)
{
    stl::insertionSort(nums.begin(), nums.end());

    std::cout << "After STL insertion-sort: " << std::endl;
    print_numbers();
}
