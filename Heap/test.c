#include "Heap.h"

int main()
{
	int a[] = { 15, 18, 19, 25, 28, 34, 65, 49, 27, 37 };
	//int a[] = { 65, 100, 70, 32, 50, 60 };
	Heap heap;
	HeapInit(&heap,&a,(sizeof(a)/sizeof(a[0])));
	/*for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		HeapPush(&heap, a[i]);
	}*/
	HeapPush(&heap,13);
	HeapPrint(&heap);
	HeapDestory(&heap);

	//HeapPush(&heap, 10);
	//HeapPrint(&heap);

	//HeapPop(&heap);
	//HeapPrint(&heap);

	//HeapPop(&heap);
	//HeapPrint(&heap);

	/*while (!HeapEmpty(&heap))
	{
		printf("%d ", HeapTop(&heap));
		HeapPop(&heap);
	}*/

	return 0;
}