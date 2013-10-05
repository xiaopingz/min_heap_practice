#pragma once
#include"head_info.h"
/* direct insert sort algorithms imply
	zhou xiaoping 2013-10-04 */

void direct_insert_sort(int a[], int len)
{
	int i,j,k;
	for( i=1;i<len;++i )
	{
		for( j=i-1;j>=0;--j )
		{
			if(a[j]<=a[i])
				break;
		}
		int temp = a[i];
		for( k=i-1;k>j;--k )
		{
			a[k+1] = a[k];
		}
		a[k+1] = temp; 
	}
}

void direct_insert_sort2(int a[],int len )
{
	int i,j;
	for( i=1;i<len;++i )
		if(a[i]<a[i-1])
		{
			int temp = a[i];
			for( j=i-1;j>=0 && a[j]>temp;--j )
			{
				a[j+1] = a[j];
			}
			a[j+1] = temp;
		}
}