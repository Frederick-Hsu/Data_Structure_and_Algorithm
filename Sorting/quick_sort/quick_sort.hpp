/*!
 *  \file       quick_sort.hpp
 *  \brief
 *
 */



#pragma once

#include <vector>

/* Declaration ===================================================================================*/

template<typename ElemType> void swap(std::vector<ElemType>& nums, int i, int j);
template<typename ElemType> void partition(std::vector<ElemType>& nums, int left, int right);



/* Implementation ================================================================================*/

template<typename ElemType> void swap(std::vector<ElemType>& nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

template<typename ElemType> int partition(std::vector<ElemType>& nums, int left, int right)
{
    int i = left, j = right;
    while (i < j)
    {
        while(i < j && nums[j] >= nums[left])
        {
            j--;
        }
        while (i < j && nums[j] <= nums[left])
        {
            i++;
        }
        swap(nums, i, j);
    }
    swap(nums, i, left);
    return i;
}
