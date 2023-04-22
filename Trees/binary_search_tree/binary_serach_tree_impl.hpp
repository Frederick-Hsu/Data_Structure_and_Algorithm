/*!
 *  \file       binary_search_tree_impl.hpp
 *  \brief      Implement the BinarySearchTree class template.
 *
 */


/* Implementation ================================================================================*/
/*!
 *  \brief      在二叉搜索树中查找元素elem
 *  \tparam     ElemType - 二叉搜索树中存储的元素的类型
 *  \param      elem - 用户指定查找的元素
 *  \return     若找到指定元素则返回true, 否则返回false.
 */
template<typename ElemType>
bool BinarySearchTree<ElemType>::contains(const ElemType& elem) const
{
    return contains(elem, root);
}

/*!
 *  \brief      将元素elem插入到二叉搜索树中，忽略重复元素。
 *  \tparam     ElemType - 二叉搜索树中存储的元素的类型
 *  \param      elem - 用户欲插入到二叉搜索树中的元素
 *  \return     void
 */
template<typename ElemType>
void BinarySearchTree<ElemType>::insert(const ElemType& elem)
{
    insert(elem, root);
}

template<typename ElemType>
void BinarySearchTree<ElemType>::insert(ElemType&& elem)
{
    insert(std::move(elem), root);
}

/*!
 *  \brief      从二叉搜索树中删除元素elem, 如果没有找到elem, 则什么也不做。
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      elem - 用户欲从二叉搜索树中删除的元素
 *  \return     void
 */
template<typename ElemType>
void BinarySearchTree<ElemType>::remove(const ElemType& elem)
{
    remove(elem, root);
}

/*!
 *  \brief      测试某一个元素elem是否在子树上
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      elem - 要查找的元素
 *  \param      tree - 作为二叉搜索树的子树的根节点.
 *  \return     若找到则返回true, 没有就返回false.
 */
#if (DEFINITION_METHOD == WITHOUT_COMPARATOR)
    template<typename ElemType>
    bool BinarySearchTree<ElemType>::contains(const ElemType& elem,
                                              BinarySearchTree<ElemType>::BinaryNode* tree) const
    {
        if (tree == nullptr)
        {
            return false;
        }
        else if (tree->element < elem)
        {
            return contains(elem, tree->right);
        }
        else if (elem < tree->element)
        {
            return contains(elem, tree->left);
        }
        else    /* elem == tree->element */
        {
            return true;
        }
    }
#elif (DEFINITION_METHOD == WITH_COMPARATOR)
    template<typename ElemType, typename Comparator>
    bool BinarySearchTree<ElemElemType, Comparator>::contains(const ElemType& elem,
        BinarySearchTree<ElemType, Comparator>::BinaryNode* tree) const
    {
        if (tree == nullptr)
            return false;
        else if (isLessThan(elem, tree->element))
            return contains(elem, tree->left);
        else if (isLessThan(tree->element, elem))
            return contains(elem, tree->right);
        else    /* elem == tree->element */
            return true;
    }
#endif

/*!
 *  \brief      找到二叉搜索树的最小元素
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \return     返回最小的元素
 */
template<typename ElemType>
const ElemType& BinarySearchTree<ElemType>::findMin() const
{
    return findMin(root)->element;
}

/*!
 *  \brief      找出子树tree种最小项，返回包含最小项的节点。
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      tree - 二叉搜索树的根节点
 *  \return     若找到最小项则返回其所在的节点，若没有则返回nullptr
 */
template<typename ElemType>
typename BinarySearchTree<ElemType>::BinaryNode* BinarySearchTree<ElemType>::findMin(BinarySearchTree<ElemType>::BinaryNode* tree) const
{
    if (tree == nullptr)
        return nullptr;
    if (tree->left == nullptr)
        return tree;
    return findMin(tree->left);
}

/*!
 *  \brief      找到二叉搜索树的最大元素
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \return     返回最大的元素
 */
template<typename ElemType>
const ElemType& BinarySearchTree<ElemType>::findMax() const
{
    return findMax(root)->element;
}

/*!
 *  \brief      找到子树tree上的最大项，返回包含最大项的节点。
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      tree - 二叉搜索树的根节点
 *  \return     返回最小项所在的节点。
 *  \note       这是对二叉搜索树findMax的非递归实现
 */
template<typename ElemType>
typename BinarySearchTree<ElemType>::BinaryNode* BinarySearchTree<ElemType>::findMax(BinarySearchTree<ElemType>::BinaryNode* tree) const
{
    if (tree != nullptr)
    {
        while (tree->right != nullptr)
        {
            tree = tree->right;
        }
    }
    return tree;
}

/*!
 *  \brief      向子树插入元素
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      elem - 将要插入的元素
 *  \param      tree - 子树的根节点
 */
template<typename ElemType>
void BinarySearchTree<ElemType>::insert(const ElemType& elem, BinarySearchTree<ElemType>::BinaryNode*& tree)
{
    if (tree == nullptr)
    {
        tree = new BinaryNode(elem, nullptr, nullptr);
    }
    else if (tree->element < elem)
    {
        insert(elem, tree->right);
    }
    else if (elem < tree->element)
    {
        insert(elem, tree->left);
    }
    else    /* elem == tree->element */
    {
        ;   // 重复元素，则什么也不错。
    }
}

