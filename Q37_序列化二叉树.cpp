#include<iostream>
#include<string>
#include"BinaryTree.h"
using namespace std;

//序列化二叉树
void Serialize(const BinaryTreeNode* pRoot, ostream& stream)
{
	if (pRoot == NULL)
	{
		stream << "$,";
		return;
	}
	stream << pRoot->value << ",";//前序遍历输入 根左右
	Serialize(pRoot->pleft, stream);
	Serialize(pRoot->pright, stream);
}

bool ReadStream(istream& stream, int *n);
//反序列二叉树
void Deserialize(BinaryTreeNode**pRoot, istream& stream)
{
	int number;
	if (ReadStream(stream, &number))
	{
		*pRoot = new BinaryTreeNode();
		(*pRoot)->value = number;
		(*pRoot)->pleft = NULL;
		(*pRoot)->pright = NULL;

		Deserialize(&((*pRoot)->pleft), stream);
		Deserialize(&((*pRoot)->pright), stream);
	}
}

bool ReadStream(istream& stream, int *number)
{
	if (stream.eof())
		return false;

	char ch;
	stream >> ch;
	int i = 0;
	char buffer[32];
	buffer[0] = '\0';
	while (!stream.eof() && ch != ',')
	{
		buffer[i++] = ch;
		stream >> ch;
	}

	bool isNumeric = false;
	if (i > 0 && buffer[0] != '$')
	{	
		*number = atoi(buffer);
		isNumeric = true;
	}
	return isNumeric;
}
bool isSameTree(const BinaryTreeNode* pRoot1, const BinaryTreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;

	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	if (pRoot1->value != pRoot2->value)
		return false;

	return isSameTree(pRoot1->pleft, pRoot2->pleft) &&
		isSameTree(pRoot1->pright, pRoot2->pright);
}
void PrintTreeOfstream(const BinaryTreeNode* pRoot, ofstream& fout)//前序遍历
{
	fout << pRoot->value << ",";
	if (pRoot != NULL)
	{
		if (pRoot->pleft != NULL)
			PrintTreeOfstream(pRoot->pleft, fout);
		if (pRoot->pright != NULL)
			PrintTreeOfstream(pRoot->pright, fout);
	}
}
void Test(const char* testName, const BinaryTreeNode* pRoot)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	PrintTree(pRoot);
	cout << endl;

	char* fileName = "test.txt";
	ofstream fileOut;
	fileOut.open(fileName);

	Serialize(pRoot, fileOut);
	fileOut.close();

	// print the serialized file
	ifstream fileIn1;
	char ch;
	fileIn1.open(fileName);
	while (!fileIn1.eof())
	{
		fileIn1 >> ch;
		cout << ch;
	}
	fileIn1.close();
	cout << endl;

	ifstream fileIn2;
	fileIn2.open(fileName);
	BinaryTreeNode* pNewRoot = nullptr;
	Deserialize(&pNewRoot, fileIn2);
	fileIn2.close();

	PrintTree(pNewRoot);
	ofstream fout("Detest.txt");
	PrintTreeOfstream(pNewRoot, fout);
	cout << endl;

	if (isSameTree(pRoot, pNewRoot))
		printf("The deserialized tree is same as the oritinal tree.\n\n");
	else
		printf("The deserialized tree is NOT same as the oritinal tree.\n\n");

	DestroyTree(pNewRoot);
}

//            8
//        6      10
//       5 7    9  11
void Test1()
{
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	Test("Test1", pNode8);

	DestroyTree(pNode8);
}

int main()
{
	Test1();
	return 0;
}