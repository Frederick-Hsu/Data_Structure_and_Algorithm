/*!
 *  \file       test_shell_sort.h++
 *  \brief
 *
 */


#pragma once

#include <gtest/gtest.h>

class UTester4ShellSort : public ::testing::Test
{
protected:
    std::vector<int> nums;
public:
    UTester4ShellSort();
    void SetUp() override;
    void printNumbers();
    bool isSorted();
};
