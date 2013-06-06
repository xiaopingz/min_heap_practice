#if 1
#include"head_info.h"
#include<time.h>
#include<stdlib.h>
#include<iostream>
#define MAX 24


int main(){
	int s[MAX],i;
	srand((unsigned)time(0));
	for ( i=0;i<MAX;i++ )
		s[i] = rand()%100;
	for( i=0;i<MAX;i++ )
		std::cout<<s[i]<<" ";
	bubble_sort1( s,MAX );
	std::cout<<std::endl;
	for( i=0;i<MAX;i++ )
		std::cout<<s[i]<<" ";

}
#endif