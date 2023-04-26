/*!
 *  \file       AVL_Tree_impl.hpp
 *  \brief      Implement the AVLTree<ElemType> class template.
 *  \author     Frederique Hsu (frederique.hsu@outlook.com)
 *  \date       Sun.    23 Apr. 2023
 *
 */


#include <utility>
#include <algorithm>

/* Implementation ================================================================================*/
/*!
 *  \brief      获取AVL树中任一节点的高度
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      tree_node - AVL树中某一个节点
 *  \return     节点的高度， 空节点高度为-1, 叶子节点高度为0
 */
template<typename ElemType>
int AVLTree<ElemType>::height(AVLTree<ElemType>::AvlTreeNode* tree_node) const
{
    return (tree_node == nullptr) ? -1 : tree_node->height;
}

/*!
 *  \brief      AvlTreeNode构造函数
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      elem - AVL树根节点的元素
 *  \param      left_node - AVL树根节点的左子树
 *  \param      right_node - AVL树根节点的右子树
 *  \param      hgt - 节点的高度，空树的高度为-1, 叶子节点的高度为0，当只有一个根节点，其实也是叶子节点，高度为0.
 */
template<typename ElemType>
AVLTree<ElemType>::AvlTreeNode::AvlTreeNode(const ElemType& elem,
                                            AVLTree<ElemType>::AvlTreeNode* left_node,
                                            AVLTree<ElemType>::AvlTreeNode* right_node,
                                            int hgt)
    : element{elem}, left{left_node}, right{right_node}, height{hgt}
{
}

/*!
 *  \brief      AvlTreeNode移动构造函数
 */
template<typename ElemType>
AVLTree<ElemType>::AvlTreeNode::AvlTreeNode(ElemType&& elem,
                                            AVLTree<ElemType>::AvlTreeNode* left_node,
                                            AVLTree<ElemType>::AvlTreeNode* right_node,
                                            int hgt)
    : element(std::move(elem)), left(left_node), right(right_node), height(hgt)
{
}

/*!
 *  \brief      AVLTree构造函数
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      element - 构造AVLTree时根节点的元素
 */
template<typename ElemType>
AVLTree<ElemType>::AVLTree(const ElemType& element)
    : root{new AVLTree<ElemType>::AvlTreeNode(element, nullptr, nullptr, 0)}
{
}

/*!
 *  \brief      AVLTree析构函数
 */
template<typename ElemType>
AVLTree<ElemType>::~AVLTree()
{
    makeEmpty();
}

/*!
 *  \brief      更新AVLTree的节点的高度
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      tree_node - AVL树的节点
 *  \note       节点的高度等于最高子树的高度 + 1
 */
template<typename ElemType>
void AVLTree<ElemType>::updateHeight(AVLTree<ElemType>::AvlTreeNode* tree_node)
{
    tree_node->height = std::max(height(tree_node->left), height(tree_node->right)) + 1;
}


/*!
 *  \brief      获取AVL树中任一节点的平衡因子
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      tree_node - AVL树中的任一节点
 *  \return     返回tree_node对应的平衡因子
 */
template<typename ElemType>
int AVLTree<ElemType>::balanceFactor(AVLTree<ElemType>::AvlTreeNode* tree_node) const
{
    if (tree_node == nullptr)   /* 空节点平衡因子为0 */
        return 0;
    /* 节点平衡因子 = 左子树高度 - 右子树高度 */
    return height(tree_node->left) - height(tree_node->right);
}

/*!
 *  \brief      向右旋转，以平衡AVL树
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      tree_node - 失衡的子树的根节点，亦即标记为node的节点
 *  \return     返回右旋后子树的根节点
 */
template<typename ElemType>
typename AVLTree<ElemType>::AvlTreeNode* AVLTree<ElemType>::rightRotate(AVLTree<ElemType>::AvlTreeNode* tree_node)
{
    AvlTreeNode* child = tree_node->left;       /* 将左子节点标记为child */
    AvlTreeNode* grandchild = child->right;     /* 如果child节点本身存在右子节点，则标记为grandchild */
    /* 以child为原点， 将tree_node向右旋转 */
    child->right = tree_node;
    tree_node->left = grandchild;       /* 将grandchild节点修改为它tree_node的左子节点 */
    /* 更新节点高度 */
    updateHeight(tree_node);
    updateHeight(child);
    return child;       /* 返回旋转后子树的根节点 */
}

