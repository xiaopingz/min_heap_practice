#pragma once 
#include"head_info.h"
/* shell sort algorithms imply
	zhou xiaoping 2013-10-04 */

void shell_sort(int a[], int len)
{
	int i,j,k,d,m;
	for( d=len/2;d>0;d/=2 )
	{
		for( i=0;i<d;++i )
		{
			for( j=i+d;j<len;j+=d )
				if(a[j]<a[j-d])
				{
					int temp = a[j];
					for( m=j-d;m>=0 && a[m]>temp;m-=d )
						a[m+d] = a[m];
					a[m+d] = temp;
				}
		}
	}
}