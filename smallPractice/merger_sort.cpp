/* merger sort algorithms imply
	zhou xiaoping 2013-06-05 */

#include<stdlib.h>
#include<stack>   //2013-10-03
#include"head_info.h"

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

void mergeSort( int a[], int first, int last , int temp[] )
{
	// unrecursive solution
	std::stack<int>	st, stx;
	st.push(first);
	st.push(last);
	while( !st.empty() )
	{
		int l = st.top();
		st.pop();
		stx.push(l);
		int f = st.top();
		st.pop();
		stx.push(f);
		int mid = (l+f)/2;
		if( f<mid )
		{
			st.push(f);
			st.push(mid);
		}
		if( mid+1<l )
		{
			st.push(mid+1);
			st.push(l);
		}
	}
	while( !stx.empty() )
	{
		int f = stx.top();
		stx.pop();
		int l = stx.top();
		stx.pop();
		mergeArray(a,f,(f+l)/2,l,temp);
	}
}

bool merger_sort( int a[], int n )//n为数组元素个数
{
	int *p = new int[n];
	if( p==NULL )
		return false;
	mergeSort(a,0,n-1,p);
	delete[] p;
	return true;
}