/*!
 *  \brief      向左旋转，以平衡AVL树
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      tree_node - 失衡的子树的根节点，标记为node节点
 *  \return     返回左旋后子树的根节点
 */
template<typename ElemType>
typename AVLTree<ElemType>::AvlTreeNode* AVLTree<ElemType>::leftRotate(AVLTree<ElemType>::AvlTreeNode* tree_node)
{
    AvlTreeNode* child = tree_node->right;      /* 将右子节点标记为child */
    AvlTreeNode* grandchild = child->left;      /* 如果child节点存在左子节点，则标记为grandchild */
    /* 以child为原点，将tree_node向左旋转 */
    child->left = tree_node;
    tree_node->right = grandchild;      /* 将grandchild节点修改为tree_node的右子节点 */
    /* 更新节点的高度 */
    updateHeight(tree_node);
    updateHeight(child);
    return child;       /* 返回左旋后的子树的根节点 */
}

/*!
 *  \brief      执行旋转操作，使当前子树重新恢复平衡
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      tree_node - 失衡子树的根节点
 *  \return     返回旋转后的子树的根节点
 */
template<typename ElemType>
typename AVLTree<ElemType>::AvlTreeNode* AVLTree<ElemType>::rotate(AVLTree<ElemType>::AvlTreeNode* tree_node)
{
    int balance_factor = balanceFactor(tree_node);
    if (balance_factor > 1)     /* 左偏树 */
    {
        if (balanceFactor(tree_node->left) >= 0)
            return rightRotate(tree_node);      /* 右旋 */
        else
        {
            tree_node->left = leftRotate(tree_node->left);      /* 先左旋 */
            return rightRotate(tree_node);                      /* 后右旋 */
        }
    }
    else if (balance_factor < -1)   /* 右偏树 */
    {
        if (balanceFactor(tree_node->right) <= 0)
            return leftRotate(tree_node);       /* 左旋 */
        else
        {
            tree_node->right = rightRotate(tree_node->right);   /* 先右旋 */
            return leftRotate(tree_node);                       /* 后左旋 */
        }
    }
    else    /* 平衡树 */
    {
        return tree_node;   /* 无需旋转，直接返回 */
    }
}

/*!
 *  \brief      递归插入新的节点
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      tree_node - 子树的根节点
 *  \param      elem - 用户欲插入的节点的元素
 *  \return     返回完成插入新节点，并恢复平衡的子树根节点
 */
template<typename ElemType>
typename AVLTree<ElemType>::AvlTreeNode* AVLTree<ElemType>::insert(AVLTree<ElemType>::AvlTreeNode* tree_node,
                                                                   const ElemType& elem)
{
    if (tree_node == nullptr)   // 空树
    {
        return new AvlTreeNode(elem, nullptr, nullptr);
    }
    if (elem < tree_node->element)
    {   // 插入左子树
        tree_node->left = insert(tree_node->left, elem);
    }
    else if (tree_node->element < elem)
    {   // 插入右子树
        tree_node->right = insert(tree_node->right, elem);
    }
    else    /* tree_node->element == elem */
    {
        return tree_node;       // 重复元素，不插入，直接返回
    }
    updateHeight(tree_node);    // 更新节点的高度
    tree_node = rotate(tree_node);      // 执行旋转操作，使该子树重新恢复平衡
    return tree_node;       // 返回子树的根节点
}

/*!
 *  \brief      插入新节点
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      elem - 用户欲插入的新节点的元素
 */
template<typename ElemType>
void AVLTree<ElemType>::insert(const ElemType& elem)
{
    root = insert(root, elem);
}

/*!
 *  \brief      从AVL树中移除用户指定的元素
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      tree_node - AVL树的根节点
 *  \param      elem - 用户指定的欲删除的元素
 *  \return     返回删除后的子树的根节点
 */
