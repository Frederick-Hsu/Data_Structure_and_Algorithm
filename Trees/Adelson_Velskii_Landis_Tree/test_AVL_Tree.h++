/*!
 *  \file       test_AVL_Tree.h++
 *  \brief      Define the unit test class for AVLTree.
 *
 */


#pragma once

#include <gtest/gtest.h>

#include "AVL_Tree.hpp"

class UTester4AVLTree : public ::testing::Test
{
protected:
    AVLTree<int> avl_tree;
public:
    UTester4AVLTree() : avl_tree(5) {}
    ~UTester4AVLTree() {}
};
