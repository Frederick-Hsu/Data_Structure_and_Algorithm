/*!
 *  \file       insertion_sort.hpp
 *  \brief      研究插入排序算法
 *
 *
 */


#pragma once

#include <vector>
#include <utility>
#include <functional>

/* Declaration ===================================================================================*/

template<typename ElemType> void insertionSort(std::vector<ElemType>& nums);

namespace stl
{
    template<typename Iterator> void insertionSort(const Iterator& begin, const Iterator& end);
    template<typename Iterator, typename Comparator> void insertionSort(const Iterator& begin,
                                                                        const Iterator& end,
                                                                        Comparator lessThan);
}


/* Implementation ================================================================================*/

template<typename ElemType> void insertionSort(std::vector<ElemType>& nums)
{
    for (std::size_t i = 1; i < nums.size(); ++i)
    {
        ElemType tmp = std::move(nums[i]);

        std::size_t j;
        for (j = i; j > 0 && tmp < nums[j-1]; --j)
        {
            nums[j] = std::move(nums[j-1]);
        }
        nums[j] = std::move(tmp);
    }
}


namespace stl
{
    template<typename Iterator> void insertionSort(const Iterator& begin, const Iterator& end)
    {
        insertionSort(begin, end, std::less<decltype(*begin)>{});
    }

    template<typename Iterator, typename Comparator> void insertionSort(const Iterator& begin,
                                                                        const Iterator& end,
                                                                        Comparator lessThan)
    {
        if (begin == end)
            return;

        for (Iterator i = begin + 1; i != end; ++i)
        {
            auto tmp = std::move(*i);

            Iterator j;
            for (j = i; j != begin && lessThan(tmp, *(j-1)); --j)
            {
                *j = std::move(*(j-1));
            }
            *j = std::move(tmp);
        }
    }
}
