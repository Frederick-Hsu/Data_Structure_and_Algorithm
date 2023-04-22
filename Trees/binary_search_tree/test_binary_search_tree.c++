/*!
 *  \file       test_binary_search_tree.c++
 *  \brief      Implement the unit test fixture and carry out the unit testing.
 *
 */


#include "test_binary_search_tree.h++"

#include <iostream>

UTester4BinarySearchTree::UTester4BinarySearchTree() : tree(NULL)
{
}

UTester4BinarySearchTree::~UTester4BinarySearchTree()
{
    if (tree != NULL)
    {
        // std::cerr << "Fatal error: the tree has not yet been destroyed!\n" << std::endl;
        MakeEmpty(tree);
    }
}

void UTester4BinarySearchTree::SetUp()
{
    std::cout << "Executing UTester4BinarySearchTree::SetUp() method..." << std::endl;
    MakeEmpty(tree);
}

void UTester4BinarySearchTree::TearDown()
{
    std::cout << "Executing UTester4BinarySearchTree::TearDown() method..." << std::endl;
    if (tree != NULL)
    {
        MakeEmpty(tree);
    }
}

TEST_F(UTester4BinarySearchTree, InsertRootNode)
{
    std::cout << "Carrying out the unit test..." << std::endl;

    SearchTree root = Insert(6, tree);
    EXPECT_EQ(root->element, 6);
}

TEST(BinarySearchTreeUTester, CheckTreeFindFunctions)
{
    SearchTree tree = NULL;
    tree= Insert(6, tree);
    Insert(3, tree);
    Insert(8, tree);
    Insert(2, tree);
    Insert(5, tree);
    Insert(1, tree);
    Insert(3, tree);
    Insert(4, tree);

    Position pos = Find(5, tree);
    EXPECT_EQ(pos->element, 5);

    Insert(11, tree);
    Insert(9, tree);
    Insert(25, tree);
    Insert(18, tree);
    Insert(-5, tree);
    Insert(-3, tree);
    Insert(-10, tree);
    Insert(30, tree);
    Insert(0, tree);

    Position max_element_node = FindMax(tree);
    EXPECT_EQ(max_element_node->element, 30);

    Position min_element_node = FindMin(tree);
    EXPECT_EQ(min_element_node->element, -10);

    MakeEmpty(tree);
}

TEST(BinarySearchTreeUTester, CheckTreeDeleteFunction)
{
    SearchTree tree = NULL;
    tree= Insert(6, tree);
    Insert(2, tree);
    Insert(8, tree);
    Insert(1, tree);
    Insert(5, tree);
    Insert(3, tree);
    Insert(4, tree);

    SearchTree removed_tree = Delete(2, tree);
    // EXPECT_EQ(removed_tree->element, 3);
    Position node = Find(2, tree);
    EXPECT_TRUE(node == NULL);

    MakeEmpty(tree);
}
