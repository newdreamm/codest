#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



void InsertSort(int* a, int n);
void PrintArray(int* a, int n);
void ShellSort(int* a, int n);
void HeapSort(int* a, int n);
void SelectSort(int* a, int n);
void BubbleSort(int* a, int n);
void QuickSort(int* a, int begin, int end);
void Swap(int* p1, int* p2);
void QuickSortNonR(int* a, int begin, int end);
void QuickSort(int* a, int begin, int end);
int PartSort3(int* a, int left, int right);
int PartSort2(int* a, int left, int right);
int PartSort1(int* a, int left, int right);
int GetMidIndex(int* a, int left, int right);
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
void _MergeSort(int* a, int begin, int end, int* tmp);





