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
		for( j=1;j<n-i;++j )	//	j��1��ʼ��������j-1��������j��j+1�Ƚϣ�����ͻ���ַ�������Խ��������
		{
			if( a[j-1]>a[j] )
			{
				swap(a[j-1],a[j]);
				flag = 1;
			}
			//else
				//flag = 0;//�����ǲ��Եģ���Ϊ���ֻ��ѭ�������һ�ΰ�flag��Ϊ0�ˣ�����ʹ��ˡ�
		}
	}
}

//�Ż������һ��������ֻ��ǰ���������򣬺���Ķ���������ô�������һ�������о��ܼ�����û��������������ں����ð���оͲ����ٱȽϡ�
void bubble_sort2(int a[],int n)
{
	int i,j,k;//kΪ�ڴ�ѭ������ֹ���������Ƚϵ���λ��
	int flag = n;
	while( flag>0 )
	{
		k = flag;
		flag = 0;//ͬ�ϣ���һ��ð������ǰ�������㣬һ���иĶ�����������Ҫ����������ȥ
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