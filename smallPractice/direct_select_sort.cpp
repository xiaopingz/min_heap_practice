/* direct selected sort algorithm imply
	zhou xiaoping 2013-0605 */

#include"head_info.h"

void select_sort( int a[], int n ) 
{
	for( int i=0;i<n;++i )
	{
		int nMinIndex = i;	//������������СԪ�ص�λ��
		for( int j=i+1;j<n;++j )
		{	
			if( a[j]<a[nMinIndex] )
				nMinIndex = j;
		}
		swap(a[nMinIndex],a[i]);//������뵽������β��
	}
}

