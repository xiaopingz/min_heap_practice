#pragma once
#include <memory>

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
	//注意命名习惯
	std::unique_ptr<int[]> m_pArray;  //使用智能指针，其实这里用vector会更好
	int		m_iLength;
};

