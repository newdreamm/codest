#include "Sort.h"
#include "Stack.h"






//void TestInsertSort()
//{
//	int a[] = { 34,56,25,65,86,99,72,66 };
//	InsertSort(a, sizeof(a) / sizeof(int));
//}
//
//void TestShellSort()
//{
//	//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int a[] = { 34, 56, 25, 65, 86, 99, 72, 66 };
//	ShellSort(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void TestSelectSort()
//{
//	int a[] = { 100, 56, 25, 65, 86, 99, 72, 66 };
//	SelectSort(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}

void TestMergeSort()
{
	int a[] = { 100, 56, 25, 65, 86, 99, 72, 66 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//void TestQuickSort()
//{
//	int a[] = { 100, 56, 25, 65, 86, 99, 72, 66 };
//	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
//	PrintArray(a, sizeof(a) / sizeof(int));
//}

//void TestOP()
//{
//	srand(time(0));
//	const int N = 1000000;
//	int* a1[] = (int*)malloc(sizeof(int) * N);
//
//	int* a2[] = (int*)malloc(sizeof(int) * N);
//	int* a3[] = (int*)malloc(sizeof(int) * N);
//	int* a4[] = (int*)malloc(sizeof(int) * N);
//	int* a5[] = (int*)malloc(sizeof(int) * N);
//	int* a6[] = (int*)malloc(sizeof(int) * N);
//	int* a7[] = (int*)malloc(sizeof(int) * N);
//
//	for (int i = 0; i < N; ++i)
//	{
//		a1[i] = rand();
//		a2[i] = a1[i];
//		a3[i] = a1[i];
//		a4[i] = a1[i];
//		a5[i] = a1[i];
//		a6[i] = a1[i];
//		a7[i] = a1[i];
//	}
//
//	int begin1 = clock();
//	//InsertSort(a1, N);
//	int end1 = clock();
//
//	int begin2 = clock();
//	//ShellSort(a2, N);
//	int end2 = clock();
//
//	int begin3 = clock();
//	//SelectSort(a3, N);
//	int end3 = clock();
//
//	int begin4 = clock();
//	HeapSort(a4, N);
//	int end4 = clock();
//
//	int begin5 = clock();
//	//QuickSort(a5, 0, N - 1);
//	int end5 = clock();
//
//	int begin6 = clock();
//	//MergeSort(a6, N);
//	int end6 = clock();
//
//	int begin7 = clock();
//	BubbleSort(a7, N);
//	int end7 = clock();
//
//	printf("InsertSort:%d\n", end1 - begin1);
//	printf("ShellSort:%d\n", end2 - begin2);
//	printf("SelectSort:%d\n", end3 - begin3);
//	printf("HeapSort:%d\n", end4 - begin4);
//	printf("BubbleSort:%d\n", end7 - begin7);
//	//printf("QuickSort:%d\n", end5 - begin5);
//	//printf("MergeSort:%d\n", end6 - begin6);
//
//
//	free(a1);
//	free(a2);
//	free(a3);
//	free(a4);
//	free(a5);
//	free(a6);
//	free(a7);
//}


int main()
{
	//TestInsertSort();
	//TestSelectSort();
	TestMergeSort();
	// TestOP();
	return 0;
}