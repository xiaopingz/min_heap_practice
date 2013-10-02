/* quick sort algorithms imply
	zhou xiaoping 2013-06-05 */
#include"head_info.h"
#include<stack>

int partition(int a[],int l,int r)
{
	int x = a[l], i=l, j=r;
	while(i<j)
	{
		while( i<j && a[j]>=x )
			--j;
		if( i<j )
			a[i++] = a[j];
		while( i<j && a[i]<x )
			++i;
		if( i<j )
			a[j--] = a[i];
	}
	a[i] = x;	//i=j
	return i;
}

void quick_sort(int a[], int l, int r)
{
	if( l<r )
	{
		//可以用partition函数替换
		/*int x = a[l];
		int i = l, j = r;
		while ( i<j )
		{
			while( i<j && a[j]>=x )
				--j;
			if( i<j )
				a[i++] = a[j];
			while( i<j && a[i]<x )
				++i;
			if( i<j )
				a[j--] = a[i];
		}
		a[i] = x;
		quick_sort(a,l,i-1);
		quick_sort(a,i+1,r);*/

		int mid = partition(a,l,r);
		quick_sort(a,l,mid-1);
		quick_sort(a,mid+1,r);
	}
}

//非递归
void quick_sort_norecursion(int a[], int l, int r)
{
	std::stack<int>	st;
	st.push(l);
	st.push(r);
	while( !st.empty() )
	{
		int j = st.top();
		st.pop();
		int i = st.top();
		st.pop();
		int mid = partition(a,i,j);
		if(i<mid-1)
		{
			st.push(i);
			st.push(mid-1);
		}
		if(mid+1<j)
		{
			st.push(mid+1);
			st.push(j);
		}
	}
}
