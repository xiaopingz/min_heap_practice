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
	void	breadthTraversal(treeNode *root);	//���ñ����ķ�����Ӧ�ò���Ҫ�����ɣ�
	int		getDepth(treeNode *root);
	int		findAndPrintPath(int n);	//���ҴӸ��ڵ㵽ָ���ڵ㣨n��������·��������·������

protected:
	void		addNode(treeNode *pNode);
	int			findPath(treeNode * root,int n,std::stack<int> &st);
	void		printStack(std::stack<int> &st);
private:
	treeNode	* m_pRoot;
};

