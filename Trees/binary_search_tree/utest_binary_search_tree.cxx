/*!
 *  \file       test_binary_search_tree.cxx
 *  \brief      Make the unit testing case for BinarySearchTree<Type> class template.
 *
 */


#include "utest_binary_search_tree.hxx"

GTester4BinarySearchTree::GTester4BinarySearchTree() : bstree{5}
{
}

GTester4BinarySearchTree::~GTester4BinarySearchTree()
{
    bstree.makeEmpty();
}

/*================================================================================================*/

void print_tree_node_element(const int& tree_node_element)
{
    std::cout << tree_node_element << std::endl;
}

TEST_F(GTester4BinarySearchTree, CheckInsertElements)
{
    bstree.insert(4);
    bstree.insert(8);

    EXPECT_EQ(bstree.treeHeight(), 1);
}

TEST_F(GTester4BinarySearchTree, CheckFindMinMaxElements)
{
    bstree.insert(0);
    bstree.insert(9);
    bstree.insert(3);
    bstree.insert(8);
    bstree.insert(-5);
    bstree.insert(1);
    bstree.insert(12);

    EXPECT_EQ(bstree.treeHeight(), 3);

    auto minimal_element = bstree.findMin();
    auto maximal_element = bstree.findMax();

    EXPECT_EQ(minimal_element, -5);
    EXPECT_EQ(maximal_element, 12);

    bstree.postOrderTraversal(print_tree_node_element);
}

TEST_F(GTester4BinarySearchTree, CheckWhetherTreeIsEmpty)
{
    bstree.insert(3);
    bstree.insert(9);
    bstree.insert(-5);
    bstree.insert(8);
    bstree.insert(2);
    bstree.insert(-10);
    bstree.insert(7);
    bstree.insert(20);

    EXPECT_EQ(bstree.isEmpty(), false);

    EXPECT_EQ(bstree.contains(8), true);
    EXPECT_EQ(bstree.contains(10), false);

    bstree.preOrderTraversal(print_tree_node_element);

    bstree.makeEmpty();
    EXPECT_EQ(bstree.isEmpty(), true);
}

TEST_F(GTester4BinarySearchTree, CheckRemoveItemsFromTree)
{
    bstree.insert(9);
    bstree.insert(3);
    bstree.insert(-1);
    bstree.insert(8);
    bstree.insert(12);
    bstree.insert(-12);
    bstree.insert(4);

    EXPECT_EQ(bstree.treeHeight(), 3);

    bstree.remove(12);
    EXPECT_EQ(bstree.contains(12), false);
    EXPECT_EQ(bstree.treeHeight(), 3);

    bstree.insert(2);
    bstree.insert(7);
    bstree.insert(6);
    bstree.insert(1);
    bstree.insert(0);
    EXPECT_EQ(bstree.treeHeight(), 5);

    bstree.remove(-1);
    bstree.remove(8);
    EXPECT_EQ(bstree.treeHeight(), 4);

    bstree.inOrderTraversal(print_tree_node_element);
}
