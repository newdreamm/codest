#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 10
typedef int SLDataType;



typedef struct SeqList
{
	SLDataType* a;
	int size;//有效数据的个数
	int capacity;//容量
}SL, SeqList;

//打印
void SeqListPrint(SL* ps);
//初始化
void SeqListInit(SL* ps);
//尾插尾删
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
//头插头删
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
//任意位置插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);
//查找
int SeqListFind(SL* ps, SLDataType x);
//扩容函数
void SeqListCheckCapacity(SL* ps);
//销毁
void SeqListDestory(SL* ps);