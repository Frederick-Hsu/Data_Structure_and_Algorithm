#ifndef AVL_TREE_H
#define AVL_TREE_H

    #include "../user_defines.h"

    struct AVLNode;
    typedef struct AVLNode  *Position;
    typedef struct AVLNode  *AVLTree;

    AVLTree* MakeEmpty(AVLTree tree);
    Position Find(ElemType elem, AVLTree tree);
    Position FindMin(AVLTree tree);
    Position FindMax(AVLTree tree);
    AVLTree Insert(ElemType elem, AVLTree tree);
    AVLTree Delete(ElemType elem, AVLTree tree);
    ElemType Retrieve(Position pos);

#endif  /* AVL_TREE_H */