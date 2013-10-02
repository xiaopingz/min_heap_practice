#include"head_info.h"
#include<stack>

int fibonacci(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci_norecursion(int n)
{
	std::stack<int> st;
	st.push(n);
	int sum=0;
	while( !st.empty() )
	{
		int cur = st.top();
		st.pop();
		if( cur==0 || cur==1 )
			++sum;
		else
		{
			st.push( cur-1 );
			st.push( cur-2 );
		}
	}
	return sum;
}

int fibonacci_no2(int n)
{
	int count = 0, pre=0,cur=1;	
	while( count != n && n!=1 )
	{
		int res = pre + cur;
		pre = cur;
		cur = res;
		++count;
	}
	return cur;
}