/*!
 *  \brief      向子树插入元素
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      elem - 通过移动实现要插入的元素
 *  \param      tree - 子树的根节点
 */
template<typename ElemType>
void BinarySearchTree<ElemType>::insert(ElemType&& elem, BinarySearchTree<ElemType>::BinaryNode*& tree)
{
    if (tree == nullptr)
    {
        tree = new BinaryNode(std::move(elem), nullptr, nullptr);
    }
    else if (tree->element < elem)
    {
        insert(std::move(elem), tree->right);
    }
    else if (elem < tree->element)
    {
        insert(std::move(elem), tree->left);
    }
    else    /* tree->element == elem */
    {
        ;
    }
}

/*!
 *  \brief      从一颗子树删除指定的元素
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      elem - 用户指定的欲删除的元素
 *  \param[in]  tree - 子树的根节点
 *  \param[out  tree - 置为该子树的新的根节点
 */
template<typename ElemType>
void BinarySearchTree<ElemType>::remove(const ElemType& elem, BinarySearchTree<ElemType>::BinaryNode*& tree)
{
    if (tree == nullptr)
        return;     // 元素没有找到，则什么也不做
    if (tree->element < elem)
    {
        remove(elem, tree->right);
    }
    else if (elem < tree->element)
    {
        remove(elem, tree->left);
    }
    else if ((tree->left != nullptr) && (tree->right != nullptr))   // 有左右两个子树
    {
        BinaryNode* minimal_node = findMin(tree->right);    // 找到右子树的最小项节点
        tree->element = minimal_node->element;      // 将右子树最小项节点的元素替代将要被删除节点的元素
        remove(tree->element, tree->right);
    }
    else
    {
        BinaryNode* old_node = tree;
        tree = (tree->left != nullptr) ? tree->left : tree->right;
        delete old_node;
    }
}

/*!
 *  \brief      二叉搜索树的析构函数
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 */
template<typename ElemType>
BinarySearchTree<ElemType>::~BinarySearchTree()
{
    makeEmpty();
}

/*!
 *  \brief      清空二叉搜索树
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 */
template<typename ElemType>
void BinarySearchTree<ElemType>::makeEmpty()
{
    makeEmpty(root);
}

/*!
 *  \brief      使子树为空，递归删除二叉搜索树的所有节点。
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      tree - 树的根节点
 */
template<typename ElemType>
void BinarySearchTree<ElemType>::makeEmpty(BinarySearchTree<ElemType>::BinaryNode*& tree)
{
    if (tree != nullptr)
    {
        makeEmpty(tree->left);
        makeEmpty(tree->right);
        delete tree;
    }
    tree = nullptr;
}

/*!
 *  \brief      检查二叉搜索树是否为空
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \return     若为空树则返回true, 否则返回false
 */
template<typename ElemType>
bool BinarySearchTree<ElemType>::isEmpty() const
{
    if (root == nullptr)
        return true;
    else
        return false;
}

/*!
 *  \brief      二叉搜索树的拷贝构造函数
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      rhs - 别的二叉搜索树对象
 */
template<typename ElemType>
BinarySearchTree<ElemType>::BinarySearchTree(const BinarySearchTree<ElemType>& rhs) : root{nullptr}
{
    root = clone(rhs.root);
}

/*!
 *  \brief      克隆子树
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      tree - 二叉搜索树的根节点
 *  \return     返回克隆得到的新树的根节点
 */
template<typename ElemType>
typename BinarySearchTree<ElemType>::BinaryNode* BinarySearchTree<ElemType>::clone(BinarySearchTree<ElemType>::BinaryNode* tree) const
{
    if (tree == nullptr)
        return nullptr;
    else
    {
        return new BinaryNode{tree->element, clone(tree->left), clone(tree->right)};
    }
}

/*!
 *  \brief      BinarySearchTree<ElemType>的构造函数
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      elem - 构造出的二叉搜索树根节点的元素
 */
template<typename ElemType>
BinarySearchTree<ElemType>::BinarySearchTree(const ElemType& elem)
    : root(new BinarySearchTree<ElemType>::BinaryNode{elem, nullptr, nullptr})
{
}

/*!
 *  \brief      二叉搜索树内部的二叉节点的构造函数
 *  \tparam     ElemType - 二叉搜索树中存储元素的类型
 *  \param      elem - 二叉节点的根节点的元素
 *  \param      left_node - 二叉节点的左子树
 *  \param      right_node - 二叉节点的右子树
 */
template<typename ElemType>
BinarySearchTree<ElemType>::BinaryNode::BinaryNode(const ElemType& elem,
                                                   BinarySearchTree<ElemType>::BinaryNode* left_node,
                                                   BinarySearchTree<ElemType>::BinaryNode* right_node)
    : element(elem), left(left_node), right(right_node)
{
}

template<typename ElemType>
BinarySearchTree<ElemType>::BinaryNode::BinaryNode(ElemType&& elem,
                                                   BinarySearchTree<ElemType>::BinaryNode* left_node,
                                                   BinarySearchTree<ElemType>::BinaryNode* right_node)
    : element{std::move(elem)}, left{left_node}, right{right_node}
{
}
