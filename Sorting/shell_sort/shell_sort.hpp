/*!
 *  \file       shell_sort.hpp
 *  \brief
 *
 */


#pragma once


#include <vector>

/* Declaration ===================================================================================*/

template<typename ElemType> void shellSort(std::vector<ElemType>& nums);


/* Implementation ================================================================================*/

template<typename ElemType> void shellSort(std::vector<ElemType>& nums)
{
    for (int gap = nums.size()/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < nums.size(); ++i)
        {
            ElemType tmp = std::move(nums[i]);

            int j = 0;
            for (j = i; j >= gap && tmp < nums[j-gap]; j -= gap)
            {
                nums[j] = std::move(nums[j-gap]);
            }
            nums[j] = std::move(tmp);
        }
    }
}
