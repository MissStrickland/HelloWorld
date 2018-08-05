#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include<fstream>
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* pleft;
	BinaryTreeNode* pright;
};

BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pleft, BinaryTreeNode* pright);
void PrintTreeNode(const BinaryTreeNode* pNode);
void PrintTree(const BinaryTreeNode* pRoot);
void DestroyTree(BinaryTreeNode*pRoot);

#endif//!BINARYTREENODE_H