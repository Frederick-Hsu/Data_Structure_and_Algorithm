/* File name    : binary_search_tree.h
 * Description  : Define and implement the generic binary search tree.
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

    #include <queue>
    #include <stack>
    #include <iostream>
    #include <iomanip>
    #include <cstdio>
    using namespace std;

    template<class ElemType> class Stack;
    template<class ElemType> class Queue;
    template<class ElemType> class BSTNode;
    template<class ElemType> class BST;

    template<class ElemType> class Stack : public stack<ElemType>
    {
    public:
        ElemType pop();
        void push(const ElemType& element);
    };

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
        void iterativePostorder();
        void iterativeInorder();
    protected:
        void clear(BSTNode<ElemType>*);
        ElemType* search(BSTNode<ElemType>*, const ElemType&) const;
        void preorder(BSTNode<ElemType>*);
        void inorder(BSTNode<ElemType>*);
        void postorder(BSTNode<ElemType>*);
        virtual void visit(BSTNode<ElemType>* p);
    };

/*===============================================================================================*/

    template<class ElemType> ElemType Stack<ElemType>::pop()
    {
        ElemType element = stack<ElemType>::top();
        stack<ElemType>::pop();
        return element;
    }

    template<class ElemType> void Stack<ElemType>::push(const ElemType& element)
    {
        stack<ElemType>::push(element);
    }

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

    template<class ElemType> BST<ElemType>::~BST()
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
        cout << " 0x" << setfill('0') << uppercase << hex << setw(16) << p << "  | "
             << right << setw(16) << dec << p->element << "  |"
             << " 0x" << setfill('0') << uppercase << hex << setw(16) << p->left << "  |"
             << " 0x" << setfill('0') << uppercase << hex << setw(16) << p->right << endl;
        cout << "---------------------+-------------------+---------------------+-----------------------" << endl;
        cout << nouppercase << dec;
    }

    template<class ElemType> void BST<ElemType>::inorder(BSTNode<ElemType>* p)
    {
        if (p != nullptr)
        {
            inorder(p->left);
            visit(p);
            inorder(p->right);
        }
    }

    template<class ElemType> void BST<ElemType>::preorder(BSTNode<ElemType>* p)
    {
        if (p != nullptr)
        {
            visit(p);
            preorder(p->left);
            preorder(p->right);
        }
    }

    template<class ElemType> void BST<ElemType>::postorder(BSTNode<ElemType>* p)
    {
        if (p != nullptr)
        {
            postorder(p->left);
            postorder(p->right);
            visit(p);
        }
    }

    template<class ElemType> void BST<ElemType>::inorder()
    {
        inorder(root);
    }

    template<class ElemType> void BST<ElemType>::preorder()
    {
        preorder(root);
    }

    template<class ElemType> void BST<ElemType>::postorder()
    {
        postorder(root);
    }

    template<class ElemType> void BST<ElemType>::iterativePreorder()
    {
        Stack<BSTNode<ElemType>*> travStack;
        BSTNode<ElemType> *p = root;
        if (p != nullptr)
        {
            travStack.push(p);
            while (!travStack.empty())
            {
                p = travStack.pop();
                visit(p);
                if (p->right != nullptr)
                {
                    travStack.push(p->right);
                }
                if (p->left != nullptr)     /* left-child should be pushed after right-child */
                {
                    travStack.push(p->left);
                }

            }
        }
    }

    template<class ElemType> void BST<ElemType>::iterativePostorder()
    {
        Stack<BSTNode<ElemType>*> travStack;
        BSTNode<ElemType> *p = root, *q = root;     /* q node as an auxiliary */
        while (p != nullptr)
        {
            for (; p->left != nullptr; p = p->left)
            {
                travStack.push(p);
            }
            while ((p->left == nullptr) || (p->right == q))
            {
                visit(p);
                q = p;
                if (travStack.empty())
                {
                    return;
                }
                p = travStack.pop();
            }
            travStack.push(p);
            p = p->right;
        }
    }

    template<class ElemType> void BST<ElemType>::iterativeInorder()
    {
        Stack<BSTNode<ElemType>*> travStack;
        BSTNode<ElemType>* p = root;
        while (p != nullptr)
        {
            while (p != nullptr)    /* stack the right-child (if any) */
            {
                if (p->right)       /* and the node itsel when going to the left */
                    travStack.push(p->right);
                travStack.push(p);
                p = p->left;
            }
            p = travStack.pop();    /* pop a node with no left-child visit it */
            while (!travStack.empty() && p->right == nullptr)
            {
                visit(p);
                p = travStack.pop();    /* and all nodes with no right-child */
            }
            visit(p);                   /* visit also the first node with a right-child (if any) */
            if (!travStack.empty())
            {
                p = travStack.pop();
            }
            else
            {
                p = nullptr;
            }
        }
    }

#endif  /* BINARY_SEARCH_TREE_H */
