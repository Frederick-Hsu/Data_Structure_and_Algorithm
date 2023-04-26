/*!
 *  \file       AVL_Tree.hpp
 *  \brief      Learn and study the structure of Adelson-Velskii-Landis tree.
 *  \author     Frederique Hsu (frederique.hsu@outlook.com)
 *  \date       Sat.    22 Apr. 2022
 *
 */


#pragma once


/*!
 *  \remark     Adelson-Velskii-Landis Tree
 *              一颗AVL树是其每个节点的左子树和右子树的高度最多相差1的二叉搜索树.
 *  \note       空树的高度定义为-1, 只有根节点的树，高度为0.
 */


/* Declaration ===================================================================================*/
/*!
 *  \class      AVLTree<ElemType>
 *  \brief      定义Adelson_Velskii_Landis树的类模板
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 */
template<typename ElemType>
class AVLTree
{
private:
    struct AvlTreeNode
    {
        ElemType        element;
        AvlTreeNode*    left;
        AvlTreeNode*    right;
        int             height;

        AvlTreeNode(const ElemType& elem,
                    AvlTreeNode* left_node,
                    AvlTreeNode* right_node,
                    int hgt = 0);
        AvlTreeNode(ElemType&& elem, AvlTreeNode* left_node, AvlTreeNode* right_node, int hgt = 0);
    };

    AvlTreeNode* root;
public:
    explicit AVLTree(const ElemType& element);
    AVLTree(const AVLTree& rhs) = delete;
    AVLTree& operator=(const AVLTree& rhs) = delete;
    AVLTree(AVLTree&& rhs) = delete;
    AVLTree& operator=(AVLTree&& rhs) = delete;
    virtual ~AVLTree();
public:
    void insert(const ElemType& elem);
    void remove(const ElemType& elem);
    const ElemType& findMinElement() const;
    const ElemType& findMaxElement() const;
    void makeEmpty();
    bool contains(const ElemType& elem) const;
private:
    int height(AvlTreeNode* tree_node) const;
    void updateHeight(AvlTreeNode* tree_node);
    int balanceFactor(AvlTreeNode* tree_node) const;
    AvlTreeNode* rightRotate(AvlTreeNode* tree_node);
    AvlTreeNode* leftRotate(AvlTreeNode* tree_node);
    AvlTreeNode* rotate(AvlTreeNode* tree_node);
    AvlTreeNode* insert(AvlTreeNode* tree_node, const ElemType& elem);
    AvlTreeNode* remove(AvlTreeNode* tree_node, const ElemType& elem);
    AvlTreeNode* findMin(AvlTreeNode* tree_node) const;
    AvlTreeNode* findMax(AvlTreeNode* tree_node) const;
    bool contains(const ElemType& elem, AvlTreeNode* tree_node) const;
    void makeEmpty(AvlTreeNode* tree_node);
    AvlTreeNode* clone(AvlTreeNode* tree_node) const;
};


#include "AVL_Tree_impl.hpp"
