#include "Heap.h"


void HeapSort(int* a, int n)
{
	 //建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//前提：左右子树的都是小堆
void AdjustDown(HPDataType* a, int n, int root)
{
	//找出左右孩子中小的那个
	int parent = root;
	int child = parent * 2 + 1;//左孩子
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}

void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType*) * n);
	memcpy(php->_a, a, sizeof(HPDataType*) * n);
	php->_size = n;
	php->_capacity = n;
	//构建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(php->_a, php->_size, i);
	}
}

void HeapDestory(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_capacity = php->_size = 0;

}

void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}
HPDataType HeapTop(Heap* php)
{

	assert(php);
	assert(php->_size > 0);
	return php->_a[0];
}
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	// 扩容
	if (php->_size == php->_capacity)
	{
		int newCapacity = php->_capacity == 0 ? 4 : php->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}

		php->_a = tmp;
		php->_capacity = newCapacity;
	}

	php->_a[php->_size] = x;
	php->_size++;

	AdjustUp(php->_a, php->_size - 1);
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	//while (parent >= 0)
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPrint(Heap* php)
{
	for (int i = 0; i < php->_size; ++i)
	{
		printf("%d ", php->_a[i]);
	}
	printf("\n");
}