#include "BinaryTree.h"
#include<iostream>
#include<stack>
#include<queue>

BinaryTree::BinaryTree(int *a, int len)
	: m_pRoot(nullptr)
{
	for( int i=0;i<len;++i )
	{
		treeNode * p = new treeNode(a[i]);
		addNode(p);
	}
}

BinaryTree::~BinaryTree(void)
{
}

treeNode * BinaryTree::getRoot()
{
	return m_pRoot;
}

void	BinaryTree::preOrder(treeNode * root)
{
	if(root == nullptr)
		return ;
	std::cout<<root->data<<" ";
	if(root->leftChild)
		preOrder(root->leftChild);
	if(m_pRoot->rightChild)
		preOrder(root->rightChild);
}

void	BinaryTree::preOrder_unrecursive(treeNode * root)
{
	if( root==nullptr )
		return;
	std::stack<treeNode *> st;
	st.push(root);
	while( !st.empty() )
	{
		treeNode * cur = st.top();
		std::cout<<cur->data<<" ";
		st.pop();
		if(cur->rightChild)
			st.push(cur->rightChild);
		if(cur->leftChild)
			st.push(cur->leftChild);
	}
}

void	BinaryTree::midOrder(treeNode *root)
{
	if(root->leftChild)
		midOrder(root->leftChild);
	std::cout<<root->data<<" ";
	if(root->rightChild)
		midOrder(root->rightChild);
}

void	BinaryTree::midOrder_unrecursive(treeNode *root)
{
	std::stack<treeNode *> st;
	st.push(root);
	treeNode * cur = root;
	while(cur->leftChild)
	{
		st.push(cur->leftChild);
		cur = cur->leftChild;
	}
	while( !st.empty() )
	{
		cur = st.top();
		std::cout<<cur->data<<" ";
		st.pop();
		if( cur->rightChild )
		{
			st.push(cur->rightChild);
			cur = cur->rightChild;
			while(cur->leftChild)
			{
				st.push(cur->leftChild);
				cur = cur->leftChild;
			}
		}
	}
}

void	BinaryTree::midOrder_unrecursive2(treeNode *root)
{
	std::stack<treeNode *> st;
	treeNode * p = root;
	while( p || !st.empty() )
	{
		if( p )
		{
			st.push(p);
			p = p->leftChild;
		}
		else
		{
			p = st.top();
			std::cout<<p->data<<" ";
			st.pop();
			p = p->rightChild;
		}
	}
}

void	BinaryTree::postOrder(treeNode *root)
{
	if(root->leftChild)
		postOrder(root->leftChild);
	if(root->rightChild)
		postOrder(root->rightChild);
	std::cout<<root->data<<" ";
}

void	BinaryTree::postOrder_unrecursive(treeNode *root)
{
	std::stack<treeNode *> st;
	std::stack<int>		flagst;
	treeNode * cur = root;
	while( cur || !st.empty() )
	{
		if( cur )
		{
			st.push(cur);
			flagst.push(1);	
			cur = cur->leftChild;
		}
		else
		{
			cur = st.top();
			int flag = flagst.top();
			flagst.pop();
			if( flag==1 )
			{
				//从左子树出
				cur = cur->rightChild;
				flagst.push(2);
			}
			else
			{	//从右子树出
				std::cout<<cur->data<<" ";
				st.pop();
				cur = nullptr;
			}
		}
	}
}

void	BinaryTree::breadthTraversal(treeNode *root)
{
	std::queue<treeNode *>  que;
	treeNode * cur = root;
	que.push(cur);
	while( !que.empty() )
	{
		cur = que.front();
		que.pop();
		std::cout<<cur->data<<" ";
		if(cur->leftChild)
			que.push(cur->leftChild);
		if(cur->rightChild)
			que.push(cur->rightChild);
	}
}

int		BinaryTree::getDepth(treeNode *root)
{
	int ld =0, rd =0;
	if( root->leftChild )
		ld = getDepth(root->leftChild);
	if( root->rightChild )
		rd = getDepth(root->rightChild);
	if( ld>rd )
		return ld + 1;
	else 
		return rd + 1;
}

int		BinaryTree::findAndPrintPath(int n)
{
	std::stack<int> st;
	int pathNum = findPath(m_pRoot,n,st);
	if( pathNum == 0 )
		std::cout<<"NOT FOUND!"<<std::endl;
	return pathNum;
}

int		BinaryTree::findPath(treeNode * root,int n,std::stack<int> &st)
{
	 int count = 0;
	 st.push(root->data);
	 if( root->data==n )
	 {
		 printStack(st);
		 ++count;
	 }
	 if( root->leftChild )
		 count += findPath(root->leftChild,n,st);
	 if( root->rightChild )
		 count += findPath(root->rightChild,n,st);
	 st.pop();
	 return count;
}

void	BinaryTree::printStack(std::stack<int> &st)
{
	std::stack<int> stTmp;
	int tmp;
	while( !st.empty() )
	{
		tmp = st.top();
		stTmp.push(tmp);
		st.pop();
	}
	while( !stTmp.empty() )
	{
		tmp = stTmp.top();
		std::cout<<tmp<<" ";
		st.push(tmp);
		stTmp.pop();
	}
	std::cout<<std::endl;
}

void BinaryTree::addNode(treeNode * p)
{
	if( !m_pRoot )
	{
		m_pRoot = p;
		return;
	}
	treeNode * cur = m_pRoot;
	while( cur )
	{
		if( p->data < cur->data )
		{
			if( cur->leftChild )
				cur = cur->leftChild;
			else
			{
				cur->leftChild = p;
				return;
			}
		}
		else
		{
			if( cur->rightChild )
				cur = cur->rightChild;
			else
			{
				cur->rightChild = p;
				return;
			}
		}
	}
}
