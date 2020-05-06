/* File name    : binary_search_threaded_tree.h
 * Description  : generic bianry search threaded tree
 */

#ifndef BINARY_SEARCH_THREADED_TREE_H
#define BINARY_SEARCH_THREADED_TREE_H

    template<class ElemType> class ThreadedTreeNode;
    template<class ElemType> class ThreadedTree;

    template<class ElemType> class ThreadedTreeNode
    {
    public:
        ThreadedTreeNode();
        ThreadedTreeNode(const ElemType& elem, ThreadedTreeNode* l = nullptr, ThreadedTreeNode* r = nullptr);
    public:
        ElemType element;
        ThreadedTreeNode* left;
        ThreadedTreeNode* right;
        unsigned int successor : 1;
    };

    template<class ElemType> class ThreadedTree
    {
    public:
        ThreadedTree();
    public:
        void insert(const ElemType& elem);
        void inorder();
        virtual void visit(ThreadedTreeNode<ElemType>* p);
    protected:
        ThreadedTreeNode<ElemType>* root;
    };

/*================================================================================================*/

    template<class ElemType> ThreadedTreeNode<ElemType>::ThreadedTreeNode()
    {
        left = nullptr;
        right = nullptr;
    }

    template<class ElemType> ThreadedTreeNode<ElemType>::ThreadedTreeNode(const ElemType& elem,
                                                                          ThreadedTreeNode* l,
                                                                          ThreadedTreeNode* r)
    {
        element = elem;
        left = l;
        right = r;
    }

    template<class ElemType> ThreadedTree<ElemType>::ThreadedTree()
    {
        root = nullptr;
    }

    template<class ElemType> void ThreadedTree<ElemType>::inorder()
    {
        ThreadedTreeNode<ElemType> *prev, *p = root;
        if (p != nullptr)                   // process only nonempty trees
        {
            while (p->left != nullptr)      // go to the leftmost node
            {
                p = p->left;
            }
            while (p != nullptr)
            {
                visit(p);
                prev = p;
                p = p->right;                               // go to the right node and
                if (p != nullptr && prev->successor == 0)   //  only if it is a descendant,
                {
                    while (p->left != nullptr)              // go to the leftmost node, otherwise
                    {
                        p = p->left;                        // visit the successor.
                    }
                }
            }
        }
    }

#endif  /* BINARY_SEARCH_THREADED_TREE_H */
