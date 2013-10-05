#include"head_info.h"
#include<iostream>

void showArray(int a[], int len)
{
	for( int i=0;i<len;++i )
	{
		std::cout<<a[i]<<" ";
	}
	std::cout<<std::endl;
}

void reverseString(char * a, int index, int len)
{
	if(index == len /2 )
		return ;
	swap(a[len -1 - index], a[index]);
	reverseString(a, index + 1, len);
}

void reverse_string( char * a, int len)
{
	reverseString(a, 0, len);
}