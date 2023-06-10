/*!
 *  \file       main.cpp
 *  \brief      Study all kinds of sorting algorithms in this project.
 *  \author     Frederique Hsu
 *  \date       Wed.    26 Apr. 2023
 *
 */



#include <gtest/gtest.h>


/*!
 *  \attention      基于比较的排序 comparison-based sorting
 */

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*!
 *  \ref        STL中的排序函数模板
 *
 *  \code
 *
 *  #include <algorithm>
 *
 *  template<typename Iterator> void sort(Iteractor begin, Iterator end);
 *  template<typename Iterator, typename Comparator> void sort(Iterator begin,
 *                                                             Iterator end,
 *                                                             Comparator cmp);
 *  \endcode
 */
