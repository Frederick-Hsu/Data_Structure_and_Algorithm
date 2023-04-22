/*!
 *  \file       test_binary_search_tree.h++
 *  \brief      Make the unit test for some actions about binary search tree.
 *
 */


#include <gtest/gtest.h>

#include "tree.h"

class UTester4BinarySearchTree : public ::testing::Test
{
protected:
    SearchTree tree;
public:
    UTester4BinarySearchTree();
    ~UTester4BinarySearchTree();

    void SetUp() override;
    void TearDown() override;
};
