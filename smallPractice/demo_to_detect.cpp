

#include"head_info.h"

#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<bitset>
#define MAX 10


int main(){
	//�����㷨
	//int s[MAX],i;
	//srand((unsigned)time(0));
	//for ( i=0;i<MAX;i++ )
	//	s[i] = rand()%100;
	//showArray(s,MAX);
	//shell_sort(s,MAX);
	////quick_sort_norecursion(s,0,MAX-1);
	//showArray(s,MAX);

	//fibonacci�ݹ�ͷǵݹ�
	//std::cout<<"\n"<<fibonacci(20)<<" || "<<fibonacci_norecursion(20)<<std::endl;

	int s[] = {5,24,8,4,91,6,64,29,43,10};
	BinaryTree mytree(s,MAX);
	//mytree.preOrder(mytree.getRoot());
	//mytree.midOrder(mytree.getRoot());
	/*mytree.postOrder_unrecursive(mytree.getRoot());
	std::cout<<std::endl;
	mytree.breadthTraversal(mytree.getRoot());
	std::cout<<std::endl;
	std::cout<<"tree depth:"<<mytree.getDepth(mytree.getRoot())<<std::endl;*/
	std::cout<<mytree.findAndPrintPath(6)<<std::endl;

	/*int a[8] = {0};
	if( placeQueue(a,0) )
		showEightQueue(a);*/


	/*double a=2.6+3.7, c = 6.3;
	std::cout<<a<<" "<<c<<std::endl;
	if( a==c )
		std::cout<<a<<" "<<c<<" a=c"<<std::endl;
	float b = pow((float)2,(float)-128);
	int * p = (int *)(void*)&b;
	if( *p!=0 )
		std::cout<<"b is not 0"<<std::endl;
	std::bitset<32> mybits(*p);
	std::cout<<mybits<<std::endl;

	if( !(*p & 0x7fffffff) )
		std::cout<< "b is 0\n";
	else std::cout<< "b is not 0"<<std::endl;

	float d = 123.456789;
	std::cout<<d<<std::endl;*/
}

#if 0

//�����Լ�дһ�飡��
#include <map>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;

typedef std::pair<int, int>	Range_t;
typedef std::pair<Range_t, std::function<double (int)> > Range_Func_t;

typedef std::vector<Range_Func_t> Rang2Funcs_t;


int main()
{
	Rang2Funcs_t rfs;
	rfs.push_back(std::make_pair(std::make_pair(0, 300), [](int x){return 2 * x;}));
	rfs.push_back(std::make_pair(std::make_pair(301, 600), [](int x){return 10 * (x-300);}));
	rfs.push_back(std::make_pair(std::make_pair(601, 700), [](int x){return 15 * (x-600);}));

	int x = 620;
	double ans = 0;
	for(auto it= rfs.begin(); it != rfs.end(); it++)
	{
		Range_t r = it->first;
		if(x > r.second)
			ans += it->second(r.second);
		else if(x >= r.first && x <= r.second)
		{
			ans += it->second(x);
		}
	}
	std::cout<<"For x:"<<x<<", we get:"<<ans<<std::endl;

	return 0;
}


#include<iostream>
class Base{
protected:
	static int a;
	int c;
};

class b:public Base{
public:
	void foo(b b1,Base b2){
		b1.a = 1;
		b1.c = 2;
	}
};

void main(){
	char str[] = "abcdefg";
	int a[] = {1,2,3};
	std::cout<<sizeof(str)<<" "<<sizeof(a)<<std::endl;
}


void main()
{
	char s[] = "abcdef";
	reverse_string(s,6);
	std::cout<<s<<std::endl;
}

#endif