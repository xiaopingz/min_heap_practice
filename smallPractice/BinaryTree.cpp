#include "BinaryTree.h"
#include<iostream>
#include<stack>

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
			if( flag==1 )
			{
				cur = cur->rightChild;
				flagst.pop();
				flagst.push(2);
			}
			else
			{
				std::cout<<cur->data<<" ";
				st.pop();
				flagst.pop();
				cur = nullptr;
			}
		}
	}
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
