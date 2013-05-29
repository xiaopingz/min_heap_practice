#include "MinHeap.h"
#include<iostream>


MinHeap::MinHeap(int a[], int n)
{
	mem_iLength = n;
	mem_iArray = new int[n];
	for(int i=0; i<n; i++)
	{
		mem_iArray[i] = a[i];
	}
	//makeMinHeap();
}


MinHeap::~MinHeap(void)
{
	delete[] mem_iArray;
}

void MinHeap::makeMinHeap()
{
	for(int i=mem_iLength/2 - 1;i>=0; --i)
	{
		minHeapFixDown(i,mem_iLength);
	}
}

void MinHeap::minHeapAddNumber(int num)
{
	int i = mem_iLength ;
	++mem_iLength;
	mem_iArray[i] = num;
	int j,temp;
	j = (i-1)/2;
	temp = mem_iArray[i];
	while( j>=0 && i!=0 )
	{
		if( mem_iArray[j]<temp )break;
		mem_iArray[i] = mem_iArray[j];
		i = j;
		j = (i-1)/2;
	}
	mem_iArray[i] = temp;
}

void MinHeap::minHeapDelNumber()
{
	int temp = mem_iArray[0];
	mem_iArray[0] = mem_iArray[mem_iLength-1];
	mem_iArray[mem_iLength-1] = temp;
	mem_iLength--;
	minHeapFixDown(0,mem_iLength);
	
}

void MinHeap::minHeapFixDown(int i, int n)
{
	int j,temp;
	temp = mem_iArray[i];
	j = 2*i + 1;
	while( j<mem_iLength )
	{
		//if( temp <=( mem_iArray[j]-mem_iArray[j+1]>0?mem_iArray[j+1]:mem_iArray[j]) )break;//如果此处这样比较的话，后面就难以确定是j+1大还是j大，为了确定j，用下面的比较方法
		if( j+1<mem_iLength && mem_iArray[j+1]<mem_iArray[j] )
			j++;
		if( temp<=mem_iArray[j] )
			break;
		mem_iArray[i] = mem_iArray[j];
		i = j;
		j = 2*i + 1;
	}
	mem_iArray[i] = temp;
} 

void MinHeap::minHeapShow()
{
	std::cout<<std::endl;
	for( int i=0;i<mem_iLength;++i)
	{
		std::cout<<mem_iArray[i]<<" ";
	}
}