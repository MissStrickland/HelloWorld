#include"BinaryTree.h"
#include<iostream>
using namespace std;

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode *pNode= new BinaryTreeNode();
	pNode->value = value;
	pNode->pleft = NULL;
	pNode->pright = NULL;
	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pleft, BinaryTreeNode* pright)
{
	if (pParent != NULL)
	{
		pParent->pleft = pleft;
		pParent->pright = pright;
	}
}

void PrintTreeNode(const BinaryTreeNode* pNode)
{
	if (pNode != NULL)
	{
		cout << pNode->value << endl;
		if (pNode->pleft != NULL)
			cout << pNode->pleft->value;

		if (pNode->pright != NULL)
			cout << pNode->pleft->value << endl;
	}
}

void PrintTree2(const BinaryTreeNode* pRoot)//前序遍历
{
	PrintTreeNode(pRoot);
	if (pRoot != NULL)
	{
		if (pRoot->pleft != NULL)
			PrintTree(pRoot->pleft);
		if (pRoot->pright != NULL)
			PrintTree(pRoot->pright);
	}
}
void PrintTree(const BinaryTreeNode* pRoot)//前序遍历
{
	cout << pRoot->value << ",";
	if (pRoot != NULL)
	{
		if (pRoot->pleft != NULL)
			PrintTree(pRoot->pleft);
		if (pRoot->pright != NULL)
			PrintTree(pRoot->pright);
	}
}



void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		BinaryTreeNode* pleft = pRoot->pleft;
		BinaryTreeNode* pright = pRoot->pright;

		delete pRoot;
		pRoot = NULL;

		DestroyTree(pleft);
		DestroyTree(pright);
	}
}