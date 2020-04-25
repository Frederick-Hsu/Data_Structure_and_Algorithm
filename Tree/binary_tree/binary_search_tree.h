/* File name    : binary_search_tree.h
 * Description  : Define and implement the generic binary search tree.
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

    #include <queue>
    #include <iostream>
    #include <cstdio>
    using namespace std;

    template<class ElemType> class Queue;
    template<class ElemType> class BSTNode;
    template<class ElemType> class BST;

    template<class ElemType> class Queue : queue<ElemType>
    {
    public:
        ElemType dequeue();
        void enqueue(const ElemType& element);
    };

    template<class ElemType> class BSTNode  /* The node of binary search tree */
    {
    public:
        BSTNode();
        BSTNode(const ElemType& elem, BSTNode<ElemType>* l, BSTNode<ElemType>* r);
    public:
        ElemType element;
        BSTNode<ElemType>* left;
        BSTNode<ElemType>* right;
    };

    template<class ElemType> class BST  /* Binary search tree */
    {
    protected:
        BSTNode<ElemType>* root;
    public:
        BST();
        virtual ~BST();
    public:
        void clear();
        bool isEmpty();
        void preorder();
        void inorder();
        void postorder();
        ElemType* search(const ElemType& elem) const;
        void breadthFirst();
        void iterativePreorder();
    protected:
        void clear(BSTNode<ElemType>*);
        ElemType* search(BSTNode<ElemType>*, const ElemType&) const;
        void preorder(BSTNode<ElemType>*);
        void inorder(BSTNode<ElemType>*);
        void postorder(BSTNode<ElemType>*);
        virtual void visit(BSTNode<ElemType>* p);
    };

/*===============================================================================================*/

    template<class ElemType> ElemType Queue<ElemType>::dequeue()
    {
        ElemType tmp = queue<ElemType>::front();
        queue<ElemType>::pop();
        return tmp;
    }

    template<class ElemType> void Queue<ElemType>::enqueue(const ElemType& element)
    {
        queue<ElemType>::push(element);
    }

    template<class ElemType> BSTNode<ElemType>::BSTNode()
    {
        left = 0;
        right = 0;
    }

    template<class ElemType> BSTNode<ElemType>::BSTNode(const ElemType& elem,
                                                        BSTNode<ElemType>* l,
                                                        BSTNode<ElemType>* r)
    {
        element = elem;
        left = l;
        right = r;
    }

    template<class ElemType> BST<ElemType>::BST()
    {
        root = 0;
    }

    template<class ElemType> BST<ElemType>::~BST<ElemType>()
    {
        clear();
    }

    template<class ElemType> void BST<ElemType>::clear()
    {
        clear(root);
        root = 0;
    }

    template<class ElemType> ElemType* BST<ElemType>::search(BSTNode<ElemType>* p, const ElemType& elem) const
    {
        while (p != 0)
        {
            if (elem == p->element)
                return &(p->element);
            else if (elem < p->element)
                p = p->left;
            else    /* elem > p->element */
                p = p->right;
        }
        return 0;
    }

    template<class ElemType> ElemType* BST<ElemType>::search(const ElemType& elem) const
    {
        return search(root, elem);
    }

    template<class ElemType> void BST<ElemType>::breadthFirst()
    {
        Queue<BSTNode<ElemType>*> node_queue;
        BSTNode<ElemType>* p = root;
        if (p != nullptr)
        {
            node_queue.enqueue(p);
            while (!node_queue.empty())
            {
                p = node_queue.dequeue();
                visit(p);
                if (p->left != nullptr)
                {
                    node_queue.enqueue(p->left);
                }
                if (p->right != nullptr)
                {
                    node_queue.enqueue(p->right);
                }
            }
        }
    }

    template<class ElemType> void BST<ElemType>::visit(BSTNode<ElemType>* p)
    {
        printf(" 0x%0016X    | %")
    }
#endif  /* BINARY_SEARCH_TREE_H */
