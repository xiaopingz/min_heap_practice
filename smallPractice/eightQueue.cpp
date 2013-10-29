#include<iostream>
#include"head_info.h"

bool isSafe( int row, int col, int safeArray[] )
{
	for( int tmpCol = 0;tmpCol<col; ++tmpCol )
	{
		int tmpRow = safeArray[tmpCol];
		if( tmpRow == row )
			return false;
		if( tmpCol + tmpRow == col + row || tmpCol - tmpRow == col - row )
			return false;
	}
	return true;
}

bool placeQueue( int safeArray[], int col )
{
	int row = 0;
	bool safePlace = false;
	if( col==8 )
		safePlace = true;
	else
	{
		while( row<8 && !safePlace )
		{
			if( isSafe( row,col,safeArray ) )
			{
				safeArray[col] = row;
				safePlace = placeQueue(safeArray,col+1);
				if( !safePlace )
					++row;
			}
			else
				++row;
		}
	}
	return safePlace;
}

void showEightQueue( int a[] )
{
	int i,j ;
	for (  i=0;i<8;++i )
	{
		for( j=0;j<=a[i]-1;++j )
			std::cout<<"- ";
		std::cout<<"# ";
		for( ++j;j<8;++j )
			std::cout<<"- ";
		std::cout<<std::endl;
	}
}