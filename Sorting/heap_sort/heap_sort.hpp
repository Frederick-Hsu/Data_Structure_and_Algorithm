/*!
 *  \file       heap_sort.hpp
 *  \brief
 *
 */


#pragma once


#include <vector>

/* Declaration ===================================================================================*/

template<typename ElemType> void heapSort(std::vector<ElemType>& nums);
template<typename ElemType> void percDown(std::vector<ElemType>& nums, int i, int n);
inline int leftChild(int i);


/* Implementation ================================================================================*/

/*!
 *  \brief      标准的堆排序
 */
template<typename ElemType> void heapSort(std::vector<ElemType>& nums)
{
    for (int i = nums.size()/2 - 1; i >= 0; --i)
    {
        percDown(nums, i, nums.size());
    }
    for (int j = nums.size() - 1; j > 0; --j)
    {
        std::swap(nums[0], nums[j]);
        percDown(nums, 0, j);
    }
}

/*!
 *  \brief      堆排序的内部方法
 *  \param      i 是堆中一项的下标发
 *  \return     返回左儿子的下标
 */
int leftChild(int i)
{
    return 2 * i + 1;
}

template<typename ElemType> void percDown(std::vector<ElemType>& nums, int i, int n)
{
    int child;
    ElemType tmp;

    for (tmp = std::move(nums[i]); leftChild(i) < n; i = child)
    {
        child = leftChild(i);
        if ((child != n -1) && (nums[child] < nums[child+1]))
        {
            ++child;
        }
        if (tmp < nums[child])
        {
            nums[i] = std::move(nums[child]);
        }
        else
        {
            break;
        }
    }
    nums[i] = std::move(tmp);
}
