#pragma once
#include"BinaryTree.h"

//void swap(int &a, int &b);

void bubble_sort1(int a[],int n);

void bubble_sort2(int a[],int n);

void quick_sort(int a[], int l, int r);

void quick_sort_norecursion(int a[], int l, int r);

int fibonacci(int n);

int fibonacci_norecursion(int n);

int fibonacci_no2(int n);

bool merger_sort( int a[], int n );

void showArray(int a[], int len);

void reverseString(char * a, int len, int s);

template<typename T>
void swap(T &a,T &b)
{
	T t = a;
	a = b;
	b = t;
};

void reverse_string( char * a, int len);

void direct_insert_sort(int a[], int len);
void direct_insert_sort2(int a[], int len);

void shell_sort(int a[], int len);