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
	//ע������ϰ��
	std::unique_ptr<int[]> m_pArray;  //ʹ������ָ�룬��ʵ������vector�����
	int		m_iLength;
};

