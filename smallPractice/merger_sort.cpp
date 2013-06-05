/* merger sort algorithms imply
	zhou xiaoping 2013-06-05 */

#include<stdlib.h>

void mergeArray(int a[],int first,int middle,int last,int temp[])
{
	//combine two ordered arrays to the array c[]
	int i=first,j=middle+1,k=0;
	while(i<=middle && j<=last)
	{
		if( a[i]<=a[j] )
			temp[k++] = a[i++];
		else 
			temp[k++] = a[j++];
			//count += middle-i+1;//求数列中的逆序对个数
	}
	while( j<=last )
			temp[k++] = a[j++];
	while( i<=middle )
			temp[k++] = a[i++];
	for( i=0;i<k;++i )
		a[first+i] = temp[i];
}

void mergerSort( int a[], int first,int last, int temp[] )
{
	if( first<last )
	{
		int mid = (first+last)/2;
		mergerSort(a,first,mid,temp);
		mergerSort(a,mid+1,last,temp);
		mergeArray(a,first,mid,last,temp);
	}
}

bool merger_sort( int a[], int n )//n为数组元素个数
{
	int *p = new int[n];
	if( p==NULL )
		return false;
	mergerSort(a,0,n-1,p);
	delete[] p;
	return true;
}
