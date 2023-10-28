/*!
 *  \file       B_tree.hpp
 *  \brief
 *
 */



#pragma once

/*!
 *  \note   阶为M的B树 B-tree 是一棵具有下列特性的 M叉树：  M-ary search tree
 *
 *  \list
 *  \li     1. 数据项存储在树叶上
 *  \li     2. 非叶子节点存储直到 M - 1 个关键字以指示搜索的方向： 关键字 i 代表子树 i + 1 种的最小的关键字
 *  \li     3. 树的根或者是一片叶子，或者其儿子数在 2 和 M 之间
 *  \li     4. 除根外，所有非叶子节点的儿子数在 [M/2] 和 M 之间。
 *  \li     5. 所有的树叶都在相同的深度上，并且每片树叶拥有的数据项其个数在 [L/2] 和 L 之间。
 *  \endlist
 */


/* Declaration ===================================================================================*/
template<typename ElemType> class BTree
{
public:
    BTree();
private:
    struct BTreeNode
    {
        ElemType     *data;
        BTreeNode   **child_ptr;
        bool          leaf;
        int           n;
    };

    BTreeNode* root;
    BTreeNode* node_ptr;
    BTreeNode* x;
private:
    BTreeNode* initialize();
};


/* Implementation ================================================================================*/
template<typename ElemType>
typename BTree<ElemType>::BTreeNode* BTree<ElemType>::initialize()
{
    node_ptr = new BTreeNode;
    node_ptr->data = new ElemType[5];     // 5叉搜索树
    node_ptr->child_ptr = new BTreeNode *[6];
    node_ptr->leaf = true;

}
