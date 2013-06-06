#include"head_info.h"


void swap(int &a, int &b)
{
	if(a!=b)
	{
		a^=b;
		b^=a;
		a^=b;
	}
}