/* bubble sort algorithms impliment,ascending order
	zhou xiaoping 2013-06-06	*/

#include"head_info.h"

void bubble_sort1(int a[],int n)
{
	int i,j,flag=1;//flag :0,no data has been changed when one bubble
	for( i=0;i<n;++i )
	{
		if( flag == 0 )
			return;
		flag = 0;
		for( j=1;j<n-i;++j )	//	j从1开始，下面用j-1，而不是j和j+1比较；否则就会出现访问数组越界的情况。
		{
			if( a[j-1]>a[j] )
			{
				swap(a[j-1],a[j]);
				flag = 1;
			}
			//else
				//flag = 0;//这里是不对的，因为如果只是循环的最后一次把flag置为0了，结果就错了。
		}
	}
}

//优化：如果一个数组中只有前几个数无序，后面的都是有序，那么后面的在一趟排序中就能检查出来没有做调整。因此在后面的冒泡中就不需再比较。
void bubble_sort2(int a[],int n)
{
	int i,j,k;//k为内存循环的中止条件，即比较到的位置
	int flag = n;
	while( flag>0 )
	{
		k = flag;
		flag = 0;//同上，在一次冒泡排序前将其置零，一旦有改动，则排序需要继续进行下去
		for( j=1;j<k;++j )
		{
			if( a[j-1]>a[j] )
			{
				swap(a[j-1],a[j]);
				flag = j;
			}
		}
	}
}