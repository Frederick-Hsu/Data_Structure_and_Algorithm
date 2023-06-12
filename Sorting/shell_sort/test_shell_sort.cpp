/*!
 *  \file       test_shell_sort.cpp
 *  \brief
 *
 */


#include "test_shell_sort.hpp"
#include "shell_sort.hpp"

UTester4ShellSort::UTester4ShellSort() : nums(30)
{
}

void UTester4ShellSort::SetUp()
{
    std::srand(std::time(NULL));

    std::cout << "The raw sequence is: " << std::endl;
    for (auto index = 0U; index < nums.size(); ++index)
    {
        nums[index] = std::rand() % 200;
        std::cout << nums[index] << ((index == nums.size()-1) ? " " : ", ");
    }
    std::cout << "\n" << std::endl;
}

void UTester4ShellSort::printNumbers()
{
    for (auto index = 0U; index < nums.size(); ++index)
    {
        std::cout << nums[index] << ((index == nums.size()-1) ? " " : ", ");
    }
    std::cout << "\n" << std::endl;
}

bool UTester4ShellSort::isSorted()
{
    bool flag = false;
    for (auto index = 0U; index != (nums.size()-1); ++index)
    {
        if (nums[index] <= nums[index+1])
        {
            flag = true;
        }
        else
        {
            return false;
        }
    }
    return flag;
}

/*================================================================================================*/

TEST_F(UTester4ShellSort, CheckShellSort)
{
    shellSort(nums);

    std::cout << "After shell-sort: " << std::endl;
    printNumbers();

    EXPECT_EQ(isSorted(), true);
}
