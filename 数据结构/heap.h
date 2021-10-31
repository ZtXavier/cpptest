/*
* 抽象数据类型——最大堆
*/
#ifndef _MAX_HEAP_HEAD_
#define _MAX_HEAP_HEAD_
#include <iostream>
using namespace std;

const int DefaultSize = 10;

class max_heap {
	int* heap;
	int currentSize;
	int maxSize;
	void siftDown(const int start,const int end);
public:
	max_heap(int sz = DefaultSize);
	max_heap(int* h, int sz);
	~max_heap();
	void heap_sort();
	void display() const;
};

//成员函数定义
max_heap::max_heap(int sz) {
	heap = new int[sz];
	if (!heap) {
		cerr << "内存分配失败" << endl;
		exit(EXIT_FAILURE);
	}
	currentSize = 0;
	maxSize = (sz <= DefaultSize) ? DefaultSize : sz;
}

max_heap::max_heap(int* h, int sz)
{
	heap = new int[sz];
	if (!heap) {
		cerr << "内存分配失败" << endl;
		exit(EXIT_FAILURE);
	}
	//初始化成员变量
	currentSize = sz;
	maxSize = (sz <= DefaultSize) ? DefaultSize : sz;
	for (int cnt = 0; cnt < sz; ++cnt) {
		heap[cnt] = h[cnt];
	}
	//调整为最大堆
	int currentPosition = (currentSize - 2) / 2;	//最后一个分支节点——调整起点
	while (currentPosition >= 0) {
		siftDown(currentPosition--, currentSize - 1);
	}
}

max_heap::~max_heap() {
	delete[] heap;
}

//函数功能，自上向下比较将一个集合局部调整为最大堆
//函数参数，调整起始节点，调整最终节点
void max_heap::siftDown(const int start,const int end)
{
	int i = start;
	int j = 2 * i + 1;	//起始节点的左子树
	int temp = heap[i];
	while (j <= end)
    {	//确定temp最终的位置
		if (j < end && heap[j] < heap[j + 1])
        {	//定位到左右子树的较大者
			++j;
		}
		if (heap[j] <= temp) {	//与当前根值比较
			break;
		}
		else
        {
			heap[i] = heap[j];
			i = j;
			j = j * 2 + 1;
		}
	}
	heap[i] = temp;
}

//函数功能，堆排序算法对数列递增排序
//函数参数，NULL
void max_heap::heap_sort()
{
	for (int cnt = currentSize - 1; cnt > 0; --cnt)
    {
		swap(heap[0], heap[cnt]);
		siftDown(0, cnt - 1);	//重新调整为最大堆
	}
}

void max_heap::display() const
{
	for (int cnt = 0; cnt < currentSize; ++cnt)
    {
		cout << heap[cnt] << " ";
	}
}


#endif

