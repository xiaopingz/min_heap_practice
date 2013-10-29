#pragma once
#include<stack>

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
	int		findAndPrintPath(int n);	//查找从根节点到指定节点（n）的所有路径，返回路径数。

protected:
	void		addNode(treeNode *pNode);
	int			findPath(treeNode * root,int n,std::stack<int> &st);
	void		printStack(std::stack<int> &st);
private:
	treeNode	* m_pRoot;
};

