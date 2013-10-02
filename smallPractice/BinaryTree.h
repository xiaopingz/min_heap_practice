#pragma once

struct treeNode
{
	int data;
	treeNode * leftChild;
	treeNode * rightChild;
	treeNode(int a)
		: data(a)
		, leftChild(nullptr)
		, rightChild(nullptr){}
};

class BinaryTree
{
public:
	BinaryTree(int *a, int len);
	~BinaryTree(void);
	treeNode * getRoot();
	void	preOrder(treeNode * root);
	void	preOrder_unrecursive(treeNode * root);
	void	midOrder(treeNode *root);
	void	midOrder_unrecursive(treeNode *root);
	void	midOrder_unrecursive2(treeNode * root);
	void	postOrder(treeNode *root);
	void	postOrder_unrecursive(treeNode *root);

protected:
	void		addNode(treeNode *pNode);
private:
	treeNode	* m_pRoot;
};

