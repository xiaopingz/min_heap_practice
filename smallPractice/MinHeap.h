#pragma once
class MinHeap
{
public:
	MinHeap(int a[], int n);
	~MinHeap(void);

public:
	void makeMinHeap();
	void minHeapFixDown(int i, int n);
	void minHeapAddNumber(int num);
	void minHeapDelNumber();
	void minHeapShow();

protected:
	int *	mem_iArray;
	int		mem_iLength;
};

