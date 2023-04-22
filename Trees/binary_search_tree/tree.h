/*!
 *  \file       tree.h
 *  \brief      Define the structure of binary search tree.
 *
 */


#pragma once


#ifdef __cplusplus
extern "C"
{
#endif

    #include "element.h"

    struct TreeNode;
    typedef struct TreeNode     *Position;
    typedef struct TreeNode     *SearchTree;

    SearchTree MakeEmpty(SearchTree tree);
    Position Find(ElementType elem, SearchTree tree);
    Position FindMin(SearchTree tree);
    Position FindMax(SearchTree tree);
    SearchTree Insert(ElementType elem, SearchTree tree);
    SearchTree Delete(ElementType elem, SearchTree tree);
    ElementType Retrieve(Position position);

    /* Specific definition ===========================================================================*/
    struct TreeNode
    {
        ElementType     element;
        SearchTree      left;
        SearchTree      right;
    };

#ifdef __cplusplus
}
#endif
