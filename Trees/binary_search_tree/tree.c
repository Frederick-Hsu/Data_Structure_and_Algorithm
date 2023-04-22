/*!
 *  \file       tree.c
 *  \brief      Implement the binary search tree.
 *
 */


#include "tree.h"

#include <stdlib.h>
#include <stdio.h>

/*!
 *  \brief          建立一颗空树
 *  \param[in, out] tree - 一颗树的根
 *  \return         NULL - 一颗空树
 */
SearchTree MakeEmpty(SearchTree tree)
{
    if (tree != NULL)
    {
        MakeEmpty(tree->left);
        MakeEmpty(tree->right);
        free(tree);
        tree = NULL;
    }
    return NULL;
}

/*!
 *  \brief      Find a specific element from a tree
 *  \param[in]  elem - user-specified element
 *  \param[in]  tree - a binary search tree, pointer to the root node.
 *  \return     the pointer to the tree node whose element is identical to the elem.
 *  \note
 */
Position Find(ElementType elem, SearchTree tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (elem < tree->element)
    {
        Find(elem, tree->left);
    }
    else if (tree->element < elem)
    {
        Find(elem, tree->right);
    }
    else    /* elem == tree->element */
    {
        return tree;
    }
}

/*!
 *  \brief      对二叉搜索树的FindMin的递归实现
 *  \param      tree - the binary search tree, pointer to the root node.
 *  \return     the position (aka the pointer) of minimal element
 */
Position FindMin(SearchTree tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    else if (tree->left == NULL)
    {
        return tree;
    }
    else
    {
        return FindMin(tree->left);
    }
}

/*!
 *  \brief      对二叉搜索树的FindMax的非递归实现
 *  \param      tree - the binary search tree, pointer to the root node
 *  \return     最大的元素所在的位置，亦即最右边的叶子节点。
 */
Position FindMax(SearchTree tree)
{
    if (tree != NULL)
    {
        while (tree->right != NULL)
        {
            tree = tree->right;
        }
    }
    return tree;
}

SearchTree Insert(ElementType elem, SearchTree tree)
{
    if (tree == NULL)
    {
        tree = (SearchTree)malloc(sizeof(struct TreeNode));
        if (tree == NULL)
        {
            fprintf(stderr, "%s", "Allocate memory for tree failed!\n");
            return NULL;
        }
        else
        {
            tree->element = elem;
            tree->left = tree->right = NULL;
        }
    }
    else if (elem < tree->element)
    {
        tree->left = Insert(elem, tree->left);
    }
    else if (tree->element < elem)
    {
        tree->right = Insert(elem, tree->right);
    }
    else    /* elem == tree->element */
    {
        /*!
         *  \note   elem is already in the tree, we will do nothing.
         */
    }
    return tree;    /*!< \warning DO NOT forget this line */
}

SearchTree Delete(ElementType elem, SearchTree tree)
{
    Position temp_node;

    if (tree == NULL)
    {
        fprintf(stderr, "%s", "The binary search tree is empty");
        return NULL;
    }
    else if (elem < tree->element)      /* Go to the left sub-tree */
    {
        tree->left = Delete(elem, tree->left);
    }
    else if (tree->element < elem)      /* Go the the right sub-tree */
    {
        tree->right = Delete(elem, tree->right);
    }
    else if ((tree->left != NULL) && (tree->right != NULL))     /* Found element to be deleted, but have 2 children */
    {
        /* Replace with the smallest element node in the right sub-tree */
        temp_node = FindMin(tree->right);
        tree->element = temp_node->element;
        tree->right = Delete(tree->element, tree->right);
    }
    else    /* One or zero element node found */
    {
        temp_node = tree;
        if (tree->left == NULL)
            tree = tree->right;
        else if (tree->right == NULL)
            tree = tree->left;
        free(temp_node);
    }
    return tree;
}
