/*!
 *  \file       utest_binary_search_tree.hxx
 *  \brief      Make some unit testing for the class template BInarySearchTree<ELemType>
 *
 */


#pragma once

#include <gtest/gtest.h>

#include "binary_serach_tree.hpp"

class GTester4BinarySearchTree : public ::testing::Test
{
protected:
    BinarySearchTree<int> bstree;
public:
    GTester4BinarySearchTree();
    ~GTester4BinarySearchTree();
};
