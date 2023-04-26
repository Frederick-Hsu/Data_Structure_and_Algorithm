/*!
 *  \file       binary_search_tree.hpp
 *  \brief      Define the structure of binary-search-tree in C++.
 *
 */


#pragma once


#include <iostream>
#include <algorithm>


#define WITHOUT_COMPARATOR      1
#define WITH_COMPARATOR         2
#define DEFINITION_METHOD       WITHOUT_COMPARATOR

/* Declaration ===================================================================================*/

/*!
 *  \class      BinarySearchTree<ElemType>
 *  \brief      二叉搜索树
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 */
#if (DEFINITION_METHOD == WITHOUT_COMPARATOR)
    template<typename ElemType>
#elif (DEFINITION_METHOD == WITH_COMPARATOR)
    template<typename ElemType, typename Comparator = std::less<ElemType>>
#endif
    class BinarySearchTree
    {
    public:
        explicit BinarySearchTree(const ElemType& elem);
        BinarySearchTree(const BinarySearchTree& rhs);
        BinarySearchTree(BinarySearchTree&& rhs);
        BinarySearchTree& operator=(const BinarySearchTree& rhs);
        BinarySearchTree& operator=(BinarySearchTree&& rhs);
        ~BinarySearchTree();
    public:
        const ElemType& findMin() const;
        const ElemType& findMax() const;
        bool contains(const ElemType& elem) const;
        bool isEmpty() const;
        void printTree(std::ostream& out = std::cout) const;
        void makeEmpty();
        void insert(const ElemType& elem);
        void insert(ElemType&& elem);
        void remove(const ElemType& elem);
    private:
        struct BinaryNode
        {
            ElemType element;
            BinaryNode *left;
            BinaryNode* right;

            BinaryNode(const ElemType& elem);
            BinaryNode(const ElemType& elem, BinaryNode* left_node, BinaryNode* right_node);
            BinaryNode(ElemType&& elem, BinaryNode* left_node, BinaryNode* right_node);
        };

        BinaryNode* root;
#if (DEFINITION_METHOD == WITH_COMPARATOR)
        Comparator isLessThan;
#endif
    private:
        void insert(const ElemType& elem, BinaryNode*& tree);
        void insert(ElemType&& elem, BinaryNode*& tree);
        void remove(const ElemType& elem, BinaryNode*& tree);
        BinaryNode* findMin(BinaryNode* tree) const;
        BinaryNode* findMax(BinaryNode* tree) const;
        bool contains(const ElemType& elem, BinaryNode* tree) const;
        void makeEmpty(BinaryNode*& tree);
        void printTree(BinaryNode* tree, std::ostream& out) const;
        BinaryNode* clone(BinaryNode* tree) const;
    };


#include "binary_serach_tree_impl.hpp"
