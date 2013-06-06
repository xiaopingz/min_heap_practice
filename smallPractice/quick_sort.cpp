/* quick sort algorithms impl8y
	zhou xiaoping 2013-06-05 */


void quick_sort(int a[], int l, int r)
{
	
	if( l<r )
	{
		int x = a[l];
		int i = l, j = r;
		while( i<j )
		{
			while( i<j && a[j]>=x )
				j--;
			if( i<j )
				a[i++] = a[j];
			while( i<j && a[i]<x )
				i++;
			if( i<j )
				a[j--] = a[i];
		}
		a[i] = x;
		quick_sort(a, l, i-1);
		quick_sort(a, i+1, r);
	}
}