template<typename ElemType>
typename AVLTree<ElemType>::AvlTreeNode* AVLTree<ElemType>::remove(AVLTree<ElemType>::AvlTreeNode* tree_node,
                                                                   const ElemType& elem)
{
    if (tree_node == nullptr)
        return nullptr;
    if (elem < tree_node->element)
    {
        tree_node->left = remove(tree_node->left, elem);
    }
    else if (tree_node->element < elem)
    {
        tree_node->right = remove(tree_node->right, elem);
    }
    else    /* tree_node->element == elem */
    {
        if  ((tree_node->left != nullptr) && (tree_node->right != nullptr))     // 有2个子树
        {   // 从右子树中找到最小元素，用来代替当前欲删除的节点的元素
            tree_node->element = findMin(tree_node->right)->element;
            // 转而去删除右子树中最小元素的节点
            tree_node->right = remove(tree_node->right, tree_node->element);
        }
        else if ((tree_node->left == nullptr) && (tree_node->right == nullptr))     // 没有子节点
        {
            delete tree_node;   // 直接删除该节点
            return nullptr;
        }
        else    // 有一个子节点
        {
            AvlTreeNode* child = (tree_node->left != nullptr) ? tree_node->left : tree_node->right;
            delete tree_node;   // 直接删除该节点
            tree_node = child;  // 用子节点替代被删除的节点
        }
    }
    updateHeight(tree_node);    // 删除节点后更新高度
    tree_node = rotate(tree_node);  // 执行旋转操作，恢复平衡
    return tree_node;
}

/*!
 *  \brief      从AVL树中移除用户指定的元素elem
 */
template<typename ElemType>
void AVLTree<ElemType>::remove(const ElemType& elem)
{
    remove(root, elem);
}

/*!
 *  \brief      从AVL树中找到最小的元素
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      tree_node - AVL任一子树的根节点
 *  \return     返回最小元素所在的节点
 */
template<typename ElemType>
typename AVLTree<ElemType>::AvlTreeNode* AVLTree<ElemType>::findMin(AVLTree<ElemType>::AvlTreeNode* tree_node) const
{
    if (tree_node != nullptr)
    {
        while (tree_node->left != nullptr)
        {
            tree_node = tree_node->left;
        }
    }
    return tree_node;
}

/*!
 *  \brief      从AVL树中返回最小的元素
 */
template<typename ElemType>
const ElemType& AVLTree<ElemType>::findMinElement() const
{
    return findMin(root)->element;
}

/*!
 *  \brief      从AVL树中找到最大的元素，返回最大元素所在的节点。
 */
template<typename ElemType>
typename AVLTree<ElemType>::AvlTreeNode* AVLTree<ElemType>::findMax(AVLTree<ElemType>::AvlTreeNode* tree_node) const
{
    if (tree_node->right != nullptr)
    {
        return findMax(tree_node->right);
    }
    return tree_node;
}

/*!
 *  \brief      从AVL树中返回最大的元素
 */
template<typename ElemType>
const ElemType& AVLTree<ElemType>::findMaxElement() const
{
    return findMax(root)->element;
}

/*!
 *  \brief      从AVL树中找到用户指定的元素
 *  \tparam     ElemType - AVL树中存储元素的数据类型
 *  \param      elem - 用户指定的欲查找的元素
 *  \param      tree_node - AVL任一子树的根节点
 *  \return     找到返回true, 没找到则返回false
 */
template<typename ElemType>
bool AVLTree<ElemType>::contains(const ElemType& elem, AVLTree<ElemType>::AvlTreeNode* tree_node) const
{
    if (tree_node == nullptr)
        return false;
    if (elem < tree_node->element)
    {
        return contains(elem, tree_node->left);
    }
    else if (tree_node->element < elem)
    {
        return contains(elem, tree_node->right);
    }
    else    /* elem == tree_node->element */
    {
        return true;
    }
}

/*!
 *  \brief      从AVL树中找到用户指定的elem元素，找到就返回true, 否则返回false
 */
template<typename ElemType>
bool AVLTree<ElemType>::contains(const ElemType& elem) const
{
    return contains(elem, root);
}

/*!
 *  \brief      清空AVL树的某一个子树
 *  \param      tree_node - AVL树的任一子树的根节点
 */
template<typename ElemType>
void AVLTree<ElemType>::makeEmpty(AVLTree<ElemType>::AvlTreeNode* tree_node)
{
    if (tree_node != nullptr)
    {
        makeEmpty(tree_node->left);
        makeEmpty(tree_node->right);
        delete tree_node;
    }
    tree_node = nullptr;
}

/*!
 *  \brief      清空整个AVL树
 */
template<typename ElemType>
void AVLTree<ElemType>::makeEmpty()
{
    makeEmpty(root);
}


template<typename ElemType>
typename AVLTree<ElemType>::AvlTreeNode* AVLTree<ElemType>::clone(AVLTree<ElemType>::AvlTreeNode* tree_node) const
{
    if (tree_node == nullptr)
        return nullptr;
    else
    {
        return new AvlTreeNode(tree_node->element, clone(tree_node->left), clone(tree_node->right));
    }
}
