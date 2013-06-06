#include "MinHeap.h"
#include<iostream>
#include<cstdlib>
#define MAX	50

MinHeap::MinHeap(int a[], int n)
	: m_pArray(new int[MAX])  //���캯���жԳ�Ա�����ĳ�ʼ����д��
	, m_iLength(n)
{
	std::memcpy(m_pArray.get(), a, sizeof(int) * n); //ʹ���ڴ濽�����ֱ��
}


MinHeap::~MinHeap(void)
{//����ָ����Զ�����
}

void MinHeap::makeMinHeap()
{
	for(int i=m_iLength/2 - 1;i>=0; --i)
	{
		minHeapFixDown(i,m_iLength);
	}
}

//����д�ò���Ŷ
void MinHeap::minHeapAddNumber(int num)
{
	int i = m_iLength ;
	++m_iLength;
	m_pArray[i] = num;
	int j,temp;
	j = (i-1)/2;
	temp = m_pArray[i];
	while( j>=0 && i!=0 )
	{
		if( m_pArray[j]<temp )break;
		m_pArray[i] = m_pArray[j];
		i = j;
		j = (i-1)/2;
	}
	m_pArray[i] = temp;
}

void MinHeap::minHeapDelNumber()
{
	int temp = m_pArray[0];
	m_pArray[0] = m_pArray[m_iLength-1];
	m_pArray[m_iLength-1] = temp;
	m_iLength--;
	minHeapFixDown(0,m_iLength);
	
}

void MinHeap::minHeapFixDown(int i, int n)
{
	int j,temp;
	temp = m_pArray[i];
	j = 2*i + 1;
	while( j<m_iLength )
	{
		//if( temp <=( mem_iArray[j]-mem_iArray[j+1]>0?mem_iArray[j+1]:mem_iArray[j]) )break;//����˴������ȽϵĻ������������ȷ����j+1����j��Ϊ��ȷ��j��������ıȽϷ���
		if( j+1<m_iLength && m_pArray[j+1]<m_pArray[j] )
			j++;
		if( temp<=m_pArray[j] )
			break;
		m_pArray[i] = m_pArray[j];
		i = j;
		j = 2*i + 1;
	}
	m_pArray[i] = temp;
} 

void MinHeap::minHeapShow()
{
	std::cout<<std::endl;
	for( int i=0;i<m_iLength;++i)
	{
		std::cout<<m_pArray[i]<<" ";
	}
}