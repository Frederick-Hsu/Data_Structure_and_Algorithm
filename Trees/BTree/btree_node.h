/*!
 *  \file       btree_node.h
 *  \brief
 *
 */


#pragma once

struct BTreeNode
{
    int          *data;
    BTreeNode   **child_ptr;
    bool          leaf;
    int           n;
};


BTreeNode* init();
void traversal(BTreeNode* p);
void destroy(BTreeNode* p);
