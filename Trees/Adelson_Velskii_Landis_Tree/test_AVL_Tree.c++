/*!
 *  \file       test_AVL_Tree.c++
 *  \brief      Make some unit testing for the AVL Tree.
 *
 */

#include "test_AVL_Tree.h++"


TEST_F(UTester4AVLTree, CheckInsertMethod)
{
    EXPECT_EQ(avl_tree.contains(5), true);
    EXPECT_EQ(avl_tree.contains(10), false);

    avl_tree.insert(3);
    avl_tree.insert(10);
    EXPECT_EQ(avl_tree.contains(10), true);
}

TEST_F(UTester4AVLTree, CheckLeftRotate)
{
    avl_tree.insert(8);
    avl_tree.insert(3);
    avl_tree.insert(10);
    avl_tree.insert(12);
}

TEST_F(UTester4AVLTree, CheckRightRotate)
{
    avl_tree.insert(4);
    avl_tree.insert(8);
    avl_tree.insert(3);
    avl_tree.insert(2);
}

TEST_F(UTester4AVLTree, CheckFistLeftRotateLastRightRotate)
{
    avl_tree.insert(4);
    avl_tree.insert(9);
    avl_tree.insert(2);
    avl_tree.insert(3);
}

TEST_F(UTester4AVLTree, CheckFirstRightRotateLastLeftRotate)
{
    avl_tree.insert(8);
    avl_tree.insert(3);
    avl_tree.insert(10);
    avl_tree.insert(9);
}

TEST_F(UTester4AVLTree, CheckRemoveItem)
{
    avl_tree.insert(9);
    avl_tree.insert(3);
    avl_tree.insert(8);
    avl_tree.insert(10);
    avl_tree.insert(7);
    avl_tree.insert(1);
    avl_tree.insert(4);
    avl_tree.insert(15);
    avl_tree.insert(6);

    avl_tree.remove(5);
    EXPECT_EQ(avl_tree.contains(5), false);
}
