/**************************************************************************************************
 * File name	: invert_binary_tree.cpp
 * Description	: Implement an algorithm to invert a binary tree.
 * Creator		: Frederique Hsu
 * Creation date: Sat.	18 April 2020
 * Copyright(C)	2020	All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>

using namespace std;

typedef struct TreeNode
{
public:
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
public:
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}
TreeNode;

TreeNode* invertBinaryTree(TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	TreeNode* tmpNode = root->left;
	root->left = invertBinaryTree(root->right);
	root->right = invertBinaryTree(tmpNode);
	return root;
}


int main(int argc, char* argv[])
{
	return 0;
}

