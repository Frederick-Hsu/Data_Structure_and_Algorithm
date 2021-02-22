#include "AVL_Tree.h"
#include "misc.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct AVLNode
{
    ElemType Element;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

static Position SingleRotateWithLeft(Position k2);
static Position SingleRotateWithRight(Position k2);
static Position DoubleRotateWithLeft(Position k3);
static Position DoubleRotateWithRight(Position k3);

static int Height(Position pos)
{
    if (pos == NULL)
    {
        return -1;
    }
    else
    {
        return pos->Height;
    }
}

AVLTree Insert(ElemType elem, AVLTree tree)
{
    if (tree == NULL)
    {
        /* Create and return a one-node tree */
        tree = (AVLTree)malloc(sizeof(struct AVLNode));
        assert(tree != NULL);
        tree->Element = elem;
        tree->Height = 0;
        tree->Left = NULL;
        tree->Right = NULL;
    }
    else if (elem < tree->Element)
    {
        tree->Left = Insert(elem, tree->Left);
        if (Height(tree->Left) - Height(tree->Right) == 2)
        {
            if (elem < tree->Left->Element)
                tree = SingleRotateWithLeft(tree);
            else
                tree = DoubleRotateWithLeft(tree);
        }
    }
    else if (elem > tree->Element)
    {
        tree->Right = Insert(elem, tree->Right);
        if (Height(tree->Right) - Height(tree->Left) == 2)
        {
            if (elem > tree->Right->Element)
                tree = SingleRotateWithRight(tree);
            else
                tree = DoubleRotateWithRight(tree);
        }
    }
    else
    {
        /* elem is already in the tree, we will do nothing. */
    }
    tree->Height = Max(Height(tree->Left), Height(tree->Right)) + 1;
    return tree;
}

Position SingleRotateWithLeft(Position k2)      /* 左子树单旋转 */
/* This function can be called only if k2 has a left child.
 * Perform a rotate between a node(k2) and its left child.
 * update heights, then return new root. 
 */
{
    Position k1 = k2->Left;
    k2->Left = k1->Right;
    k1->Right = k2;

    k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
    k1->Height = Max(Height(k1->Left), k2->Height) + 1;
    
    return k1;
}

Position SingleRotateWithRight(Position k2)		/* 右子树单旋转 */
/* This function can be called only if k2 has a right child-tree,
 * Perform a rotate between the node(k2) and its right child-tree
 * update the heights, then return the new root.
 */
{
    Position k1 = k2->Right;
    k2->Right = k1->Left;
    k1->Left = k2;

    k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
    k1->Height = Max(k2->Height, Height(k1->Right)) + 1;

    return k1;
}

Position DoubleRotateWithLeft(Position k3)      /* 左子树双旋转 */
/* This function can be called only if k3 has a left child-tree, 
 * and k3's left child-tree has a right child-tree.
 * Do the right-left double rotation.
 * updates the heights, then return new root.
 */
{
    /* Rotate between k1 and k2 */
    k3->Left = SingleRotateWithRight(k3->Left);

    /* Rotate between k3 and k2 */
    return SingleRotateWithLeft(k3);
}

Position DoubleRotateWithRight(Position k3)     /* 右子树双旋转 */
/* This function can be called only if k3 has a right child-tree,
 * and k3's left child-tree has a left child-tree.
 * Do the left-right double rotation.
 * updates the heights, then return the new root.
 */
{
    /* Rotate between k1 and k2 */
    k3->Right = SingleRotateWithLeft(k3->Right);

    /* Rotate between k3 and k2 */
    return SingleRotateWithRight(k3);
}
