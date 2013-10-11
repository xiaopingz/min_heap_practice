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
	void	breadthTraversal(treeNode *root);	//不用遍历的方法，应该不需要参数吧？
	int		getDepth(treeNode *root);

protected:
	void		addNode(treeNode *pNode);
private:
	treeNode	* m_pRoot;
};

